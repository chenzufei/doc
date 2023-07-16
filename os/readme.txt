
操作系统实战45讲：HelloOS运行笔记

《操作系统设计与实现》（上册）（第3版）


Linus不是凭空创造出的Linux。在90年代早期学过操作系统课程的人应该都知道，其实之前有个专门用于教育的开源Unix版本叫MINIX。
Linus学习了MINIX后，发现MINIX的版权协议只允许应用在教育上，于是基于MINIX开发了Linux。

而MINIX的开发则是因为UNIX的版权属于AT&T，非常昂贵，所以Andrew S. Tanenbaum 在1987年开发了MINIX用于计算机教学

Unix版权属于AT&T则是因为 Ken Thompson, Dennis Ritchie 两位大神开发Unix时，是在AT&T所属的贝尔实验室工作

Unix也不是凭空出来的，Thompson和Ritchie两位大神参与过 Multics 的开发。
尽管 Multics失败了，但让他们了解了分时操作系统的核心理念及相关的实现细节，为Unix的开发奠定了很好的基础。

GNU计划 以GNU Hurd为整个GNU 操作系统的核心，然而，GNU 操作系统的核心 Hurd 直至1991年仍不可使用。
而在1991年，当年的计算机业余爱好者Linus Torvalds（如今为世界顶级计算机科学家），通过对教学用的Minix操作系统的研究扩展，独立发表了开源的 Linux内核。




图中可以看出，操作系统完整的程序执行过程：Loader.asm--->Kernel.asm--->Kernel.c。
那我们现在就只需要把Kernel.c在内存上顺序的布置在Kernel.asm的后面即可。
那怎么才能把Kernel.c贴在Kernel.asm的屁股后面呢，方法就是把Kernel.asm编译成的二进制文件（Kernela.bin）
和Kernel.c编译成的二进制文件(Kernelc.bin)连接在一起嘛:

将程序的最后一句指令"jmp $"修改为: jmp over+0x24

0/1生汇编，汇编生C，C生万物，乃编程之本


市面上的编译器连接器都是只支持对应的操作系统的。就像win下的编译器，只会生成pe格式的文件，
linux下gcc会生成elf格式的文件。这些都不是纯的无格式二进制文件，他们有对应的文件头，来让pe加载器或者elf加载器来加载。
而且文件的链接也是需要头的。但凡这样的文件都是不能裸机运行，需要跑在对应的操作系统上。
你也可以设计一套你自己操作系统的可执行文件格式，也就是自己设计个文件头以便于程序加载，这样的话你就需要和30天的作者一样自己写一个编译器和链接器。
如果不想自己写，而且想要自然地用c，可以使用市面上的编译器，比如gcc。这样的话，你的操作系统就必须有elf或者pe加载器。
这个可以研究一下两个文件格式自己写，不会很难。
对比来说，其实最简单的方法就是作者提到的方法，找到编译后文件的可执行程序位置，手动复制黏贴。
当然可能有其他爱好者自己写的用于开发操作系统的c编译器，这个我就不知道了。


发现一种在windows非常简单的用mingw实现汇编和一起编译的方法，可以生成平台无关的裸机运行的二进制代码（linux的gcc是同理的）代码如下

汇编代码（head.asm）：
extern __main
[bits 32]
push __main
jmp __main
jmp $


main.c代码：
int _main()
{
  while(1){}
    return 0;
}



编译链接选项：
nasm -f win32 head.asm -o head.obj
gcc -c -x c -fno-builtin -ffreestanding -fno-ident -nostdinc -nostdlib -m32 main.c -o main.obj
ld -m i386pe -N -nostdlib --no-dynamic-linker -e __main -Ttext 0x0 head.obj main.obj -o bin/kernel.obj

注意这样链接出来的是pe格式的文件，我们的目标是编译生成纯二进制文件格式的代码，所以还需要一句话
objcopy -S -R ".eh_frame" -R ".comment" -O binary kernel.obj kernel.bin

这样就可以直接生成裸机运行的二进制代码了，我解释一下比较重要的编译选项，-e __main这个是指定程序入口的，
这里一定要指定__main，因为windows在进入main函数之前会调用__main进行初始化，
默认情况下这个函数是在windows提供的动态库里面，但是我们不能依赖它的库，所以我们要自己把这个函数给出来，
不然链接器就找不到这个函数了， -Ttext 0x0这个是指定代码段起始地址的，别的选项可以上网搜搜看什么作用，
大概就是去除库的依赖啥啥啥的，我贴一下我生成的代码,可以发现轻松进入main函数



linux0.11中起动部分的代码是如何从汇编跳入c语言函数的:
先将main函数入栈，然后利用ret弹出堆栈既可以执行c语言中的main函数了。
也可以直接用call ？


after_page_tables:
  pushl $main
  jmp setup_paging

setup_paging:
  ...
  ret            /* this also flushes prefetch-queue */
	
	


汇编程序中调用C函数
1、call指令
2、jmp指令
3、push+ret                                     linux 0.11采用的方式
4、将c语言编译位二进制，直接放在汇编代码后面    计算机自制操作系统-windows



c语言调用汇编

#hello.s
.code32
.section .data
    msg: .string "In hello.s!\n"
    len=.-msg
.text
.global _start,myprint
_start:
    movl $4,%eax
    movl $1,%ebx
    movl $msg,%ecx
    movl $len,%edx
    int $0x80


    pushl $0
    pushl $0
    pushl $0
    call main


//hello.c
#include <stdio.h>
void myprint(char * msg,int len);
int main()
{
    myprint("Hello, In hello.c!\n",20);
    return 0;
}


as -o hello.o hello.s ;如果在64位系统下，要加上 --32选项来编译
gcc -c -o hello_c.o hello.c ;如果在64位系统上，要加上-m32选项
ld -o hello hello.o hello_c.o ;如果在64位系统上，要加上 -m elf_i386选项
然后运行 ./hello




