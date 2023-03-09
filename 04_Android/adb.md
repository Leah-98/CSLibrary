查看设备Android版本

```
adb shell getprop ro.build.version.sdk
```

查看设备列表 

```
adb devices
```

注入按键

```
adb shell input keyevent 219(219是语音键)
```

查看设备的cpu架构

```
adb shell getprop ro.product.cpu.abi
```

获取所有包名

```
adb shell pm list package
```

获取第三方包名

```
adb shell pm list package -3
```

全局查找文件

https://blog.csdn.net/chouzhou9701/article/details/119395831

```
> adb shell
# cd data/local/tmp
# ./busybox find 目录 -name "文件名"
# ./busybox find / -name "*.txt"
```

查看platform版本号
```
adb shell getprop ro.build.version.release
```

查看api版本号
```
adb shell getprop ro.build.version.sdk
```

获取设备名称
```
adb root
adb shell
cat /system/build.prop
```

查看所有的程序包名
```
adb shell pm list packages
```

查看Activities信息
```
adb shell dumpsys activity activities
```
