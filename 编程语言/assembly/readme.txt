
汇编(Assembly)


AT&T汇编语法： GNU Assembler (GAS)
Intel汇编语法： Microsoft Macro Assembler (MASM)
Netwide Assembler (NASM)使用的汇编语法和Intel汇编语法类似


汇编语言指令大致分为以下几类
一、传送类指令
1、数据传送指令    MOV/XCHG
2、有效地址传送指令LEA
3、堆栈指针操作指令  PUSH/POP
4、输入输出执行   IN/OUT
二、算数运算类指令
1、加法指令   ADD/ADC/INC
2、减法指令   SUB/SBB/DEC
3、求补指令   NEG
4、比较指令   CMP
5、乘法指令   MUL/IMUL
6、除法指令   DIV/IDIV
三、位操作指令  AND/or/XOR/NOT/TEST/SHL/SAL/SHR/SAR/ROL/ROR/RCL/RCR
四、串操作指令
五、控制转移类指令  
1、无条件转移：JMP/CALL/RET/RETF
2、条件转移
3、循环控制指令：LOOP/LOOPE/LOOPZ/JCXZ
4、中断指令      INT/INTO/IRET
六、处理器控制类指令   12个
七、汇编指令伪指令  DW/PROC/ENDP/SEGMENT/ASSUME/ENDS/END



1、常用寄存器寄存器
函数返回值传参     %rax
函数传参的寄存器总共有6个: %rdi，%rsi, %rdx, %rcx, r8, r9; 第7个参数会使用栈来传递

状态寄存器: SF（符号寄存器），OF（溢出寄存器），CF等

栈： 栈空间扩展方向是从高地址到低地址的。
栈底指针: %rbp
栈顶指针: %rsp

下一条运行的指令: %rip


2、常用汇编指令
(1)mv: mov des,src
(2)cmp:cmp A,B
(3)jmp: jmp Lable
(4)push: push %reg
(5)pop: pop %reg
(6)call: all Address
(7)ret     函数返回
(8)lea     获取内存地址


3、其他
返回小于等于4字节的基本类型，例如short,int，都是直接使用eax寄存器返回，而指针，也是使用eax寄存器返回。
如果结构体或者说类只占8字节或者更小的话，也是直接使用寄存器返回的。
返回的结构体大于8字节：结构体复制到了arg1指向的地址，arg1就是刚刚传进来的eax，这个返回的结构体，是直接复制到了上一个方法的局部变量区


