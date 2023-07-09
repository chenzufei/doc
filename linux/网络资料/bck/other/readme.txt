

 To get a working system you
need a shell, compilers, a library etc.


linux周边配套：
gcc 1.40
bash-1.12.1    目前没有找到对应版本的源码，只有bash-1.05-linux.tar.gz
                                           bash-1.12.tar.Z   这个是可执行程序
										   
										   
libc            glibc是封装的系统调用函数,但是只是封装了大部分系统调用,并不是所有的。
                目前不清楚采用哪个版本， 目前找到两个： lib-0.12.tar.Z和glibc-1.09.tar.gz
                 GLIBC 0.1 – 1991
                 GLIBC 1.0 – 1992
				 glib-1.06   1993
				 gibc-1.09   1995.3

各种命令（ps/date/mkfs/cp/dd/mv等）：目前不清楚采用的是哪个软件， 目前找到两个busybox（最早1996年）  busybox-0.25.tar.gz                 
                                                                              coreutils（第一个版本2003年4月4日发布） coreutils-5.0.tar.bz2
																			  GNU tools ？
																			  linux 0.11配套采用的是哪个呢？  参考minx？
																			  
 
ld,ar,nm      目前不清楚采用的是哪个软件，目前找到   binutils-1.9.tar.bz2
                                                     gas（GNU assembler）：gas-1.38.1.tar.bz2
													 binsrc.Tar.Z （1992）
													 binutils.001.tar.bz2（1988年12月）   binutils.002.tar.bz2（1989年4月）
													 binutils.tar.Z （1989年）



gnu coreutils 是原来的gnu shellutils, fileutils, textutils三部分合成的   目前找到fileutils-3.1.tar.Z


可以从如下网站找到:http://www.oldlinux.org/Linux.old/bin-src/
fdisk  fdisk-0.91.tar.Z
grep   grep-1.5.tar.Z
vi     
ls
mount/umount  mount-0.97.tar.Z 
mkfs   mkfs.c
ps     ps-0.97.tar.Z
unistd.tar.Z  unistd是unix standard的简称,主要封装了一些glibc函数和系统调用相关的定义, 这个和glibc的区别是什么




我个人理解：glibc是c语言库，里面部分封装了系统调用，比如内存申请和释放
            unistd主要封装了系统调用，有的给glibc调用，有的给其他shell程序调用。



 