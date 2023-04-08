Year    C++ Standard              Informal name
1998    ISO/IEC 14882:1998[20]    C++98
2003    ISO/IEC 14882:2003[21]    C++03                       没有改变语言特性
2011    ISO/IEC 14882:2011[22]    C++11, C++0x                增加了许多新特性：auto，decltype，nullptr，range for，返回类型后置语法，
                                                                                final和override，=default和=delete，Lambda，std::move
                                                                                std::array，std::forward_list，std::unordered_map，std::unordered_set
                                                                                std::shared_ptr，std::unique_ptr，std::weak_ptr
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


当前主流
set(CMAKE_CXX_STANDARD 17)


gcc
Clang:(Clang是前端，中端优化和后端都在微观LLVM之中。)