# 1.没有配置ndk的项目找不到ndk路径

This is a Gradle bug that is documented here:
https://code.google.com/p/android/issues/detail?id=228424

 

The problem is that Gradle is computing the location of an NDK folder by just tacking on the string "/ndk-bundle" to the SDK folder location, even if you have never installed the NDK.

After establishing this false expectation of an NDK folder existing in a particular location, each time you build, Gradle gives you a warning that you're "missing" that folder. 

 

The solution was the following:

    1. Open project in Android Studio
    2. Wait for sync to finish
    3. Click on File -> Project structure -> SDK Location
    4. At Android NDK Location, if you don't have any NDK, install one
    5. Select an existing NDK location.

That should fix it.



# 2.Entry name 'assets/agent_channel.ini' collided



更改apk生成的路径，举个栗子，Android studio 打包默认路径是这样的：

![img](https://img-blog.csdnimg.cn/2020051409495296.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x1b19ib2tl,size_16,color_FFFFFF,t_70)

等待你的就是`Entry name 'res/layout/test_toolbar.xml' collided`

解决办法，更改生成apk的路径，如

![img](https://img-blog.csdnimg.cn/20200514095235468.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x1b19ib2tl,size_16,color_FFFFFF,t_70)
