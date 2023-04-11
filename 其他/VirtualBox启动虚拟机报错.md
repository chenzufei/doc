# 问题现象：VirtualBox启动虚拟机报错
Error -104 in supR3HardenedWinReSpawn! (enmWhat=5)

# 软件说明
win 10专业版 21H2
VirtualBox  6.1.36

# 解决办法：修改注册表
win+r后输入regedit，找到计算机\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\VBoxSup，将start值修改为2后重启计算机。

# 原因
个人猜测是vboxsup驱动启动类型不能选择为系统启动（start=1），只能选择为根据服务管理器自动挂载(start=2)。
