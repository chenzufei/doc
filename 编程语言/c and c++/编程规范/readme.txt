
1、linux内核编程规范
https://www.kernel.org/doc/html/latest/process/coding-style.html

2、C++编码的格式风格遵守《Google 开源项目风格指南》(Google C++ Style Guide)
https://google.github.io/styleguide/cppguide.html

3、C++编码的最佳实践及规范遵守C++社区的《C++ 核心指南》(CppCoreGuidelines)
https://github.com/isocpp/CppCoreGuidelines


4、检查及格式化（clang-tidy和clang-format）
（1）vscode需要安装clangd插件
（2）linux上需要安装llvm（https://github.com/llvm/llvm-project  clang+llvm-15.0.6-x86_64-linux-gnu-ubuntu-18.04.tar.xz）;
     将clangd,clang-tidy和clang-format拷贝到/usr/local/bin

备注：
（1）CMakeListx.txt中加入set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
     将make生成的compile_commands.json放在工程跟目录
（2）.clang-tidy文件配置(放在工程根目录)，参见clang.llvm.org/extra/clang-tidy/checks/list.html
     .clang-format文件配置(放在工程根目录)