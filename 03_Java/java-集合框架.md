# Collection 类关系图

- Collection
  - Set
    - TreeSet：基于红黑树实现，支持有序性操作，例如根据一个范围查找元素的操作。但是查找效率不如 HashSet，HashSet 查找的时间复杂度为 O(1)，TreeSet 则为 O(logN)
    - HashSet
    - LinkedHashSet
  - List
    - ArrayList
    - Vector
    - LinkedList
  - Queue
    - LinkedList
    - PriorityQueue
- Map
  - TreeMap
  - HashMap
  - HashTable
  - LinkedHashMap

![img](D:\personal\CSLibrary\03_Java\imgs\2.png)

容器，就是可以容纳其他Java对象的对象。*Java Collections Framework(JCF)*为Java开发者提供了通用的容器，其始于JDK 1.2，优点是:

- 降低编程难度
- 提高程序性能
- 提高API间的互操作性
- 降低学习难度
- 降低设计和实现相关API的难度
- 增加程序的重用性

Java容器里只能放对象，对于基本类型(int, long, float, double等)，需要将其包装成对象类型后(Integer, Long, Float, Double等)才能放到容器里。很多时候拆包装和解包装能够自动完成。这虽然会导致额外的性能和空间开销，但简化了设计和编程。

## Collection