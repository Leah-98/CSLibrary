# 命令格式

```
command -shortoption parameter
command --longoption parameter
```

比如：

```
$rm -r dir
rm --recursive dir
```

注意：使用短选项时可以将多个选项合并

# 文件操作

## 路径操作

### cd 切换路径

切换到相对路径

```
cd ./xxx
```

切换到绝对路径

```
cd /xxx
```

切换到当前用户的家目录

```
cd ~
```

### pwd 查看当前路径

### mkdir 创建路径 

### rmdir 删除目录 

## 文件操作

### ls 查看文件 

-a 查看包括隐藏文件在内的所有文件![image-20230323145108477](E:\personal\CSLibrary\09_Linux\imgs\image-20230323145108477.png)

-l 以详细信息列出文件，可指定文件名

![image-20230323145224018](E:\personal\CSLibrary\09_Linux\imgs\image-20230323145224018.png)

![image-20230323145300447](E:\personal\CSLibrary\09_Linux\imgs\image-20230323145300447.png)

### cat 打印文件内容到输出设备 

### more 分页显示文件内容 

f/Space 显示下一页

Enter 显示下一行

q/Q 退出

### head 查看文件的前n行 

![image-20230323174303049](E:\personal\CSLibrary\09_Linux\imgs\image-20230323174303049.png)

### tail 查看文件的后n行 

![image-20230323174446751](E:\personal\CSLibrary\09_Linux\imgs\image-20230323174446751.png)

### touch 创建新文件 

## 文件路径操作

### cp 复制文件/目录

-r 递归复制目录下的文件和子目录

### mv 移动文件或目录 

### rm 删除目录中的文件或目录 

-f 强制删除文件或目录

-r 递归删除目录中所有子文件和子目录

-i 在删除文件或目录时对要删除的内容逐一进行确认

## 文件搜索

### which 查看命令所在路径

![image-20230323175613953](E:\personal\CSLibrary\09_Linux\imgs\image-20230323175613953.png)

### find 接触搜索关键字查找文件或目录

find 搜索路径 [选项] 搜索关键字

-name 根据文件名查找

-size 根据文件大小查找

-user 根据文件所有者查找

### locate 借助搜索关键字查找文件或目录

locate [选项] 搜索关键字

locate速度远胜find

find搜索整个目录，locate搜索数据库 /var/lib/locatedb

即使文件存在，数据库中没有记录，locate便搜索不到

### grep 在文件中搜索与字符串匹配的行并输出

![image-20230323175911567](E:\personal\CSLibrary\09_Linux\imgs\image-20230323175911567.png)

# 权限管理

权限分类

| 权限     | 对应字符 | 文件           | 目录                       |
| -------- | -------- | -------------- | -------------------------- |
| 读权限   | r        | 可查看文件内容 | 可以列出目录中的内容       |
| 写权限   | w        | 可修改文件内容 | 可以在目录中创建、删除文件 |
| 执行权限 | x        | 可执行该文件   | 可以进入目录               |

![image-20230323174808535](E:\personal\CSLibrary\09_Linux\imgs\image-20230323174808535.png)

-rwxrwxrwx为权限最开放的777

权限顺序：所属用户的权限、组群权限、其他用户的权限

## su 将用户切换为root

## chmod 变更文件或目录的权限

![image-20230323175025304](E:\personal\CSLibrary\09_Linux\imgs\image-20230323175025304.png)

## chgrp 变更文件或目录的所有者

![image-20230323175448522](C:\Users\5109U25854\AppData\Roaming\Typora\typora-user-images\image-20230323175448522.png)



# 网络管理与通信

## ifconfig 查看网卡

```shell
ifconfig -a
```

![image-20230322161152241](E:\personal\CSLibrary\09_Linux\imgs\image-20230322161152241.png)

eth0用于访问外部网络，默认情况下关闭

lo网卡用实现本机内部访问，IP地址为127.0.0.1（本机回送地址）

## netstat

## ping

## write 使当前用户向另一个用户发送信息

## wall 使当前用户向所有用户发送信息

# 压缩解压

## gzip/gunzip 

.gz 压缩后不保存源文件，若同时列出多个文件，则每个文件会被单独压缩

## zip/unzip

.zip 压缩后保存源文件

## bzip2/bunzip2

.bz2 使用选项 -k时保留源文件

## tar

打包多个文件或目录，通常与压缩命令一起使用

-c 产生.tar打包文件

-v 打包时显示详细信息

-f 指定压缩后的文件名

-z 打包，同时通过gzip指令压缩备份文件，压缩后格式为.tar.gz

-x 从打包文件中还原文件

![image-20230323180324490](E:\personal\CSLibrary\09_Linux\imgs\image-20230323180324490.png)

# 帮助命令

## man 查看帮助手册

-a 在所有的man帮助手册中搜索

-p 指定内容时，使用分页程序

-M 指定man手册搜索的路径

## info 也是查看帮助手册，编写方式不一样

## whatis  查询命令的功能

## whoami 打印当前有效的用户名称
