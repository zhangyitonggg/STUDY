# 基础语法

#### 标准输入输出流

```cpp
std::cin >> x >> y;
std::cout << y << std::endl << x;
```

#### scanf 与 printf

在大多数情况下，它们的速度比 `cin` 和 `cout` 更快，并且能够方便地控制输入输出格式

#### freopen 函数

将指定输入输出流以指定方式重定向到文件

```cpp
#include <cstdio>
#include <iostream>

int main(void) {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  /*
  中间的代码不需要改变，直接使用 cin 和 cout 即可
  */
  fclose(stdin);
  fclose(stdout);
  return 0;
}
```

#### fopen 函数

打开指定文件并返回打开文件的指针

* fread/fwrite
* fgetc/fputc
* fscanf/fprintf
* fgets/fputs

```c++
FILE *in, *out;  // 定义文件指针
in = fopen("data.in", "r");
out = fopen("data.out", "w");
/*
do what you want to dos
*/
fclose(in);
fclose(out);
```

#### 字符串 

**字符串的定义和初始化**

```c++
char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char str2[] = "World";
string str3 = "Hello";
string str4("World");
```

**字符串的操作**

* 拼接：`+`

* 比较：`==`、`!=`、`<`、`>`

* 长度：`length()` 或 `size()`

  与 `strlen` 不同

#### 指针

与 C语言 的不同：动态内存分配：

```c++
int* dynamicPtr = new int; // 动态分配一个整数大小的内存空间
*dynamicPtr = 20; // 在动态分配的内存空间中存储值
delete dynamicPtr; // 释放动态分配的内存空间
```

#### 函数

* 可重载

* 可以提供默认值

* 传引用参数：通过引用传递参数，函数内部对参数的修改将影响原始变量。调用时直接填入变量即可

  ```c++
  void increment(int& x) {
      x++;
  }
  ```

#### 结构体与联合体

与 C 不同的是，在 C++ 中，`struct` 和 `union` 定义的名称**会自动成为新的类型名称**，即它们不仅属于结构标签命名空间，同时也进入普通的类型命名空间。

## 面向对象

#### 构造函数和析构函数

* 构造函数：名称与类相同
* 析构函数：名称与类相同，但在函数名前加上 `~`

#### 访问修饰符

* `public`
* `private`
* `protected`

#### 友元函数

* **不是类的成员函数**，但可以访问类的私有和保护成员
* **在类内声明，在类外定义**。声明位置无所谓。
* 不能通过对象调用（没有 `this` 指针）

```c++
class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double len, double wid) {
        length = len;
        width = wid;
    }

    friend double calculateArea(Rectangle rect); // 也可以改成传引用
};

double calculateArea(Rectangle rect) { // 也可以改成传引用
    return rect.length * rect.width;
}

int main() {
    Rectangle rectangle(5.0, 3.0);
    double area = calculateArea(rectangle);
    cout << "矩形的面积是：" << area << endl;

    return 0;
}
```

#### 继承

**基本格式**

```c++
class 基类名 {
    // 基类成员
};

class 派生类名 : 继承方式 基类名 {
    // 派生类新增的成员
};
```

| 继承方式         | **基类 `public` 成员** | **基类 `protected` 成员** | **基类 `private` 成员** |
| ---------------- | ---------------------- | ------------------------- | ----------------------- |
| `public` 继承    | 仍然是 `public`        | 仍然是 `protected`        | 无法访问                |
| `protected` 继承 | 变成 `protected`       | 仍然是 `protected`        | 无法访问                |
| `private` 继承   | 变成 `private`         | 变成 `private`            | 无法访问                |

**继承中的构造函数和析构函数**

* 如果基类有显示定义的构造函数或析构函数，则子类在创建对象或者销毁对象时，需要显示调用基类的构造函数或析构函数
* **如果不指定，默认调用基类的默认构造函数**（如果有）

```cpp
class Base {
public:
    int x;
    Base(int val) { x = val; cout << "Base Constructor\n"; }
};
	
class Derived : public Base {
public:
    Derived(int val) : Base(val) { cout << "Derived Constructor\n"; }
};

int main() {
    Derived obj(10);
    return 0;
}
```

**Override 与 final**

* 重写：`void show() override {}`

  这里的 `override` 关键字可加可不加，主要是为了程序的可读性和防止拼写错误

* 组织进一步的重写：`void show() final {}`

**virtual**

* 允许通过基类的指针或引用调用派生类的函数版本，从而实现 **运行时多态（动态绑定）**。在没有 `virtual` 关键字的情况下，函数调用通常是 **静态绑定**，即在编译时就决定了调用哪个函数，而使用 `virtual` 后，函数调用会在运行时根据对象的实际类型决定。

* 如果基类中有虚函数，那么基类的析构函数也应该声明为虚函数

* **纯虚函数**：未实现，派生类必须重写该函数

  ```c++
  virtual void speak() = 0; 
  ```

  含有纯虚函数的类称为**抽象类**，不能直接实例化

**静态成员**

同java，略

# STL 标准模版库

## STL 容器

### 简介

#### 分类

**序列式容器**

* 向量 `vector`
* 数组 `array`
* 双端队列 `deque`
* 列表 `list`
* 单向列表 `forward_list`

**关联式容器**

* 集合 `set`
* 多重集合 `multiset`
* 映射 `map`
* 多重映射 `multimap`

**无序关联式容器**

* 无序集合 `unordered_set`
* 无序多重集合 `unordered_multiset`
* 无序映射 `unordered_map`
* 无序多重映射 `unordered_multimap`

**容器适配器**

> * 对基本容器的封装，提供了特定用途的接口，隐藏了一些底层的实现细节
> * 并非容器，不具有容器的某些特点（迭代器。`clear()`函数）

* 栈 `stack`：后进后出，对 `deque` 的封装
* 队列 `queue`：先进先出，对 `deque` 的封装
* 优先队列 `priority_queue`：元素的次序是由作用于所存储的值上的某种谓词决定的一种队列，默认是对 `vector` 的封装

#### 共同点

**容器声明**：都是 `containerName<typeName,...> name` 的形式

**共有函数**

* `=`
* `begin()`：指向开头元素的迭代器
* `end()`：返回指向末尾的下一个元素的迭代器
* `size()`
* `max_size()`
* `empty()`
* `swap()`：交换两个容器
* `clear`
* `==、!=、<、>、<=、>=`：按**字典序**比较两个容器的大小：
  * `map` 的两个元素相当于 `set<pair<key,value>>`
  * 无序容器只支持 `==` 和 `!=`

### 迭代器

#### 基础使用

* 自增 `++`：移动迭代器
* 解引用 `*`：获取或修改迭代器指向的元素

```c++
vector<int> data(10);

for (int i = 0; i < data.size(); i++)
  cout << data[i] << endl;  // 使用下标访问元素

for (vector<int>::iterator iter = data.begin(); iter != data.end(); iter++)
  cout << *iter << endl;  // 使用迭代器访问元素
// 在C++11后可以使用 auto iter = data.begin() 来简化上述代码
```

#### 分类

- InputIterator（输入迭代器）：只要求支持拷贝、自增和解引访问。
- OutputIterator（输出迭代器）：只要求支持拷贝、自增和解引赋值。
- ForwardIterator（向前迭代器）：同时满足 InputIterator 和 OutputIterator 的要求。
- BidirectionalIterator（双向迭代器）：在 ForwardIterator 的基础上支持自减（即反向访问）。
- RandomAccessIterator（随机访问迭代器）：在 BidirectionalIterator 的基础上支持加减运算和比较运算（即随机访问）。
- ContiguousIterator（连续迭代器）：在 RandomAccessIterator 的基础上要求对可解引用的迭代器 `a + n` 满足 `*(a + n)` 与 `*(std::address_of(*a) + n)` 等价（即连续存储，其中 `a` 为连续迭代器、`n` 为整型值）。
  * ContiguousIterator 于 C++17 中正式引入。

> 指针可以看作一种随机访问迭代器

#### 相关函数

* `std::advance(it, n)` 将迭代器 `it` 向后移动 `n` 步；若 `n` 为负数，则对应向前移动
* `std::next(it, n)` 获得向前迭代器 `it` 的第 `n` 个后继
* `std::prev(it, n)` 获得双向迭代器 `it` 的第 `n` 个前驱
* `begin()` 函数可以获得指向容器第一个元素的迭代器，`rbegin()` 函数可以获得指向容器最后一个元素的反向迭代器，`cbegin()` 函数可以获得指向容器第一个元素的 const 迭代器，`end()` 函数可以获得指向容器尾端（并不是最后一个元素）的迭代器

### 序列式容器——vector

**内存连续**的、**可变长度**的数组。能够提供线性复杂度的插入和删除，以及常数复杂度的随机访问

#### 构造函数

```cpp
// 1. 创建空vector：常数复杂度
vector<int> v0;
// 1+. 插入前3个元素时，保证常数时间复杂度
v0.reserve(3);
// 2. 创建有3个元素的vector,其元素的默认值是0：线性复杂度
vector<int> v1(3);
// 3. 创建有3个元素的vector,其元素的默认值是2：线性复杂度
vector<int> v2(3, 2);
// 4. 创建一个初始空间为3的vector，其元素的默认值是1，
// 并且使用v2的空间配置器: 线性复杂度
vector<int> v3(3, 1, v2.get_allocator());
// 5. 创建一个vector，其元素是v2的拷贝：线性复杂度
vector<int> v4(v2);
// 6. 创建一个v4的拷贝vector v5，其内容是{v4[1], v4[2]}: 线性复杂度
vector<int> v5(v4.begin() + 1, v4.begin() + 3);
// 7. 移动v2到新创建的vector v6，不发生拷贝：常数复杂度
vector<int> v6(move(v2));
// 8. 创建有3个元素的vector,其元素的值分别是1,2,3：线性复杂度
vector<int> v7{1, 2, 3};
```

#### 元素访问

1. `at()`：`v.at(pos)` 返回容器中下标为 `pos` 的引用。如果数组越界抛出 `std::out_of_range` 类型的异常。
2. `operator[]`：`v[pos]` 返回容器中下标为 `pos` 的引用。不执行越界检查。
3. `front()`：`v.front()` 返回首元素的引用。
4. `back()`：`v.back()` 返回末尾元素的引用。
5. `data()`：`v.data()` 返回指向数组第一个元素的指针。

#### 迭代器

1. `begin() / cbegin()`
2. `end() / cend()`
3. `rbegin() / crbegin()`
4. `rend() / crend()`

#### 长度和容量

> * 长度（size）指有效元素数量
> * 容量（capacity）指实际分配的内存长度

**与长度相关的函数**

* `empty`：返回一个 `bool` 值
* `size()`：容器长度，即 `std::distance(v.begin(), v.end())`
* `resize()`：改变长度，多退少补
* `max_size()`：返回容器的最大可能长度

**与容量相关的函数**

* `reserve()`
* `capacity()`

* `shrink_to_fit()`：使得 `vector` 的容量与长度一致

#### 元素增删改

* `clear()`

* `insert()`：复杂度与距离末尾长度成线性关系

  ```c++
  v.insert(v.begin() + 1, 99);
  ```

* `erase()`：

  ```c++
  v.erase(v.begin() + 1);  // 删除索引 1 处的元素，v = {1, 3, 4, 5}
  v.erase(v.begin() + 1, v.begin() + 3);  // 删除索引 [1,3) 范围，v = {1, 5}
  ```

* `push_back()`：在末尾插入一个元素

* `pop_back()`：删除末尾元素

* `swap()`：交换两个 `vector`，仅交换指针，不拷贝数据

  ```c++
  v1.swap(v2);
  ```

### 序列式容器——array

**内存连续**的、**固定长度**的数组数据结构。其本质是对原生数组的直接封装。

#### 构造函数

```c++
// 1. 创建空array，长度为3; 常数复杂度
std::array<int, 3> v0;
// 2. 用指定常数创建array; 常数复杂度
std::array<int, 3> v1{1, 2, 3};
```

#### 元素访问

* `at(size_t pos)`：返回指定位置的元素，带越界检查

  ```c++
  // at 若遇 pos >= size() 的情况会抛出 std::out_of_range
  std::array<int, 3> arr = {1, 2, 3};
  try {
      std::cout << arr.at(2) << std::endl;  // 正常输出
      std::cout << arr.at(5) << std::endl;  // 超出范围，抛出异常
  } catch (const std::out_of_range& e) {
      std::cout << "Exception: " << e.what() << std::endl;
  }
  ```

* `operator[]`：返回指定位置的元素，不带越界检查

* `front()`：返回数组的第一个元素

* `back()`：返回数组最后一个元素

* `data()`：返回指向数组数据的指针

#### 迭代器

同 `vector`

#### 长度

* `empty()`
* `size`
* `max_size()`：`size()` 返回的值等于 `max_size()` 返回的值

#### 用 array2 重写 array1

```c++
// 长度必须一致
array<int, 5> a1 = {1, 2, 3, 4, 5};
array<int, 5> a2 = {10, 20, 30, 40, 50};
a1 = a2;
```

#### 成员函数与非成员函数辨析

* `std::array::fill`

  ```c++
  arr.fill(99);  // 将所有元素设置为 99
  ```

* `std::fill`

  ```c++
  std::fill(arr.begin(), arr.end(), 99);
  ```

* `std::array::swap`：交换内容，复杂度是线性的

  ```c++
  arr1.swap(arr2);
  ```

* `std::swap`：交换指针，复杂度是常数的

  ```c++
  std::swap(arr1, arr2);
  ```

### 序列式容器——deque

允许在**两端**进行**插入和删除**操作的线性数据结。是一个动态数组，它提供了快速的随机访问能力，同时允许在两端进行高效的插入和删除操作。

**底层实现：**多个不连续的缓冲区，而缓冲区中的内存是连续的

#### 构造函数

```c++
// 1. 定义一个int类型的空双端队列 v0
deque<int> v0;
// 2. 定义一个int类型的双端队列 v1，并设置初始大小为10; 线性复杂度
deque<int> v1(10);
// 3. 定义一个int类型的双端队列 v2，并初始化为10个1; 线性复杂度
deque<int> v2(10, 1);
// 4. 复制已有的双端队列 v1; 线性复杂度
deque<int> v3(v1);
// 5. 创建一个v2的拷贝deque v4，其内容是v4[0]至v4[2]; 线性复杂度
deque<int> v4(v2.begin(), v2.begin() + 3);
// 6. 移动v2到新创建的deque v5，不发生拷贝; 常数复杂度; 需要 C++11
deque<int> v5(std::move(v2));
```

#### 元素访问

全部是**常数复杂度**

* `at()`：执行越界检查
* `operator[]`：不执行越界检查
* `front()`
* `back()`

#### 迭代器

同 `vector`

#### 长度

* `empty`：返回一个 `bool` 值
* `size()`：容器长度，即 `std::distance(v.begin(), v.end())`
* `resize()`：改变长度，多退少补
* `max_size()`：返回容器的最大可能长度
* `shrink_to_fit()`：尽量将容器的容量缩减到适应当前元素数量的大小，只是一个请求，不一定生效

### 序列式容器——list

双向链表数据结构，允许在容器的任意位置快速插入和删除元素。

用法与 `deque` 基本一致，但是遍历不能用类似数组下标的方法

```c++
for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
    std::cout << *it << " ";
}
```

| 函数 | 说明 |
| --------------------------- | ------------------------- |
| `push_back(const T& val)`   | 在链表末尾添加元素        |
| `push_front(const T& val)`  | 在链表头部添加元素        |
| `pop_back()`                | 删除链表末尾的元素        |
| `pop_front()`               | 删除链表头部的元素        |
| `insert(iterator pos, val)` | 在指定位置插入元素        |
| `erase(iterator pos)`       | 删除指定位置的元素        |
| `clear()`                   | 清空所有元素              |
| `size()`                    | 返回链表中的元素数量      |
| `empty()`                   | 检查链表是否为空          |
| `front()`                   | 返回链表第一个元素        |
| `back()`                    | 返回链表最后一个元素      |
| `remove(const T& val)`      | 删除所有等于指定值的元素  |
| `sort()`                    | 对链表中的元素进行排序    |
| `unique()` | 删除相邻重复元素 |
| `merge(list& other)`        | 合并另一个已排序的链表    |
| `reverse()`                 | 反转链表                  |
| `begin()` / `end()`         | 返回链表的起始/结束迭代器 |

### 序列式容器——forward_list

用法与 `list` 几乎一致，但是是单向链表。

### 关联式容器——set、multiset

通常采用**红黑树**实现。**平衡二叉树**的特性使其**搜索、移除、插入拥有对数复杂度**。

#### 插入与删除

* `insert(x)`：返回值类型为 `pair<iterator, bool>`，其中 iterator 是一个指向所插入元素（或者是指向等于所插入值的原本就在容器中的元素）的迭代器，而 bool 则代表元素是否插入成功。
* `erase(x)`：删除值为 x 的**所有**元素，返回删除元素的个数。
* `erase(pos)`：删除迭代器为 pos 的元素。
* `erase(first, last)`：删除迭代器在 $[first,last)$ 范围内的所有元素。

#### 查找

- `count(x)` 返回 `set` 内键为 x 的元素数量。
- `find(x)` 在 `set` 内存在键为 x 的元素时会返回该元素的迭代器，否则返回 `end()`。
- `lower_bound(x)` 返回指向首个**大于等于**给定键的元素的迭代器。如果不存在这样的元素，返回 `end()`。
- `upper_bound(x)` 返回指向首个**大于**给定键的元素的迭代器。如果不存在这样的元素，返回 `end()`。
- `empty()` 返回容器是否为空。
- `size()` 返回容器内元素个数。

> `lower_bound()` 和 `upper_bound()` 如果使用 `set` 自带的话，时间复杂度为 $O(log n)$；若使用 algorithm 库中的，时间复杂度为 $O(n)$。

#### 迭代器

同 `vector`

### 关联式容器——map、multimap

通常采用**红黑树**实现。**搜索、移除、插入拥有对数复杂度**

> `multimap` 没有提供给出键访问其对应值的方法。

#### 插入与删除

* `insert(pair<Key, T>)`：`mp.insert(pair<string,int>("Alan",100));`
* `operator[]`：可以通过 `key` 查找并插入元素，如果 `key` 已存在会更新其值；如果 `key` 不存在，会插入新元素。
* `erase(key)`：删除键为 `key` 的**所有**元素，返回删除的个数。
* `erase(pos)`
* `erase(first,last)`
* `clear`

#### 查询

* 通过下标访问来进行查询或修改操作：`mp["key"]=100`
* `count(key)`：$O(log(size) + ans)$
* `find()`：返回元素的迭代器，无则返回 `end()`
* `lower_bound(key)`：同 `set`
* `upper_bound(key)`：同 `set`
* `empty`
* `size`

### 关联式容器——其他

#### 遍历容器

迭代器遍历：

```c++
set<int> s;
using si = set<int>::iterator;
for (si it = s.begin(); it != s.end(); it++) cout << *it << endl;
for (auto x : s) cout << x << endl; // c++11
```

需要注意的是，对 `map` 的迭代器解引用后，得到的是类型为 `pair<Key, T>` 的键值对

#### 自定义比较方式

```c++
// 定义比较仿函数（降序排序）
struct CustomCompare {
    bool operator()(int a, int b) const {
        return a > b;  // 降序排序
    }
};

// 使用自定义比较器的 set
set<int, CustomCompare> s = {5, 2, 8, 1, 3};
for (int x : s) {
    cout << x << " ";
}

// 使用自定义比较器的 map
map<int, string, CustomCompare> m;
m[3] = "Apple";
m[1] = "Banana";
m[5] = "Cherry";
for (const auto& pair : m) {
    cout << pair.first << ": " << pair.second << endl;
}
```

### 无序关联式容器

#### 分类

##### unordered_set

##### unordered_multiset

##### unordered_map

##### unordered_multimap

#### 时间复杂度

采用哈希存储：使得无序关联式容器在平均情况下大多数操作（包括查找，插入，删除）都能在常数时间复杂度内完成，相较于关联式容器（使用红黑树实现）与容器大小成对数的时间复杂度更加优秀。

#### 自定义哈希函数

```c++
struct my_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }

  // 针对 std::pair<int, int> 作为主键类型的哈希函数
  size_t operator()(pair<uint64_t, uint64_t> x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM) ^
           (splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};

unordered_map<int, int, my_hash> my_map;
unordered_map<pair<int, int>, int, my_hash> my_pair_map;
```

### 容器适配器——栈

#### 定义

```c++
std::stack<TypeName> s;  // 使用默认底层容器 deque，数据类型为 TypeName
std::stack<TypeName, Container> s;  // 使用 Container 作为底层容器
std::stack<TypeName> s2(s1);        // 将 s1 复制一份用于构造 s2
```

#### 成员函数

- `top()` 访问栈顶元素（如果栈为空，此处会出错）
- `push(x)` 向栈中插入元素 x
- `pop()` 删除栈顶元素
- `size()` 查询容器中的元素数量
- `empty()` 询问容器是否为空

### 容器适配器——队列

#### 定义

```c++
std::queue<TypeName> q;  // 使用默认底层容器 deque，数据类型为 TypeName
std::queue<TypeName, Container> q;  // 使用 Container 作为底层容器
std::queue<TypeName> q2(q1);  // 将 s1 复制一份用于构造 q2
```

#### 成员函数

- `front()` 访问队首元素（如果队列为空，此处会出错）
- `push(x)` 向队列中插入元素 x
- `pop()` 删除队首元素
- `size()` 查询容器中的元素数量
- `empty()` 询问容器是否为空

### 容器适配器——优先队列

#### 定义

```c++
std::priority_queue<TypeName> q;             // 数据类型为 TypeName
std::priority_queue<TypeName, Container> q;  // 使用 Container 作为底层容器
std::priority_queue<TypeName, Container, Compare> q;
// 使用 Container 作为底层容器，使用 Compare 作为比较类型

// 默认使用底层容器 vector
// 比较类型 less<TypeName>（此时为它的 top() 返回为最大值）
// 若希望 top() 返回最小值，可令比较类型为 greater<TypeName>
// 注意：不可跳过 Container 直接传入 Compare

// 从 C++11 开始，如果使用 lambda 函数自定义 Compare
// 则需要将其作为构造函数的参数代入，如：
auto cmp = [](const std::pair<int, int> &l, const std::pair<int, int> &r) {
  return l.second < r.second;
};
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    decltype(cmp)>
    pq(cmp);
```

#### 成员函数

**以下所有函数均为常数复杂度**

- `top()` 访问堆顶元素（此时优先队列不能为空）
- `empty()` 询问容器是否为空
- `size()` 查询容器中的元素数量

**以下所有函数均为对数复杂度**

- `push(x)` 插入元素，并对底层容器排序
- `pop()` 删除堆顶元素（此时优先队列不能为空）

## STL 算法

- `find`：顺序查找。`find(v.begin(), v.end(), value)`，其中 `value` 为需要查找的值。
- `reverse`：翻转数组、字符串。`reverse(v.begin(), v.end())` 或 `reverse(a + begin, a + end)`。
- `unique`：去除容器中相邻的重复元素。`unique(ForwardIterator first, ForwardIterator last)`，返回值为指向 **去重后** 容器结尾的迭代器，原容器大小不变。与 `sort` 结合使用可以实现完整容器去重。
- `random_shuffle`：随机地打乱数组。`random_shuffle(v.begin(), v.end())` 或 `random_shuffle(v + begin, v + end)`。

- `sort`：排序。`sort(v.begin(), v.end(), cmp)` 或 `sort(a + begin, a + end, cmp)`，其中 `end` 是排序的数组最后一个元素的后一位，`cmp` 为自定义的比较函数。
- `stable_sort`：稳定排序，用法同 `sort()`。
- `nth_element`：按指定范围进行分类，即找出序列中第 $n$ 大的元素，使其左边均为小于它的数，右边均为大于它的数。`nth_element(v.begin(), v.begin() + n, v.end(), cmp)` 或 `nth_element(a + begin, a + begin + n, a + end, cmp)`。

- `binary_search`：二分查找。`binary_search(v.begin(), v.end(), value)`，其中 `value` 为需要查找的值。
- `merge`：将两个（已排序的）序列 **有序合并** 到第三个序列的 **插入迭代器** 上。`merge(v1.begin(), v1.end(), v2.begin(), v2.end() ,back_inserter(v3))`。

- `inplace_merge`：将两个（已按小于运算符排序的）：`[first,middle), [middle,last)` 范围 **原地合并为一个有序序列**。`inplace_merge(v.begin(), v.begin() + middle, v.end())`。

- `lower_bound`：在一个有序序列中进行二分查找，返回指向第一个 **大于等于** $x$ 的元素的位置的迭代器。如果不存在这样的元素，则返回尾迭代器。`lower_bound(v.begin(),v.end(),x)`。
- `upper_bound`：在一个有序序列中进行二分查找，返回指向第一个 **大于** $x$ 的元素的位置的迭代器。如果不存在这样的元素，则返回尾迭代器。`upper_bound(v.begin(),v.end(),x)`。

- `next_permutation`：将当前排列更改为 **全排列中的下一个排列**。如果当前排列已经是 **全排列中的最后一个排列**（元素完全从大到小排列），函数返回 `false` 并将排列更改为 **全排列中的第一个排列**（元素完全从小到大排列）；否则，函数返回 `true`。`next_permutation(v.begin(), v.end())` 或 `next_permutation(v + begin, v + end)`。
- `prev_permutation`：将当前排列更改为 **全排列中的上一个排列**。用法同 `next_permutation`。
- `partial_sum`：求前缀和。`partial_sum(src.begin(), src.end(), back_inserter(dst))`。

## bitset

### 指定大小

```c++
std::bitset<1000> bs;  // a bitset with 1000 bits
```

#### 构造函数

- `bitset()`: 每一位都是 `false`。

- `bitset(unsigned long val)`: 设为 `val` 的二进制形式。

- `bitset(const string& str)`: 设为 ![01](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 串 `str`。

  ```c++
  // 定义一个二进制字符串
  std::string str = "101010";
  
  // 使用字符串初始化 bitset
  // 注意：bitset 的大小需要足够大以容纳字符串的长度
  std::bitset<8> bits(str); // 这里假设 bitset 的大小为 8
  ```

### 运算符

- `operator []`: 访问其特定的一位。

- `operator ==`/`operator !=`: 比较两个 `bitset` 内容是否完全一样。

- `operator &`/`operator &=`/`operator |`/`operator |=`/`operator ^`/`operator ^=`/`operator ~`: 进行按位与/或/异或/取反操作。

  注意：**`bitset` 只能与 `bitset` 进行位运算**，若要和整型进行位运算，要先将整型转换为 `bitset`。

- `operator <<`/`operator >>`/`operator <<=`/`operator >>=`: 进行二进制左移/右移。

### 成员函数

- `count()`: 返回 `true` 的数量。
- `size()`: 返回 `bitset` 的大小。
- `test(pos)`: 它和 `vector` 中的 `at()` 的作用是一样的，和 `[]` 运算符的区别就是越界检查。
- `any()`: 若存在某一位是 `true` 则返回 `true`，否则返回 `false`。
- `none()`: 若所有位都是 `false` 则返回 `true`，否则返回 `false`。
- `all()`: 若所有位都是 `true` 则返回 `true`，否则返回 `false`。
- 1. `set()`: 将整个 `bitset` 设置成 `true`。
  2. `set(pos, val = true)`: 将某一位设置成 `true`/`false`。
- 1. `reset()`: 将整个 `bitset` 设置成 `false`。
  2. `reset(pos)`: 将某一位设置成 `false`。相当于 `set(pos, false)`。
- 1. `flip()`: 翻转每一位。（![0\leftrightarrow1](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)，相当于异或一个全是 ![1](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 的 `bitset`）
  2. `flip(pos)`: 翻转某一位。
- `to_string()`: 返回转换成的字符串表达。
- `to_ulong()`: 返回转换成的 `unsigned long` 表达（`long` 在 NT 及 32 位 POSIX 系统下与 `int` 一样，在 64 位 POSIX 下与 `long long` 一样）。
- `to_ullong()`:（**C++11** 起）返回转换成的 `unsigned long long` 表达。

另外，libstdc++ 中有一些较为实用的内部成员函数：

- `_Find_first()`: 返回 `bitset` 第一个 `true` 的下标，若没有 `true` 则返回 `bitset` 的大小。
- `_Find_next(pos)`: 返回 `pos` 后面（下标严格大于 `pos` 的位置）第一个 `true` 的下标，若 `pos` 后面没有 `true` 则返回 `bitset` 的大小。

## string

### 声明

```c++
std::string s;
```

### 转 char 数组

* `s.data()`：不保证末尾有空字符
* `s.c_str()`：保证末尾有空字符

### 获取长度

* `s.size()`
* `s.length()`
* `strlen(s.c_str())`

### 寻找某字符（串）第一次出现的位置

`find(str,pos)` 函数可以用来查找字符串中一个字符/字符串在 `pos`（含）之后第一次出现的位置（若不传参给 `pos` 则默认为 `0`）。如果没有出现，则返回 `string::npos`（被定义为 `-1`，但类型仍为 `size_t`/`unsigned long`）。

### 截取子串

`substr(pos, len)` 函数的参数返回从 `pos` 位置开始截取最多 `len` 个字符组成的字符串。

### 插入/删除

* `insert(index,count,ch)` 和 `insert(index,str)` 是比较常见的插入函数。它们分别表示在 `index` 处连续插入 `count` 次字符串 `ch` 和插入字符串 `str`。

* `erase(index,count)` 函数将字符串 `index` 位置开始（含）的 `count` 个字符删除（若不传参给 `count` 则表示删去 `index` 位置及以后的所有字符）。

### 替换

`replace(pos,count,str)` 和 `replace(first,last,str)` 是比较常见的替换函数。它们分别表示将从 `pos` 位置开始 `count` 个字符的子串替换为 `str` 以及将以 `first` 开始（含）、`last` 结束（不含）的子串替换为 `str`，其中 `first` 和 `last` 均为迭代器。

## pair

### 初始化

```c++
pair<int, double> p0(1, 2.0);
```

```c++
pair<int, double> p1;
p1.first = 1;
p1.second = 2.0;
```

```c++
pair<int, double> p2 = make_pair(1, 2.0);
```

```c++
auto p3 = make_pair(1, 2.0);
```

### 访问

通过成员函数 `first` 与 `second`，可以访问 `pair` 中包含的两个变量。

```c++
p1.first++; // 值会改变
```

### 比较

`<`、`>`、`<=`、`>=`、`==`、`!=`

### 赋值与交换

```c++
p0 = p1;
```

```c++
swap(p0, p1);
p2.swap(p3);
```

# 刷题

## 洛谷