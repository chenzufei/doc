gcc         编译器，将c语言编译链接为可执行程序。
bash        shell的解释器，用户可以在shell中输入命令执行任务。
coreutils   实现了很多命令，比如ls、cp、dd等。
glibc       glibc最主要的功能就是对系统调用的封装，也提供了一些上层应用函数必要的功能,如string,malloc,stdlib,linuxthreads,locale,signal。
linux       操作系统内核，对上提供系统调用接口。

备注：
libc是Linux下原来的标准C库，也就是当初写hello world时包含的头文件#include < stdio.h> 定义的地方，后来逐渐被glibc取代。