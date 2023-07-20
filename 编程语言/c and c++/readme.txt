

c编程：
静态分析：cpplint
代码走读：
动态分析（单元测试）：cunit

stub - 桩


c，极致的简单纯粹，是世界上语法最简单的语言
异常处理，纯粹是废物机制
c++的复杂语法会让阅读代码变得更加更加复杂
相比c，c++隐藏细节太多

新版本的C加上的那个破烂泛型比C++的模板更难以理解



c语言：
结构体
struct stu{
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在学习小组
    float score;  //成绩
};


枚举
enum week{ Mon, Tues, Wed, Thurs, Fri, Sat, Sun };


共用体
union data{
    int n;
    char ch;
    double f;
};



cmake: 根据CMakeLists.txt 生成Makefile
make : 根据Makefile中的相关命令编译、连接，最终生成可执行文件。
gcc  ：GNU编译器套件，通过gcc编译文件，输出汇编文件
                      通过as将汇编文件输出为二进制文件
                      通过ld将二进制文件生成可执行文件


CFLAGS += -std=c++11
cmake -DCMAKE_CXX_STANDARD=11
set(CMAKE_CXX_STANDARD 11)



c++学习资料


1. 入门推荐
《C++程序设计语言》 c++之父（Bjarne Stroustrup）的经典书籍，英文版本"The C++ Programming Language"。
《C++ Primer》 c++第一个编译器的作者 [book]，Lippman、Lajoie、Moo， ISBN: 9787121155352
《Accelerated C++》（美国斯坦福大学的经典教材）

2. 提高
《Effective C++》、《More Effective C++》 2本书都是经典的建议和推荐，作者是Scott Meyers。
《深度探索C++对象模型》 "Inside the C++ Object Model"
《Modern C++ Design》
《C++标准程序库》 "C++ Standard Library Tutorial and Reference" 手册类，可以当作工具书。

3、进阶
《C++ 沉思录》
《深度探索 C++ 对象模型》
《C++设计与演化》



每一个.c文件都是一个独立的编译单元，单独编译，互不影响。两个.c文件引用同一个头文件不会出现任何冲突问题。
头文件中的#ifndef解决的是菱形引用问题，即两个头文件b.h和c.h引用了同一个头文件a.h，而源文件d.c中同时包含了b.h和c.h，
则a.h将被包含两次，从而导致命名冲突。在a.h中使用#ifndef可以确保a.h只被包含一次。