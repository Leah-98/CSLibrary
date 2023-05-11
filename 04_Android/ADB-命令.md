截屏

```
adb shell screencap -p /sdcard/Pictures/screenshot.png
adb pull /sdcard/Pictures/screenshot.png
```

更改系统文件权限

```shell
adb shell mount -rw -o remount /
adb shell mount -o rw,remount /
adb remount
```

查看前5进程cpu占用%

```
adb shell top -m 5 -d 1
```

查看所有已安装的app包名

```
adb shell pm list packages
```

查看自己安装的app包名

```
adb shell pm list packages -3
```

导出logcat

```
adb logcat -time > <file-location>
```

adb remount将 /system部分置于可写入的模式，默认情况下 /system 部分是只读模式的。这个命令只适用于已被 root 的设备。
在将文件 push 到 /system 文件夹之前，必须先输入命令 adb remount。
adb remount 的作用相当于 adb shell mount -o rw,remount,rw /system。

```bash
adb remount
```

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

用adb命令显示apk的版本

```
(Linux)
adb shell dumpsys package <package_name> | grep versionName
(Windows)
adb shell dumpsys package <package_name> | findstr versionName
```



给apk文件重新签名

一旦有了签名文件和APK文件，就可以使用Java自带的jarsigner工具对APK文件进行签名。例如，可以执行以下命令：

```
Copy code
jarsigner -verbose -sigalg SHA1withRSA -digestalg SHA1 -keystore mykeystore.keystore myapp.apk myalias
```

其中，mykeystore.keystore是签名文件的路径，myapp.apk是需要签名的APK文件的路径，myalias是签名文件中的别名。执行这个命令后，会提示输入签名文件的密码。
