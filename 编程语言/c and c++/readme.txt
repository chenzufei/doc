

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

