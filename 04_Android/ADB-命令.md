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

