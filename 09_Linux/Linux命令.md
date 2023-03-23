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

## 文件处理

### 路径操作

#### 切换路径 cd

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

#### 查看当前路径 pwd

#### 创建路径 mkdir

### 文件操作

#### 查看文件 ls

查看包括隐藏文件在内的所有文件

```
ls -a
```

![image-20230323145108477](E:\personal\CSLibrary\09_Linux\imgs\image-20230323145108477.png)

以详细信息列出文件，可指定文件名

```
ls -l
```

![image-20230323145224018](E:\personal\CSLibrary\09_Linux\imgs\image-20230323145224018.png)

![image-20230323145300447](E:\personal\CSLibrary\09_Linux\imgs\image-20230323145300447.png)

#### 创建新文件 touch

```bash
touch ...
```

### 文件路径操作

#### 复制文件/目录 cp

-r 递归复制目录下的文件和子目录







adb remount将 /system部分置于可写入的模式，默认情况下 /system 部分是只读模式的。这个命令只适用于已被 root 的设备。
在将文件 push 到 /system 文件夹之前，必须先输入命令 adb remount。
adb remount 的作用相当于 adb shell mount -o rw,remount,rw /system。

```bash
adb remount
```



# 网络配置

查看网卡

```shell
ifconfig -a
```

![image-20230322161152241](E:\personal\CSLibrary\09_Linux\imgs\image-20230322161152241.png)

eth0用于访问外部网络，默认情况下关闭

lo网卡用实现本机内部访问，IP地址为127.0.0.1（本机回送地址）

