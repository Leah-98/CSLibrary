# 一、什么是PowerMock

PowerMock是一个Java单元测试模拟框架，用于解决测试问题,它是在其他的单元测试模拟框架的基础上做出了拓展。通过提供定制的类加载器以及一些字节码篡改技巧的应用，PowerMock实现了对<u>静态方法</u>，<u>构造方法</u>、<u>私有方法</u>以及<u>final</u>方法的模拟支持。

PowerMock支持JUnit和TestNG，扩展了EasyMock和Mockito框架，增加了mock static、final方法的功能。

举个例子，你在使用Junit进行单元测试时，并不想让测试数据进入数据库，怎么办？这个时候就可以使用PowerMock，拦截数据库操作，并模拟返回参数。

# 二、Mock底层原理

1. Mockito原理：

   底层使用了动态代理，用到了CGLIB。因此需要被mock的对象，Mockito都会生成一个子类继承该类，代理的对象会代替真实的对象进行执行。子类会覆盖父类。而static 修饰的方法不能被覆盖（也就是不能被重写）。这也就是为什么final修饰的类，private 方法，static 方法不可以被Mock的原因

2. PowerMock原理：
   javassist是一个<u>修改java字节码</u>的工具包，objenesis是一个<u>绕过构造方法来实例化一个对象</u>的工具包。由此看来，PowerMock的本质是通过修改字节码来实现对静态和final等方法的mock的。

   当某个测试方法被注解<u>@PrepareForTest</u>标注以后，在运行测试用例时，会创建一个新的org.powermock.core.classloader.MockClassLoader实例，然后加载该测试用例使用到的类（系统类除外）。
   PowerMock会根据你的mock要求，去修改写在注解@PrepareForTest里的class文件（当前测试类会自动加入注解中），以满足特殊的mock需求。例如：去除final方法的final标识，在静态方法的最前面加入自己的虚拟实现等。
   如果需要mock的是系统类的final方法和静态方法，PowerMock不会直接修改系统类的class文件，而是修改调用系统类的class文件，以满足mock需求。

# 三、应用场景

在现实的软件开发中，我们经常需要协同其他的同事一起来完成某个模块的动能开发，当我们需要测试的模块依赖于其他模块无法进行单元测试的时候，此时该模块的质量风险就有两个，第一是你所负责的代码，第二是你所依赖的代码。

当你没有办法在很快的时间协调到资源，那么你负责的代码不具备单元测试环境没有办法进行测试，可能存在很大的风险，这个时候如何测试你的代码，就需要用到mock。

# 其它

原文链接：https://blog.csdn.net/weixin_45119323/article/details/108019853