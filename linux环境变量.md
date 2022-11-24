# 修改linux环境变量的两种方式：
## export命令，效力仅限于该次登陆操作，示例：
export SHELL="/bin/bash"

## 修改配置文件；
### 作用所有用户
/etc/profile            设置环境变量和启动程序
/etc/bashrc             shell的配置文件

### 作用当前用户
~/.bash_profile
~/.bashrc
~/.bash_logout

比如在~/.bashrc中添加alias ll=ls -l

### 修改配置文件后，使配置生效：
source /etc/profile

### shell中引用环境变量
echo $PATH

### c程序中引用环境变量
path = getenv("PATH");

### python中引用环境变量
import os
print os.environ['PATH']
