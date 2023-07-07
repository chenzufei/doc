
操作系统真相还原
Orange's:一个操作系统的实现
Xv6是由麻省理工学院(MIT)为操作系统工程的课程（代号6.828）,开发的一个教学目的的操作系统。  https://github.com/mit-pdos/xv6-public



Ubuntu16.04启用root用户及root用户开机自动登录
sudo passwd root
su root
apt-get install vim

vim /usr/share/lightdm/lightdm.conf.d/50-ubuntu.conf
greeter-show-manual-login=true

vim /usr/share/lightdm/lightdm.conf.d/50-unity-greeter.conf
user-session=ubuntu
greeter-show-manual-login=true
all-guest=false


vi /root/.profile
tty -s && mesg n || true



linux 0.11文件格式统一为已经过时的a.out格式,/bin/sh可执行程序对应的文件，其文件前1024个字节为就是a.out格式规定下的文件头信息。
现在的 Linux 已经弃用了这种古老的格式，改用 ELF 格式了


mount -o offset=1024 hdc-0.11.img old-fs

hdc-0.11.img有linux0.11根文件系统
hdc-0.11.img是如何生成的？


bochs-2.3.7


http://oldlinux.org/



