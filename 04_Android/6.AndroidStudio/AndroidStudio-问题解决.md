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

# 3.Entry name *.xml collided 解决

https://blog.csdn.net/luo_boke/article/details/106113266

总结：更改打包生成路径

# 4. Current JDK version 1.8.0_341-b10 has a bug

 (https://bugs.openjdk.java.net/browse/JDK-8007720) that prevents Room from being incremental. 

https://stackoverflow.com/questions/58822538/current-jdk-version-1-8-has-a-bug-that-prevents-room-from-being-incremental

# 5.The specified Gradle installation directory does not exist error...

https://stackoverflow.com/questions/71452170/the-specified-gradle-installation-directory-does-not-exist-error-after-android-s

![image-20230403145156197](E:\personal\CSLibrary\04_Android\imgs\image-20230403145156197.png)

选择'gradle-wrapper.properties' file

# 6.output中文乱码问题

https://blog.csdn.net/jankingmeaning/article/details/104772104

