## 练习9.1
> 对于下面的程序任务，vector、deque 和 list 哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
> (a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
> (b) 读取未知数量的单词，总是将新单词插入到末尾。删除操作在头部进行。
> (c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。

(a) 按字典序意味着要在容器内部频繁进行插入操作，`vector`在尾部以外的位置插入很慢，`deque`在头尾以外的位置插入很慢，因此`list` 更合适。当然如果不是必须边读取单词边维持字典序，可以使用`vector`将读取的单词追加到队尾，读取完后进行排序。  
(b) 由于要在头尾进行插入和删除操作，`deque`和`list`都能满足，如果还需要进行随机访问那么`deque`更好。  
(c) 由于整数占空间很小，且不需要在头部进行插入删除操作，使用`vector`更合适。  

## 练习9.2
> 定义一个 list 对象，其元素类型是 int 的 deque。
```cpp
list<deque<int>> li;
```

## 练习9.3
> 构成迭代器范围的迭代器有何限制？

满足以下条件的两个迭代器 `begin` 和 `end`构成一个迭代器范围：
1. 它们指向同一个容器中的元素，或者是容器最后一个元素之后的位置。
2. 我们可以通过反复递增`begin`来到达`end`。换句话说，`end`不在`begin`之前。

## [练习9.4](ex09_04.cpp)
> 编写函数，接受一对指向 vector< int > 的迭代器和一个 int 值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。

## [练习9.5](ex09_05.cpp)
> 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

## 练习9.6

> 下面的程序有何错误？你应该如何修改它？
```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
					iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```
`list`不支持`<`运算，应改为：
```cpp
while (iter1 != iter2)
```

## 练习9.7
> 为了索引 int 的 vector 中的元素，应该使用什么类型？

可以使用下标或者迭代器索引`vector`。  
```cpp
vector<int>::size_type
vector<int>::iterator
```

## 练习9.8
> 为了读取 string 的 list 中的元素，应该使用什么类型？如果写入 list，又应该使用什么类型？

读取时应该使用`list<string>::const_iterator`，写入时应该使用`list<string>::iterator`。  

## 练习9.9
> begin 和 cbegin 两个函数有什么不同？

`cbegin` 返回`const_iterator`迭代器，可以读取元素但不能修改。  
`begin`是被重载过的，有两个版本，一个是`const`成员函数，返回`const_iterator`类型的迭代器，当对常量对象调用`begin`时会选择这个版本。  
另一个重载版本是非常量成员函数，它返回`iterator`类型迭代器。  

## 练习9.10
> 下面 4 个对象分别是什么类型？
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```
`auto it1 = v1.begin(), it2 = v2.begin();`无法通过编译，因为一条声明语句只能有一个基本数据类型，所以该语句中所有变量的初始基本数据类型必须相同。在该语句中，`it1`推断出的是`vector<int>::iterator`类型，`it2`推断出的是`vector<int>::const_iterator`，基本数据类型不同。应改为：  
```cpp
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```
其中`it1` 是`vector<int>::iterator`类型；`it2`、`it3` 和 `it4` 是 `vector<int>::const_iterator`类型。  


## 练习9.11
> 对 6 种创建和初始化 vector 对象的方法，每一种都给出一个实例。解释每个 vector 包含什么值。
```cpp
vector<int> ivec1;
vector<int> ivec2 = { 1,2,3,4,5 };
vector<int> ivec3(ivec2);
vector<int> ivec4(ivec3.begin()+2, ivec3.end());
vector<int> ivec5(5);
vector<int> ivec6(5, 10);
```
`ivec1`中为空。  
`ivec2`采用列表初始化，包含`5`个元素，分别是`1,2,3,4,5`。  
`ivec3`初始化为`ivec2`的拷贝，它也包含`5`个元素，分别是`1,2,3,4,5`。  
`ivec4`初始化为迭代器返回中的元素的拷贝，它包括`3`个元素，分别是`3,4,5`。  
`ivec5`包含`5`个元素，对元素进行了值初始化，因此元素值都为`0`。  
`ivec6`包含`5`个元素，元素值都为`10`。  

## 练习9.12
> 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

接受一个容器创建其拷贝的构造函数，要求两个容器的容器类型与元素类型都相同，会拷贝容器中的所有元素。    
接受两个迭代器创建拷贝的构造函数，只需要迭代器范围内元素能够转换为容器中的元素类型，它们的容器类型和元素类型都可以不同。  

## [练习9.13](ex09_13.cpp)
> 如何从一个 list< int > 初始化一个 vector< double > ？从一个 vector< int > 又该如何创建？编写代码验证你的答案。

由于元素类型都不相同，但是`int`可以转换为`double`，因此采用接受两个迭代器创建拷贝的构造函数即可。  

## 练习9.14
> 编写程序，将一个 list 中的 char * 指针（指向C风格字符串）元素赋值给一个 vector 中的 string。
```cpp
vector<string> svec;
list<const char*> clist{ "aa","bb","cc" };
svec.assign(clist.begin(), clist.end());
```

## [练习9.15](ex09_15.cpp)
> 编写程序，判定两个 vector< int > 是否相等。

## [练习9.16](ex09_16.cpp)
> 重写上一题的程序，比较一个 list< int > 中的元素和一个 vector< int > 中的元素。

## 练习9.17

> 假定c1 和 c2 是两个容器，下面的比较操作有何限制（如果有的话）？
```cpp
	if (c1 < c2)
```
`c1`和`c2`的容器类型和元素类型都必须相同。  
`c1`和`c2`中的元素类型必须支持`<`运算符。  

## [练习9.18](ex09_18.cpp)
> 编写程序，从标准输入读取 string 序列，存入一个 deque 中。编写一个循环，用迭代器打印 deque 中的元素。

## [练习9.19](ex09_19.cpp)
> 重写上题的程序，用 list 替代 deque。列出程序要做出哪些改变。

只需要将`deque`换成`list`。  

## [练习9.20](ex09_20.cpp)
> 编写程序，从一个 list< int > 拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，而奇数值元素都拷贝到另一个 deque 中。

## 练习9.21
> 如果我们将第308页中使用 insert 返回值将元素添加到 list 中的循环程序改写为将元素插入到 vector 中，分析循环将如何工作。

和`list`版本的过程和结果没有区别，首先在`vector`的第一个元素之前插入新元素，同时`insert`返回指向新插入元素（现在是第一个）的迭代器，循环不断重复这一过程，每次都是在第一个元素之前插入新元素。  
唯一要注意的是`vector`在首元素之前插入新元素会需要移动所有现有元素，这导致性能很差，而`list`不存在这个问题。  

## 练习9.22
> 假定 iv 是一个 int 的 vector，下面的程序存在什么错误？你将如何修改？
```cpp
vector<int>::iterator iter = iv.begin(),
					  mid = iv.begin() + iv.size() / 2;
while (iter != mid)
	if (*iter == some_val)
		iv.insert(iter, 2 * some_val);
```
程序的目的是检查`vector`中的前一半元素，如果这些元素等于某个值，就在元素前面插入该值的两倍。  
程序的问题是`iter`没有向`mid`推进，同时在进行`insert`操作后`iter`和`mid`迭代器都失效了。  
1. 要使`iter`向`mid`推进，只需在循环最后递增`iter`。  
2. 要使`iter`有效且仍指向当前元素，只需要将`insert`的返回值（指向新插入即当前元素前一个元素的迭代器）赋给`iter`，为了使其指向当前元素，再次递增`iter`。  
3. 要使`mid`有效且一直指向定义`mid`时的元素，只需要在`insert`操作之前，记录当前元素迭代器和`mid`元素迭代器之间的距离，之后令插入后有效的`iter`迭代器加上该距离。  
```cpp
vector<int>::iterator iter = iv.begin(),
					  mid = iv.begin() + iv.size() / 2;
while (iter != mid) {
	if (*iter == some_val) {
		auto diff_mid = mid - iter;
		iter = iv.insert(iter, 2 * some_val);
		++iter;
		mid = iter + diff_mid;
	}
	++iter;
}
```

## 练习9.23
> 在本节第一个程序（第 309 页）中，若 c.size() 为1，则 val、val2、val3 和 val4 的值会是什么？

所有值都一样，都等于容器中唯一一个元素的值。  

## [练习9.24](ex09_24.cpp)
> 编写程序，分别使用 at、下标运算符、front 和 begin 提取一个 vector 中的第一个元素。在一个空 vector 上测试你的程序。

## 练习9.25
> 对于第 312 页中删除一个范围内的元素的程序，如果 elem1 与 elem2 相等会发生什么？如果 elem2 是尾后迭代器，或者 elem1 和 elem2 皆为尾后迭代器，又会发生什么？

`erase(b,e)`操作，删除迭代器范围内的元素，同时返回第二个参数所指向位置的迭代器。  
如果`elem1`和`elem2`相等，迭代器范围为空，什么也没有删除，返回`elem2`。  
如果`elem2`是尾后迭代器，删除从`elem1`到容器最后的元素，返回尾后迭代器。  
如果`elem1`和`elem2`都是尾后迭代器，什么也没有删除，返回`elem2`。  

## [练习9.26](ex09_26.cpp)
> 使用下面代码定义的 ia，将 ia 拷贝到一个 vector 和一个 list 中。使用单迭代器版本的 erase 从 list 中删除奇数元素，从 vector 中删除偶数元素。
```cpp
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```

## [练习9.27](ex09_27.cpp)
> 编写程序，查找并删除 forward_list< int > 中的奇数元素。

## [练习9.28](ex09_28.cpp)
> 编写函数，接受一个 forward_list< string > 和两个 string 共三个参数。函数应在链表中查找第一个 string，并将第二个 string 插入到紧接着第一个 string 之后的位置。若第一个 string 未在链表中，则将第二个 string 插入到链表末尾。

## 练习9.29
> 假定 vec 包含 25 个元素，那么 vec.resize(100) 会做什么？如果接下来调用 vec.resize(10) 会做什么？

`vec.resize(100)`将在容器末尾添加`75`个元素，这些元素进行值初始化。  
`vec.resize(10)`将删除容器末尾`90`个元素。  

## 练习9.30
> 接受单个参数的 resize 版本对元素类型有什么限制（如果有的话）？

如果元素类型是类类型，单参数版本`resize`要求该类型必须提供一个默认构造函数。  

## [练习9.31](ex09_31)
> 第 316 页中删除偶数值元素并复制奇数值元素的程序不能用于 list 或 forward_list。为什么？修改程序，使之也能用于这些类型。

因为`list`和`forward_list`不支持迭代器算术运算，`iter += 2`是无效的。另外`forward_list`不支持`insert`和`erase`，它有自己专门的插入与删除操作。  
对于`list`，只需将迭代器算术运算`iter += 2`换成两条迭代器递增语句。  
对于`forward_list`，应该维护一个当前元素的前驱迭代器以便于插入和删除。  

## 练习9.32
> 在第 316 页的程序中，向下面语句这样调用 insert 是否合法？如果不合法，为什么？
```cpp
iter = vi.insert(iter, *iter++);
```
对函数参数的求值与传递顺序是未定义的。  

## [练习9.33](ex09_33.cpp)
> 在本节最后一个例子中，如果不将 insert 的结果赋予 begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

向`vector`插入元素后，`begin`将会失效。  

## [练习9.34](ex09_34.cpp)
> 假定 vi 是一个保存 int 的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
```cpp
iter = vi.begin();
while (iter != vi.end())
	if (*iter % 2)
		iter = vi.insert(iter, *iter);
	++iter;
```
程序的本意是复制奇数值。  
当遇到第一个奇数后，`iter`指向了新插入的元素，接着`++iter`使迭代器又指向了第一个奇数，程序陷入死循环。  
`cout << (iter - vi.begin()) << " "<< (vi.end() - iter) << endl;`  
将这条输出语句放在循环末尾，运行程序可以看出，迭代器距首元素迭代器的距离在不断增长，但迭代器距尾后迭代器的距离一直不变。    
修改时应该在`if`语句后面加入迭代器递增语句，从而使`iter`指向之前遇见的奇数的下一个元素。  

## 练习9.35
> 解释一个 vector 的 capacity 和 size 有何区别。

`capacity`返回的是在不分配新的内存空间的前提下最多可以保存多少元素。  
`size`返回的是容器已经保存的元素数目。  

## 练习9.36
> 一个容器的 capacity 可能小于它的 size 吗？

不可能。

## 练习9.37
> 为什么 list 或 array 没有 capacity 成员函数？

`list`是链表，它的元素在内存空间中不是连续存储的，而是在各个不同位置的，每当有新元素插入，就会从空闲内存中任意一个地方分配所需的空间，因此`capacity`没有意义。  
`array`是固定大小的数组，它不会分配新的内存空间，因此`capacity`也是没有意义的。  

## [练习9.38](exercise9_38.cpp)
> 编写程序，探究在你的标准库实现中，vector 是如何增长的。
```
capacity: 0 size: 0
capacity: 1 size: 1
capacity: 2 size: 2
capacity: 3 size: 3
capacity: 4 size: 4
capacity: 6 size: 5
capacity: 9 size: 7
capacity: 13 size: 10
capacity: 19 size: 14
capacity: 28 size: 20
capacity: 42 size: 29
```
可以看出新分配的`capacity`是之前的`1.5`倍。  

## 练习9.39
> 解释下面程序片段做了什么：
```cpp
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
	svec.push_back(word);
svec.resize(svec.size() + svec.size() / 2);
```
`reserve`为`svec`分配了`1024`个字符串空间，此时`capacity = 1024, size = 0`。  
`while`循环读取了不定量的字符串`word`并添加到`svec`里，如果读入字符串多于`1024`则会分配更大的内存空间并将容器内的元素移动到新内存空间，少于则不会分配与移动。  
`resize`向`svec`后面添加了读入字符串一半数量的空串，如果超过`capacity`则会重新分配空间并移动元素。  

## 练习9.40
> 如果上一题的程序读入了 256 个词，在 resize 之后容器的 capacity 可能是多少？如果读入了 512 个、1000 个、或 1048 个呢？

- 读入`256`个词后，`resize`会添加`128`个空串，此时`size = 384`，`capacity`仍然是`1024`。  
- 读入`512`个词后，`resize`会添加`256`个空串，此时`size = 768`，`capacity`仍然是`1024`。  
- 读入`1000`个词后，`resize`会添加`500`个空串，此时`size = 1500`，超过了原有的`capacity = 1024`，会重新分配空间，新分配的大小取决于标准库实现，以`练习9.38`中测试得到的`1.5`倍增长策略为例，此时`capacity = 1536`。  
- 读入`1048`个词后，`resize`会添加`524`个空串，此时`size = 1572`，超过了原有的`capacity = 1024`，会重新分配空间，新分配的大小取决于标准库实现，以`练习9.38`中测试得到的`1.5`倍增长策略为例，此时`capacity = 2304`。  

## [练习9.41](ex09_41.cpp)
> 编写程序，从一个 vector< char > 初始化一个string。

## 练习9.42
> 假定你希望每次读取一个字符存入一个 string 中，而且知道最少需要读取 100 个字符，应该如何提高程序的性能？

使用 `reserve(100)` 预先为`100`个字符分配空间。在读取时使用`push_back`函数将字符添加到字符串末尾。  

## [练习9.43](ex09_43.cpp)
> 编写一个函数，接受三个 string 参数 s、oldVal 和 newVal。使用迭代器及 insert 和 erase 函数将 s 中所有 oldVal 替换为 newVal。测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though",将"thru"替换为"through"。

## [练习9.44](ex09_44.cpp)
> 重写上一题的函数，这次使用一个下标和 replace。

## [练习9.45](ex09_45.cpp)
> 编写一个函数，接受一个表示名字的 string 参数和两个分别表示前缀（如"Mr."或"Mrs."）和后缀（如"Jr."或"III"）的字符串。使用迭代器及 insert 和 append 函数将前缀和后缀添加到给定的名字中，将生成的新 string 返回。

## [练习9.46](ex09_46.cpp)
> 重写上一题的函数，这次使用位置和长度来管理 string，并只使用 insert。

## [练习9.47](ex09_47)
> 编写程序，首先查找 string "ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用 find_first_of，第二个要使用 find_first_not_of。

## 练习9.48
> 假定 name 和 numbers 的定义如 325 页所示，numbers.find(name) 返回什么？

`find`将字符串作为一个整体查找，会返回 `string::npos`

## [练习9.49](ex09_49/ex09_49.cpp)
> 如果一个字母延伸到中线之上，如 d 或 f，则称其有上出头部分（ascender）。如果一个字母延伸到中线之下，如 p 或 g，则称其有下出头部分（descender）。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。

## [练习9.50](ex09_50)
> 编写程序处理一个 vector< string >，其元素都表示整型值。计算 vector 中所有元素之和。修改程序，使之计算表示浮点值的 string 之和。

## [练习9.51](ex09_51.cpp)
> 设计一个类，它有三个 unsigned 成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的 string 参数。你的构造函数应该能处理不同的数据格式，如 January 1,1900、1/1/1990、Jan 1 1900 等。

## [练习9.52](ex09_52.cpp)
> 使用 stack 处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从 stack 中 pop 对象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push 到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。