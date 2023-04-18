# 介绍

一个快速的AndroidUT框架

wiki：

http://robolectric.org/

# 使用

## 添加依赖库：

```
dependencies{
	testImplementation 'androidx.text:core:1.2.0'
	testImplementation 'org.robolectric:robolectric:4.3.1'
}
```

## TestRunner：

you can use RobolectricTestRunner and AndroidJUnit4 in Robolectric tests

## 配置：

**配置 SDK 级别：**

By default, Robolectric will run your code against the targetSdkVersion specified in your 

manifest. If you want to test your code under a different SDK, you can specify the SDK 

using the sdk, minSdk and maxSdk config properties.

**配置 Application Class:**

Robolectric will attempt to create an instance of your Application class as specified in the 

manifest. If you want to provide a custom implementation, you can specify it by setting:

@Config(application = CustomApplication.class)

**配置 限定符：**

You can explicitly configure the set of resource qualifiers in effect for a test;

@Test @Config(qualifiers = "fr-rFR-w360dp-h640dp-xhdpi")

**限定符表：**

| **Property**                          | **Calculated value (if unspecified)**                        | **Default** | **Other rules**                                              |
| ------------------------------------- | ------------------------------------------------------------ | ----------- | ------------------------------------------------------------ |
| MCC and MNC                           | None.                                                        | None        |                                                              |
| Language, region, and script (locale) | None.                                                        | en-rUS      |                                                              |
| Layout direction                      | The locale’s layout direction.                               | ldltr       |                                                              |
| Smallest width                        | The smaller of width and height                              | sw320dp     |                                                              |
| Width                                 | If screen size is specified, the  corresponding width as declared here. | w320dp      | If screen orientation is specified,  width and height will be swapped as appropriate. |
| Height                                | If screen size is specified, the  corresponding height as declared here. If screen aspect is specified as long,  the height is increased by 25%. | h470dp      | If screen orientation is specified,  width and height will be swapped as appropriate. |
| Screen size                           | If height and width are specified, the  corresponding screen size as declared here. | normal      |                                                              |
| Screen aspect                         | If width and height are specified, long  will be used if the ratio of height to width is at least 1.75. | notlong     |                                                              |
| Round screen                          | If UI mode is watch  then round.                             | notround    |                                                              |
| Wide color gamut                      | None.                                                        | nowidecg    |                                                              |
| High dynamic range                    | None.                                                        | lowdr       |                                                              |
| Screen orientation                    | If width and height are specified, port  or land as appropriate. | port        |                                                              |
| UI mode                               | None.                                                        |             | normal, except this property isn’t  included in the qualifier list. |
| Night mode                            | None.                                                        | notnight    |                                                              |
| Screen pixel density                  | None.                                                        | mdpi        |                                                              |
| Touchscreen type                      | None.                                                        | finger      |                                                              |
| Keyboard availability                 | None.                                                        | keyssoft    |                                                              |
| Primary text input method             | None.                                                        | nokeys      |                                                              |
| Navigation key availability           | None.                                                        | navhidden   |                                                              |
| Primary non-touch navigation method   | None.                                                        | nonav       |                                                              |
| Platform version                      |                                                              |             | The SDK level currently active. Need  not be specified.      |

配置方法：

- robolectric.properties
  - 包级的配置
- @Config
  - 类级、方法级的配置（运行时）
- 优先级：
  - @Config会覆盖robolectric.properties中的配置
  - 方法级的配置会覆盖类级的配置

**robolectric.properties File:**

To configure all Robolectric tests within a package or group of packages, create a file named robolectric.properties in the appropriate package.

location:src/test/resources

example:

```
# src/test/resources/com/mycompany/app/robolectric.properties

sdk=18
shadows=my.package.ShadowFoo,my.package.ShadowBar
```

**Build System Integration:**

Starting with Robolectric 3.3, the test runner will look for a file named /com/android/tools/test_config.properties on the classpath. If it is found, it will be used to provide the default manifest, resource, and asset locations for tests, without the need to specify @Config(constants=BuildConfig.class) or @Config(manifest="...", res="...", assets="...") in your tests.

Keys in the file:

- android_merged_manifest: Full path to the project’s merged AndroidManifest.xml file.
- android_merged_resources: Full path to the project’s merged resources.
- android_merged_assets: Full path to the project’s merged assets.
- android_custom_package: Java packagename for the applications R class.
- android_resource_apk: Path to a resources.ap_ file that contains binary resources and XML files produced by aapt tool, as well as merged assets.



## **Shadows:**

Robolectric works by creating a runtime environment that includes the real Android framework code. This means when your tests or code under test calls into the Android framework you get a more realistic experience as for the most part the same code is executed as would be on a real device. There are limitations however:

- Native code - Android native code cannot execute on your development machine.
- Out of process calls - There are no Android system services running on your development machine.
- Inadequate testing APIs - Android includes next to no APIs suitable for testing



Robolectric fills these gaps with a set of classes known as Shadows. Each shadow can modify or extend the behavior of a corresponding class in the Android OS. When an Android class is instantiated, Robolectric looks for a corresponding shadow class, and if it finds one it creates a shadow object to associate with it.



Using byte code instrumentation Robolectric is able to weave in cross platform fake implementations to substitute for native code and add additional APIs to make testing possible.



for shadow detail:please read the article

http://robolectric.org/extending/



## Test Runner config(Robolectric + PowerMock)

| **framework** | **corresponding test runner** | **rule**            |
| ------------- | ----------------------------- | ------------------- |
| Mock          | MockitoJUnitRunner            | MockitoJUnit.rule() |
| PowerMock     | PowerMockRunner               | PowerMockRule       |
| Robolectric   | RobolectricTestRunner         | --                  |

RunWith can only have one item, we can use AndroidJUnit4 to delegate 

RobolectricTestRunner and add rule PowerMockRule to implement

Robolectric + PowerMock

![image-20230329141308184](E:\personal\CSLibrary\04_Android\imgs\image-20230329141308184.png)

## Espresso & Robolectric

Espresso is the view matching and interaction library of choice for instrumentation tests.

Since Robolectric 4.0, Espresso APIs are now supported in Robolectric tests.

the Espresso detail:please refer to 

https://developer.android.google.cn/training/testing/espresso?hl=en

simple usages in robolectric test:

```kotlin
@RunWith(AndroidJUnit4::class)
class FragmentTest{
	@Test fun testEventFragment(){
        val fragmentArgs = Bundle()
        val factory = MyFragmentFactory()
        val scenario = launchFragmentInContainer<MyFragment>(fragmentArgs,factory)
        onView(withId(R.id.text)).check(matches(withText("Hello World")))
    }
}
```

