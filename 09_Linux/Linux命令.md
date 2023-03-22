创建新文件

```bash
touch ...
```

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

