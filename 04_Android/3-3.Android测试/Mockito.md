# 介绍

Mockito可以方便地创建真实对象的替代品以用于测试



Mockito 2.x 增加的限制：

- 需要 Java 6+
- 不能 mock 静态方法
- 不能 mock 构造器
- 不能 mock equals() hashCode()

Mockito定义并依赖基于这些方法的具体实现，重新定义它们可能会破坏Mockito。

- 只有在Obgenesis支持的虚拟机上才能进行 mock 。

Objenesis是一个小的Java库，它可以实例化一个特定类的新对象。

绝大多数的虚拟机都满足这个条件。

- 通过外部类在外部类中监视真实方法的真实实现是不可能的，但这种情况极为罕见。

# 使用

添加库依赖：

```
dependencies {
	testImplementation 'org.mockito:mockito-core:2.28.2'
}
```



步骤：

- 通过 mock()或spy() 创建程序化mock。
- 通过 Mockito.when(mock.action()).thenReturn(true)进行程序化Stubbing
- 自定义mock回答或提供自己的回答
- 通过 Mockito.verify(mock).action() 进行程序化验证
- 使用 @Mock @Spy @Captor @InjectMocks 等注释糖
- 使用 MockitoJUnit.rule()



mock的简单使用

```
// You can mock concrete classes and interfaces
TrainSeats seats = mock(TrainSeats.class);

// stubbing appears before the actual execution
when(seats.book(Seat.near(WINDOW).in(FIRST_CLASS))).thenReturn(BOOKED);

// the following prints "BOOKED"
System.out.println(seats.book(Seat.near(WINDOW).in(FIRST_CLASS)));

// the following prints "null" because 
// .book(Seat.near(AISLE).in(FIRST_CLASS))) was not stubbed
System.out.println(seats.book(Seat.near(AISLE).in(FIRST_CLASS)));

// the following verification passes because 
// .book(Seat.near(WINDOW).in(FIRST_CLASS)) has been invoked
verify(seats).book(Seat.near(WINDOW).in(FIRST_CLASS));

// the following verification fails because 
// .book(Seat.in(SECOND_CLASS)) has not been invoked
verify(seats).book(Seat.in(SECOND_CLASS));
```

