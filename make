.PHONY    //make 或 make clean将忽略targets是否存在，直接运行commands
$^          表示所有的依赖文件
$@          表示目标文件
$<          表示第一个依赖文件
$?          表示比目标还要新的依赖文件列表
$%          仅当目标是函数库文件中，表示规则中的目标成员名。


makefile规则：用于说明如何生成一个或多个目标文件
规则的格式：
targets：prerequisites
  command  command之前必须是一个tab键

示例：
ALL:test
test.o:test.c
	gcc -c test.c -o test.o
test:test.o
	gcc test.o -o test
clean:
	rm -rf test test.o
