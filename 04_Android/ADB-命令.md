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

