Linux From Scratch           一切从源码开始
                             scratch  搔痒
                             from scratch  从无到有
							 
构造lfs分两大步： 1、构建临时编译环境：（1）构建一个不依赖宿主系统的工具链(Binutils、GCC和Glibc： 编译器、汇编器、连接器、库文件以及一些有用的软件)
                                       （2）利用工具链构建其他基本工具
                  2、构建lfs系统

lfs官网  http://www.linuxfromscratch.org
中文     https://lctt.github.io/LFS-BOOK/
宿主机   CentOS-7-x89_64-DVD-1810.iso
linux内核      linux-5.1.tar.xz
lfs软件包集合  lfs-packages-8.4.tar
虚拟机         virtualbox
putty
winscp


http://ftp.lfs-matrix.net/pub/lfs/lfs-packages/9.0/



按照时间顺序init应用程序：
1、systemV守护进程     以前大不部分发行版都是使用SysV 因为它简单易用流程清晰。
2、UpStart             采用事件驱动模型，在2021的今天，Upstart已经被放弃了
2、systemD守护进程     现在大部分linux发行版都采用了systemd



