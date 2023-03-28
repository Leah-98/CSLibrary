# 框架选择

- 如果您的测试对 Android 框架有依赖性（特别是与框架建立复杂互动的测试），最好使用 Robolectric 添加框架依赖项。
- 如果您的测试对 Android 框架的依赖性极小，或者如果测试仅取决于您自己的对象，可以使用诸如 Mockito 之类的模拟框架添加模拟依赖项。

# 设置测试环境

本地单元测试的源文件存储在 `module-name/src/test/java/` 中。当您创建新项目时，此目录已存在。

您还需要为项目配置测试依赖项，以使用 JUnit 4 框架提供的标准 API。如果您的测试需要与 Android 依赖项互动，请添加 Robolectric 或 Mockito 库以简化您的本地单元测试。

在应用的顶级 `build.gradle` 文件中，请将以下库指定为依赖项：

```gradle
    dependencies {
        // Required -- JUnit 4 framework
        testImplementation 'junit:junit:4.12'
        // Optional -- Robolectric environment
        testImplementation 'androidx.test:core:1.0.0'
        // Optional -- Mockito framework
        testImplementation 'org.mockito:mockito-core:1.10.19'
    }
```

