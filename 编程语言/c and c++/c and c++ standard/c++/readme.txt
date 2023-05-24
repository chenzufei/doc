
Year    C++ Standard              Informal name
1998    ISO/IEC 14882:1998[20]    C++98                       支持STL中的：vector，dequeue， list， set， map
2003    ISO/IEC 14882:2003[21]    C++03                       没有改变语言特性
2011    ISO/IEC 14882:2011[22]    C++11, C++0x                增加了许多新特性：auto，decltype，nullptr，range for，返回类型后置语法，
                                                                                final和override，=default和=delete，Lambda，std::move
                                                                                std::array，std::forward_list，std::unordered_map，std::unordered_set
                                                                                std::shared_ptr，std::unique_ptr，std::weak_ptr
                                                                                线程库
2014    ISO/IEC 14882:2014[23]    C++14, C++1y                泛型lambda、constexpr放松了限制，类型推导
2017    ISO/IEC 14882:2017[8]     C++17, C++1z                1、对auto表达式推导的规则进行了改变；
                                                              2、lambda表达式可以捕获“*this”；
                                                              3、新增inline变量，可以直接将全局变量定义在头文件中；
                                                              4、条件表达式中支持初始化语句；
                                                              5、枚举的直接列表初始化等等。
                                                              6、namespace嵌套
                                                              7、from_chars函数和to_chars
                                                              8、结构化绑定
                                                              9、std::tuple的隐式推导
                                                              10、if constexpr
                                                              11、std::shared_mutex
                                                              12、std::string_view
                                                              13、std::file_system
                                                              14、std::map/unordered_map try_emplace
                                                              15、std::apply
                                                              16、std::any
                                                              17、std::optional
                                                              18、std::variant
                                                              19、并行算法库

2020    ISO/IEC 14882:2020        C++20                       引入了更多特性
                                                              在c++20标准中gcc和clang都可以捕获结构化绑定的对象
                                                              Coroutines
                                                              Modules


当前程序主流使用的c++版本：
set(CMAKE_CXX_STANDARD 17)

主流编译器
gcc: 
Clang:(Clang是前端，中端优化和后端都在微观LLVM之中。)
msvc


支持C++11标准：GCC 4.6       2011年
               Clang 3.3     2013年
               MSVC2012

支持C++17标准：GCC 8.x        2018年
               Clang 5.0      2017年
               MSVC2017

https://gcc.gnu.org/projects/cxx-status.html
https://clang.llvm.org/cxx_status.html


引用就是别名
赋值运算符 Test& operator=(const Test& test);


时间            阶段                                       内容
1979 - 1981     C with classes	         类及派生类，C++早期设计出来的一个重要目的，就是支持面向对象。
1982 - 1985     C++1.0	                 1983年底，C++正式被命名
1986 - 1989     C++2.0	                 虚函数
1990 - 1993     C++3.0	                 命名空间、异常、模板
1998            C++98	                 C++标准第一个版本，绝大多数编译器都支持，得到了国际标准化组织(ISO)和美国标准化 协会认可，以模板方式重写C++标准库，引入了STL(标准模板库)
2003            C++03	                 C++标准第二个版本，语言特性无大改变，主要：修订错误、减少多异性
2005            C++05	                 C++标准委员会发布了一份计数报告(Technical Report，TR1)，正式更名C++0x，即：计 划在本世纪第一个10年的某个时间发布
2011            C++11	                 增加了许多特性，使得C++更像一种新语言，比如：正则表达式、基于范围for循环、auto 关键字、新容器、列表初始化、标准线程库等
2014            C++14	                 对C++11的扩展，主要是修复C++11中漏洞以及改进，比如：泛型的lambda表达式， auto的返回值类型推导，二进制字面常量等
2017            C++17	                 在C++11上做了一些小幅改进，增加了19个新特性，比如：static_assert()的文本信息可 选，Fold表达式用于可变的模板，if和switch语句中的初始化器等
2020            C++20	                 有模块、概念、范围、协程等新特性的增加



编程范式
非结构化         汇编语言和机器语言

结构化编程（也叫面向过程编程）     c（步骤）： 自顶向下，模块化、语句结构化（顺序、选择、循环）
面向对象编程     c++、python、java
函数式编程       Lisp，把函数变成纯粹的数据 ？？？没理解， Lambda，函数是一等公民。尾递归，高阶函数，闭包（Closure）


数据抽象编程     c/c++（数据归类）
泛型编程         c++（模版）






编程比较重要的一些问题或功能：
（1）内存泄漏、踩内存；
（2）重复造轮子；
（3）生态；


其他语言（比如python、js）有官方的第三方库，可以通过命令直接安装，二c++没有。
c++没有python的内存垃圾回收机制，只提供了share_ptr支持。







