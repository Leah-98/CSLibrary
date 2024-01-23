系统中运行的第一个Dalvik虚拟机程序叫作zygote，该名称的意义是“一个卵”，因为接下来的所有 Dalvik虚拟机进程都是通过这个“卵” 孵化出来的。

zygote进程对应的具体程序是app_process，该程序存在于system/bin目录下，启动该程序的指令是在init.rc中进行配置的。

Zygote进程中包含两个主要模块，分别如下：

- **Socket服务端**。该Socket服务端用于接收启动新的Dalvik进程的命令。
- Framework共享类及共享资源。当Zygote进程启动后，会装载一些共享的类及资源，其中共享类是在preload-classes文件中被定义，共享资源是在preload-resources中被定义。因为zygote进程用于孵化出其他Dalvik进程，因此，这些类和资源装载后，新的Dalvik进程就不需要再装载这些类和资源了，这就是所谓的共享。--> zygote进程预先会装载共享类和共享资源，这些类及资源实际上就是SDK中定义的大部分类和资源。因此，当通过zygote孵化出新的进程后，新的APK进程只需要去装载APK自身包含的类和资源即可，这就有效地解决了多个APK共享Framework资源的问题。

在Android系统中有以下两种程序：

- Java应用程序，主要基于ART虚拟机，所有的应用程序APK都属于这类Native程序，也就是利用C或C++语言开发的程序，如bootanimation。所有的Java应用程序进程及系统服务SystemServer进程都由Zygote进程通过Linux的fork()函数孵化出来的。 --> 每fork出的一个进程都是一个Dalvik虚拟机，独立的进程可以防止一个程序的崩溃导致所有程序都崩溃，这种虚拟机类似Java虚拟机，对于程序员来说，可以直接使用Java开发应用。
- 而native程序则由Init程序创建启动。

Zgyote是Android中的第一个ART虚拟机，他通过socket的方式与其他进程进行通信。这里的其他进程主要指系统进程——**SystemServer**。

Zygote是一个C/S模型，Zygote进程作为服务端，它主要负责创建java虚拟机，加载系统资源，启动SystemServer进程，以及在后续运行过程中启动普通的应用程序，其他进程作为客户端向它发出孵化请求，而Zygote接收到这个请求后就“孵化”出一个新的进程。比如，当点击Launcher里的应用程序图标去启动一个新的应所以程序进程时，这个请求会到达框架层的核心服务**ActivityManagerService**中，当AMS收到这个请求后，它通过掉牙Process类发出一个“孵化”紫禁城的Socket请求，而Zygote监听到这个请求后就立刻fork一个新的进程出来。



![img](D:\personal\CSLibrary\04_Android\imgs\12.png)