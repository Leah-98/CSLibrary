# Collection 类关系图

- Collection
  - Set
    - TreeSet：基于红黑树实现，支持有序性操作，例如根据一个范围查找元素的操作。但是查找效率不如 HashSet，HashSet 查找的时间复杂度为 O(1)，TreeSet 则为 O(logN)
    - HashSet：基于哈希表实现，支持快速查找，但不支持有序性操作。并且失去了元素的插入顺序信息，也就是说使用 Iterator 遍历 HashSet 得到的结果是不确定的。
    - LinkedHashSet：具有 HashSet 的查找效率，且内部使用双向链表维护元素的插入顺序。
  - List
    - ArrayList：基于动态数组实现，支持随机访问。
    - Vector：和 ArrayList 类似，但它是线程安全的。
    - LinkedList：基于双向链表实现，只能顺序访问，但是可以快速地在链表中间插入和删除元素。不仅如此，LinkedList 还可以用作栈、队列和双向队列。
  - Queue
    - LinkedList：可以用它来实现双向队列。
    - PriorityQueue：基于堆结构实现，可以用它来实现优先队列。
- Map
  - TreeMap：基于红黑树实现。
  - HashMap：基于哈希表实现。
  - HashTable：和 HashMap 类似，但它是线程安全的，这意味着同一时刻多个线程可以同时写入 HashTable 并且不会导致数据不一致。它是遗留类，不应该去使用它。现在可以使用 ConcurrentHashMap 来支持线程安全，并且 ConcurrentHashMap 的效率会更高，因为 ConcurrentHashMap 引入了分段锁。
  - LinkedHashMap：使用双向链表来维护元素的顺序，顺序为插入顺序或者最近最少使用(LRU)顺序。

![img](D:\personal\CSLibrary\03_Java\imgs\2.png)

Java容器里只能放对象，对于基本类型(int, long, float, double等)，需要将其包装成对象类型后(Integer, Long, Float, Double等)才能放到容器里。很多时候拆包装和解包装能够自动完成。这虽然会导致额外的性能和空间开销，但简化了设计和编程。

容器主要包括 Collection 和 Map 两种，Collection 存储着对象的集合，而 Map 存储着键值对(两个对象)的映射表。

# Collection

## ArrayList 

底层原理：

1. 实现了List接口
2. 底层通过数组实现
3. 是顺序容器，即元素存放的数据与放进去的顺序相同。
4. 每个*ArrayList*都有一个容量(capacity)，表示底层数组的实际大小，容器内存储元素的个数不能多于当前容量。当向容器中添加元素时，如果容量不足，容器会自动增大底层数组的大小。数组进行扩容时，会将老数组中的元素重新拷贝一份到新的数组中，每次数组容量的增长大约是其原容量的1.5倍。
5. add()\addAll()执行之前，都会进行剩余空间检
6. `remove()`方法，将删除点之后的元素向前移动一个位置，需要注意的是为了让GC起作用，必须显式的为最后一个位置赋`null`值。

使用注意：

1. 允许放入null元素
2. size(), isEmpty(), get(), set()方法均能在常数时间内完成，add()方法的时间开销跟插入位置有关，addAll()方法的时间开销跟添加元素的个数成正比。其余方法大都是线性时间。
3. 为追求效率，ArrayList没有实现同步(synchronized)，如果需要多个线程并发访问，用户可以手动同步，也可使用Vector替代。
4. 在实际添加大量元素前，我也可以使用ensureCapacity来手动增加ArrayList实例的容量，以减少递增式再分配的数量。新的容量需要大于原来容量的1.5倍，不然会被强行转化为1.5倍
5. trimToSize()将底层数组的容量调整为当前列表保存的实际元素的大小
6. ArrayList也采用了Fail-Fast的机制，通过记录modCount参数来实现。在面对并发的修改时，迭代器很快就会完全失败，而不是冒着在将来某个不确定时间发生任意不确定行为的风险。