Android四大组件之一，为存储和获取数据提供统一的接口。可以在不同的应用程序之间共享数据。对于ContentProvier而言，无论数据的来源是什么，它都认为是种表，然后把数据组织成表格。

![image-20220602155655369](..\imgs\image-20220602155655369.png)

使用一：自定义ContentProvider

1.配置ContentProvider

(1)自定义类继承于ContentProvider，实现要求的方法

(2)在配置文件中通过provider标签配置，通过android:name属
性指定待配置的类，通过android:authorities属性授权，指定当前内容提供者的uri标识，必须唯一。

![image-20220604122823328](..\imgs\image-20220604122823328.png)

2.自定义ContentProvider

(1)onCreate，系统启动后，第一次启动ContentProvider所在的程序时调用；可以使用文件或数据库形式存储。

![image-20220604124212022](..\imgs\image-20220604124212022.png)

![image-20220604124251377](..\imgs\image-20220604124251377.png)

（2）insert

![image-20220604130349751](..\imgs\image-20220604130349751.png)

（3） query

![image-20220604131559840](..\imgs\image-20220604131559840.png)

(4)delete

![image-20220604131207528](..\imgs\image-20220604131207528.png)

(5)update



3.使用ContentResolver

 	cr = getContentResolver();

![image-20220604125735433](..\imgs\image-20220604125735433.png)

![image-20220604131125383](..\imgs\image-20220604131125383.png)

![image-20220604132057788](..\imgs\image-20220604132057788.png)

4.使用UrlMatcher

![image-20220604133346018](..\imgs\image-20220604133346018.png)

#代表任意数字内容

*代表任意字符内容

![image-20220604133251016](..\imgs\image-20220604133251016.png)

5.利用Url添加内容

![image-20220604133952624](..\imgs\image-20220604133952624.png)

![image-20220604134012197](..\imgs\image-20220604134012197.png)

使用二：使用系统的ContentProvider