# 一、基础概念

DB（database）

DBMS（database management system）DB是通过DBMS创建和操作的容器

常见的DBMS：MySQL Oracle（贵） DB2（处理海量的数据） SqlServer（微软公司，只能安装在Windows操作系统下）

# 二、DQL语句

## 基础查询

**语法:**

```
select <查询列表> from <表名>；
```

类似于:System.out,printIn(打印东西)；

**特点：**

1. 查询列表可以是：表中的字段、常量值、表达式、函数

2. 查询的结果是一个虚拟的表格

**用例：**

```SQL
#查询表中的单个字段
select last_name from employees;
#查询表中的多个字段
select last_name,salary,email from employees;
#查询表中的所有字段
select * from employees;
#查询常量值
select 100; 
select 'john';
#查询表达式
select 100%98;
#查询函数
select version();
#起别名
/*    用处：
        1.便于理解；
        2.如果要查询的字段有重名的情况，使用别名可以区分开来。
*/
select 100%98 as 别名
select last_name as 姓, first_name as 名 from employees;
select last_name 姓, first_name 名 from employees;
#eg.查询salary,显示结果为out put
select salary as out put from employees;#out被识别为关键字，出现错误
select salary as "out put" from employees;
#去重
#eg.查询员工表中涉及到的所有部分编号
select department_id from employees;//会有重复信息
select distinct department_id from employees;
#+号的作用
/*用法：
	只能作为运算符使用。
	如果有字符型，尝试转换成数值型，再进行运算（“1”->1）;如果转换失败，则转换成0，再进行运行。
	只要其中一方为null，结果肯定为null
*/
#eg.查询员工名和员工的姓，连接成一个字段，并显示为 姓名
select 
	concat(last_name,first_name) as 姓名 
from 
	employees;  
#eg.查询出表employees的全部列，各个列之间用逗号连接，列头显示成out_put
select 
	concat('first_name', ',' , 'last_name', ',' ,'job_id', ',',IFNULL(commission_pct,0)) as out_put
from
	employees;
```

## 条件查询

语法：

```sql
select 
	查询列表 
from
	表名
where
	筛选条件;
```

分类：

- 按条件表达式筛选
  - 条件运算符 > < = != <> >= <=
- 按逻辑表达式筛选
  - 逻辑运算符 && || ! 
  - and or not
- 模糊查询
  - like
  - between and
  - in
  - is null

用例：

### 1.按条件表达式筛选

```sql
#eg. 查询工资>12000的员工信息
SELECT
	*
FROM
	employees
WHERE 
	salary>12000;
#eg. 查询部门编号不等于90号的员工名和部门编号
SELECT 
	last_name,
	department_id
FROM
	employees
WHERE
	department_id!=90;//不标准，最好是department_id<>90;
```

### 2.按逻辑表达式筛选

```sql
#eg.查询工资z在10000到20000之间的员工名，工资和奖金
SELECT
    last_name,
    salary,
    commission_pct
FROM
	employees
WHERE
	salary>=10000 AND salary<=20000;
#eg.查询部门编号不是在90到110之间，或者工资高于15000的员工信息
SELECT
	*
FROM
	employees
WHERE
	department_id<90 OR department_id>110 OR salary>15000;
```

### 3.模糊查询

#### 3.1 like

特点：

- \- 一般和通配符搭配使用
- %任意多个字符，包含0个字符
- _任意单个字符

```sql
#eg. 查询员工名共包含字符a的员工信息
SELECT
	*
FROM
	employees
WHERE
	last_name LIKE '%a%';//默认大小写a是一回事
#eg.查询员工名中第三个字符为e，第五个字符为a的员工名和工资
SELECT
	last_name
FROM
	employees
WHERE
	last_name LIKE '___e_a%';
#eg. 查询员工名中第二个字符为下划线的员工名
SELECT
	last_name
FROM
	employees
WHERE
	last_name LIKE '_\_%';
SELECT
	last_name
FROM
	employees
WHERE
	last_name LIKE '_$_%' ESCAPE '$';
```

#### 3.2 between and 

注意：

- 使用 between and 可以提高语句的简洁度

- 包含临界值

- 两个临界值不要调换顺序

```sql
#eg. 查询员工编号在100到120之间的员工信息
SELECT
	*
FROM
	employees
WHERE
	employee_id BETWEEN 100 AND 120;
```

#### 3.3 in关键字

含义：判断某字符的值是否属于in列表中的某一项

特点：

- 使用in提高语句简洁度

- in列表的值必须是同样的类型，或者可以兼容的类型，即可以隐式转换

```sql
#eg. 查询员工的公众编号是 IT_PROG、AD_VP、AD_PRES中的一个的员工名和工种编号
SELECT
	last_name,
	job_id
FROM
	employees
WHERE
	job_id IN ('IT_PROG','AD_VP','AD_PRES');
```

#### 3.4 is null 关键字

= 或 <> 不能用于判断null值

is null 或 is not null 可以判断null值

```sql
#eg. 查询没有奖金的员工名和奖金率
SELECT
	last_name,
	commission_pct
FROM
	employees
WHERE
	commission_pct IS NULL;
```

### 4.安全等于<=>

特点：可读性差

```sql
#eg. 查询没有奖金的员工名和奖金率
SELECT
	last_name,
	commission_pct
FROM
	employees
WHERE
	commission_pct <=>  NULL;
#eg. 查询工资为12000的员工信息
SELECT
*
FROM
	employees
WHERE
	salary  <=>  12000;
```

Tips：

- IS NULL：仅仅可以判断NULL值，可读性较高，建议使用

- <=>:  既可以判断NULL，又可以判断普通的数值， 可读性较低

## 排序查询

语法：

```sql
SELECT
	查询列表
FROM
	表
(WHERE
 	筛选条件）
ORDER BY
 	排序列表
```

特点：

- ASC 代表升序，DESC代表降序，不写默认升序

- ORDER BY 子句中可以支持单个字段、多个字段、表达式、函数、别名

- ORDER BY 子句一般是放在查询语句的最后面，LIMIT子句除外

```sql
#eg.查询员工信息，要求工资从高到低排序
SELECT * FROM employees ORDER BY salary DESC;(降序排序)
SELECT * FROM employees ORDER BY salary ASC;(升序排序)
SELECT * FROM employees ORDER BY salary ;(默认为升序排序)
#eg.查询部门编号>=90的员工信息，要求按入职时间排序
SELECT 
*
FROM 
	employees
WHERE
	department_id >= 90
ORDER BY 
	hiredate ASC;
#eg.按年薪的高低显示员工信息和年薪【按别名排序】
SELECT
	*,salary*12*(1+IFNULL(commission_pct,0)) 年薪
FROM
	employees
ORDER BY 
	salary*12*(1+IFNULL(commission_pct,0)) DESC;
#eg.按姓名的长度显示员工的姓名和工资【按函数排序】
SELECT
	LENGTH(last_name) 字节长度，last_name,salary
FROM
	employees
ORDER BY
	LENGTH(last_name) DESC;
#eg.查询员工信息，要求先按工资排序，再按员工编号排序【按多个字段排序】
SELECT
	*
FROM
	employees
ORDER BY
	salary ASC，employee_id DESC;
```

## 常见函数

语法：

```sql
```



SELECT 函数名(实参列表) (from 表)

特点：1.叫什么(函数名)；2.干什么(函数功能)

分类：

1.单行函数；

功能：做处理使用

如 concat、length、ifnull等

又分为 字符函数、数学函数、日期函数、其他函数、流程控制函数

2.分组函数

功能：做统计使用、又称为统计函数、聚合函数、组函数