# 概要

放置：在app/src/androidTest/java下

原理：创建一个独立于应用 APK 的测试 APK

设置：如果需要对测试APK进行一些设置，也可以直接将AndroidManifest.xml放在androidTest下进行设置。

# 配置

在app/build.gradle中添加以下行

```
    defaultConfig {
            :
        // for Instrumented Tests
        testInstrumentationRunner "androidx.test.runner.AndroidJUnitRunner"
    }

	...
	
    dependencies {
            :
        // for Instrumented Tests
        androidTestImplementation 'androidx.test:core:1.0.0'
        androidTestImplementation 'androidx.test:runner:1.1.0'
        androidTestImplementation 'androidx.test:rules:1.1.0'
        androidTestImplementation 'androidx.test.ext:junit:1.0.0'
        androidTestImplementation 'androidx.test.espresso:espresso-core:3.1.0'
        androidTestImplementation 'androidx.test.espresso:espresso-contrib:3.1.0'
        androidTestImplementation 'androidx.test.espresso:espresso-intents:3.1.0'
        androidTestImplementation 'androidx.test.uiautomator:uiautomator:2.2.0'
    }
```

如果要使用Coverage，在app/build.gradle中添加以下行

```
    buildTypes {
        debug {
            testCoverageEnabled true
        }
    }
```

