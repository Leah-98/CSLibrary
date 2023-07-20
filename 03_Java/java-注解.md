## 注解基础

注解是JDK1.5版本开始引入的一个特性，用于对代码进行说明，可以对包、类、接口、字段、方法参数、局部变量等进行注解。它主要的作用有以下四方面：

- 生成文档，通过代码里标识的元数据生成javadoc文档。
- 编译检查，通过代码里标识的元数据让编译器在编译期间进行检查验证。
- 编译时动态处理，编译时通过代码里标识的元数据动态处理，例如动态生成代码。
- 运行时动态处理，运行时通过代码里标识的元数据动态处理，例如使用反射注入实例。

这么来说是比较抽象的，我们具体看下注解的常见分类：

- **Java自带的标准注解**，包括`@Override`、`@Deprecated`和`@SuppressWarnings`，分别用于标明重写某个方法、标明某个类或方法过时、标明要忽略的警告，用这些注解标明后编译器就会进行检查。
- **元注解**，元注解是用于定义注解的注解，包括`@Retention`、`@Target`、`@Inherited`、`@Documented`，`@Retention`用于标明注解被保留的阶段，`@Target`用于标明注解使用的范围，`@Inherited`用于标明注解可继承，`@Documented`用于标明是否生成javadoc文档。
- **自定义注解**，可以根据自己的需求定义注解，并可用元注解对自定义注解进行注解。

接下来我们通过这个分类角度来理解注解。

### Java内置注解

我们从最为常见的Java内置的注解开始说起，先看下下面的代码：

```java
class A{
    public void test() {
        
    }
}

class B extends A{

    /**
        * 重载父类的test方法
        */
    @Override
    public void test() {
    }

    /**
        * 被弃用的方法
        */
    @Deprecated
    public void oldMethod() {
    }

    /**
        * 忽略告警
        * 
        * @return
        */
    @SuppressWarnings("rawtypes")
    public List processList() {
        List list = new ArrayList();
        return list;
    }
}
```

Java 1.5开始自带的标准注解，包括`@Override`、`@Deprecated`和`@SuppressWarnings`：

- `@Override`：表示当前的方法定义将覆盖父类中的方法
- `@Deprecated`：表示代码被弃用，如果使用了被@Deprecated注解的代码则编译器将发出警告
- `@SuppressWarnings`：表示关闭编译器警告信息

我们再具体看下这几个内置注解，同时通过这几个内置注解中的元注解的定义来引出元注解。

#### @Override

我们先来看一下这个注解类型的定义：

```java
@Target(ElementType.METHOD)
@Retention(RetentionPolicy.SOURCE)
public @interface Override {
}
```

从它的定义我们可以看到，这个注解可以被用来修饰方法，并且它只在编译时有效，在编译后的class文件中便不再存在。这个注解的作用我们大家都不陌生，那就是告诉编译器被修饰的方法是重写的父类的中的相同签名的方法，编译器会对此做出检查，若发现父类中不存在这个方法或是存在的方法签名不同，则会报错。

#### @Deprecated

这个注解的定义如下：

```java
@Documented
@Retention(RetentionPolicy.RUNTIME)
@Target(value={CONSTRUCTOR, FIELD, LOCAL_VARIABLE, METHOD, PACKAGE, PARAMETER, TYPE})
public @interface Deprecated {
}
```

从它的定义我们可以知道，它会被文档化，能够保留到运行时，能够修饰构造方法、属性、局部变量、方法、包、参数、类型。这个注解的作用是告诉编译器被修饰的程序元素已被“废弃”，不再建议用户使用。

#### @SuppressWarnings

这个注解我们也比较常用到，先来看下它的定义：

```java
@Target({TYPE, FIELD, METHOD, PARAMETER, CONSTRUCTOR, LOCAL_VARIABLE})
@Retention(RetentionPolicy.SOURCE)
public @interface SuppressWarnings {
    String[] value();
}
```

它能够修饰的程序元素包括类型、属性、方法、参数、构造器、局部变量，只能存活在源码时，取值为String[]。它的作用是告诉编译器忽略指定的警告信息，它可以取的值如下所示：

| 参数                     | 作用                                               | 原描述                                                       |
| ------------------------ | -------------------------------------------------- | ------------------------------------------------------------ |
| all                      | 抑制所有警告                                       | to suppress all warnings                                     |
| boxing                   | 抑制装箱、拆箱操作时候的警告                       | to suppress warnings relative to boxing/unboxing operations  |
| cast                     | 抑制映射相关的警告                                 | to suppress warnings relative to cast operations             |
| dep-ann                  | 抑制启用注释的警告                                 | to suppress warnings relative to deprecated annotation       |
| deprecation              | 抑制过期方法警告                                   | to suppress warnings relative to deprecation                 |
| fallthrough              | 抑制确在switch中缺失breaks的警告                   | to suppress warnings relative to missing breaks in switch statements |
| finally                  | 抑制finally模块没有返回的警告                      | to suppress warnings relative to finally block that don’t return |
| hiding                   | 抑制与隐藏变数的区域变数相关的警告                 | to suppress warnings relative to locals that hide variable（） |
| incomplete-switch        | 忽略没有完整的switch语句                           | to suppress warnings relative to missing entries in a switch statement (enum case) |
| nls                      | 忽略非nls格式的字符                                | to suppress warnings relative to non-nls string literals     |
| null                     | 忽略对null的操作                                   | to suppress warnings relative to null analysis               |
| rawtype                  | 使用generics时忽略没有指定相应的类型               | to suppress warnings relative to un-specific types when using |
| restriction              | 抑制与使用不建议或禁止参照相关的警告               | to suppress warnings relative to usage of discouraged or     |
| serial                   | 忽略在serializable类中没有声明serialVersionUID变量 | to suppress warnings relative to missing serialVersionUID field for a serializable class |
| static-access            | 抑制不正确的静态访问方式警告                       | to suppress warnings relative to incorrect static access     |
| synthetic-access         | 抑制子类没有按最优方法访问内部类的警告             | to suppress warnings relative to unoptimized access from inner classes |
| unchecked                | 抑制没有进行类型检查操作的警告                     | to suppress warnings relative to unchecked operations        |
| unqualified-field-access | 抑制没有权限访问的域的警告                         | to suppress warnings relative to field access unqualified    |
| unused                   | 抑制没被使用过的代码的警告                         | to suppress warnings relative to unused code                 |