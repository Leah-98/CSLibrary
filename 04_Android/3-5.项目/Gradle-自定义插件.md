**Gradle是什么？**

- Gradle是一个自动化构建开源工具。
- Gradle运行在JVM中，执行Gradle就相当于开启了一个Java程序。

**创建Gradle的三种方式**

![Android Gradle三种自定义插件方式详解（含报错解决方案）_gradle](E:\personal\CSLibrary\04_Android\imgs\48)

#  **方式一：Build script脚本方式**

```groovy
apply plugin: MyPlugin
class MyPlugin implements Plugin<Project>{
    @Override
    void apply(Project project) {
        println "this is my plugin"
    }
}
```

![Android Gradle三种自定义插件方式详解（含报错解决方案）_android_02](E:\personal\CSLibrary\04_Android\imgs\49)


运行结果：

![Android Gradle三种自定义插件方式详解（含报错解决方案）_android_02](E:\personal\CSLibrary\04_Android\imgs\50)

# **方式二：buildSrc目录**

1、新建一个 buildSrc 文件夹

2、新建一个 build.gradle 文件，里面添加如下代码，然后点击 sync now，你就会发现 buildSrc 文件夹多了一个绿标

![Android Gradle三种自定义插件方式详解（含报错解决方案）_解决方法_04](E:\personal\CSLibrary\04_Android\imgs\51)

```groovy
apply plugin: "java"
apply plugin: 'java-gradle-plugin'
```


 3、新建子目录 src/main/java ,并编写一个插件类



```groovy
import org.gradle.api.Plugin;
import org.gradle.api.Project;

public class MyPlugin implements Plugin<Project> {
    @Override
    public void apply(Project project) {
	}
}
```

4、在app下的build.gradle里面应用

![Android Gradle三种自定义插件方式详解（含报错解决方案）_java_05](E:\personal\CSLibrary\04_Android\imgs\52)

运行结果展示：

![Android Gradle三种自定义插件方式详解（含报错解决方案）_android_06](E:\personal\CSLibrary\04_Android\imgs\53)

# 方式三：独立项目

1、新建一个独立的module，不要选错了！！！，

![Android Gradle三种自定义插件方式详解（含报错解决方案）_解决方法_07](E:\personal\CSLibrary\04_Android\imgs\54)

![Android Gradle三种自定义插件方式详解（含报错解决方案）_ide_08](E:\personal\CSLibrary\04_Android\imgs\55)

2、在该模块下的build.gradle里添加依赖

```groovy
dependencies {
    implementation gradleApi()
}
```


可能出现的报错 Build was configured to prefer settings repositories over project repositories but repository 'Gradle Libs' was added by unknown code

解决方法：

![Android Gradle三种自定义插件方式详解（含报错解决方案）_gradle_10](E:\personal\CSLibrary\04_Android\imgs\56)

 3、编写插件类

```groovy
package com.example.secondplugin;

import org.gradle.api.Plugin;
import org.gradle.api.Project;

public class MyClass implements Plugin<Project> {
    @Override
    public void apply(Project project) {
        System.out.println("this is third plugin");
    }
}
```

4、 编写插件配置文件

层级结构不能错

![Android Gradle三种自定义插件方式详解（含报错解决方案）_android_11](E:\personal\CSLibrary\04_Android\imgs\57)

![Android Gradle三种自定义插件方式详解（含报错解决方案）_java_12](E:\personal\CSLibrary\04_Android\imgs\58)

5、发布插件任务代码的编写

groupId、artifactId、version根据自己实际情况来写

![Android Gradle三种自定义插件方式详解（含报错解决方案）_ide_13](E:\personal\CSLibrary\04_Android\imgs\59)

![Android Gradle三种自定义插件方式详解（含报错解决方案）_android_14](E:\personal\CSLibrary\04_Android\imgs\60)

如果有小伙伴没找到task视图，解决方法如下：

![Android Gradle三种自定义插件方式详解（含报错解决方案）_ide_15](E:\personal\CSLibrary\04_Android\imgs\61)

6、点击如下按钮，发布到本地仓库

![Android Gradle三种自定义插件方式详解（含报错解决方案）_gradle_16](E:\personal\CSLibrary\04_Android\imgs\62)

7、使用

![Android Gradle三种自定义插件方式详解（含报错解决方案）_gradle_17](E:\personal\CSLibrary\04_Android\imgs\63)

![Android Gradle三种自定义插件方式详解（含报错解决方案）_android_18](E:\personal\CSLibrary\04_Android\imgs\64)

运行效果：

![Android Gradle三种自定义插件方式详解（含报错解决方案）_android_19](E:\personal\CSLibrary\04_Android\imgs\65)

 
