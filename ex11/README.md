## 练习11.1
> 描述 map 和 vector 的不同。

`map` 是关联容器，它是关键字-值对的集合，支持高效的关键字查找和访问。它的下标不必是整数，是通过关键字而非位置来查找特定的值。当使用某个不在容器里的关键字进行下标操作时，会自动以该关键字创建新元素。    
 `vector` 是顺序容器。每个元素有唯一的位置编号，下标操作必须是整数，当使用某个不存在的位置编号进行下标操作，会出现未定义的错误。  

## 练习11.2
> 分别给出最适合使用 list、vector、deque、map 以及 set 的例子。

`list`：元素较大，需要频繁在容器中间位置插入删除。  
`vector`：元素较小，只需要频繁在末尾插入或删除元素。  
`deque`：元素较小，只需要频繁在头尾插入或删除元素。  
`map`：按元素的某个特征访问元素值，例如电话簿中根据名字访问电话，字典中根据单词访问释义。  
`set`：保存满足或不满足某种要求的值的集合。  

## [练习11.3](ex11_03.cpp)
> 编写你自己的单词计数程序。

## [练习11.4](ex11_04.cpp)
> 扩展你的程序，忽略大小写和标点。例如，"example."、"example,"和"Example"应该递增相同的计数器。

## 练习11.5
> 解释 map 和 set 的区别。你如何选择使用哪个？

`map`保存的是`<关键字，值>`，当需要查找给定关键字对应的值时应该使用`map`。    
`set` 是关键字的集合，当只需判断给定关键字是否存在时应该使用`set`。  

## 练习11.6
> 解释 set 和 list 的区别。你如何选择使用哪个？

两者都可以保存元素的集合。  
如果需要按顺序（位置）访问元素，应该使用`list`。  
如果需要快速判断是否有元素等于给定值，应该使用`set`。  

## [练习11.7](ex11_07.cpp)
> 定义一个 map，关键字是家庭的姓，值是一个 vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

## [练习11.8](ex11_08.cpp)
> 编写一个程序，在一个 vector 而不是一个 set 中保存不重复的单词。使用 set 的优点是什么？

1. 使用`set`不必自己编写检查容器中是否存在重复的代码，而是由`set`类在添加元素时自动检查。  
2. `set`中的检查重复的效率要高于标准库算法`find`，前者和其底层数据结构有关，后者只能按照顺序逐一查找。  

## 练习11.9
> 定义一个 map，将单词与一个行号的 list 关联，list 中保存的是单词所出现的行号。
```cpp
map<string, list<size_t>> lineno;
```

## 练习11.10
> 可以定义一个 vector< int >::iterator 到 int 的 map 吗？list< int >::iterator 到 int 的 map 呢？对于两种情况，如果不能，解释为什么。

`map`要求关键字类型必须支持比较操作`<`。  
`vector`上的迭代器是随机访问迭代器，它支持比较操作，因此可以定义。  
`list`上的迭代器是双向迭代器，它不支持比较操作，因此不能定义。  

## 练习11.11
> 不使用 decltype 重新定义 bookstore。
```cpp
multiset<Sales_data, bool(*)(const Sales_data &, const Sales_data &)> bookStore(compareIsbn);
```

## [练习11.12](ex11_12.cpp)
> 编写程序，读入 string 和 int 的序列，将每个 string 和 int 存入一个 pair 中，pair 保存在一个 vector 中。

## [练习11.13](ex11_13)
> 在上一题的程序中，至少有三种创建 pair 的方法。编写此程序的三个版本，分别采用不同的方法创建 pair。解释你认为哪种形式最易于编写和理解，为什么？
```cpp
vec.push_back(make_pair(s,i));
vec.push_back({s,i});
vec.push_back(pair<string, int>(s,i)); 
```
列表初始化的形式最简洁易懂。  

## [练习11.14](ex11_14.cpp)
> 扩展你在 11.2.1 节练习（第 378 页）中编写的孩子姓达到名的 map，添加一个 pair 的 vector，保存孩子的名和生日。

## 练习11.15
> 对一个 int 到 vector< int > 的 map，其 mapped_type、key_type 和 value_type 分别是什么？

`mapped_type`：`vector<int>`  
`key_type`：`int`
`value_type`：`pair<const int, vector<int>>`

## 练习11.16
> 使用一个 map 迭代器编写一个表达式，将一个值赋予一个元素。
```cpp
map<int, int> m;
auto it = m.begin();
it->second = 2019;
```

## 练习11.17
> 假定 c 是一个 string 的 multiset，v 是一个 string 的 vector，解释下面的调用。指出每个调用是否合法：
```cpp
copy(v.begin(), v.end(), inserter(c, c.end()));
copy(v.begin(), v.end(), back_inserter(c));
copy(c.begin(), c.end(), inserter(v, v.end()));
copy(c.begin(), c.end(), back_inserter(v));
```
第一行合法，`inserter`迭代器通过`insert`插入元素，`multiset`有`insert`成员函数。  
第二行不合法，`back_inserter`通过`push_back`插入元素，`multiset`没有`push_back`成员函数。  
第三行合法，`vector`有`insert`成员函数。  
第四行合法，`vector`有`push_back`成员函数。  

## 练习11.18
> 写出第 382 页循环中 map_it 的类型，不要使用 auto 或 decltype。
```cpp
map<string, size_t>::const_iterator
```

## 练习11.19
> 定义一个变量，通过对 11.2.2 节（第 378 页）中的名为 bookstore 的 multiset 调用 begin() 来初始化这个变量。写出变量的类型，不要使用 auto 或 decltype。
```cpp
multiset<Sales_data, bool(*)(const Sales_data &, const Sales_data &)>::iterator
```

## [练习11.20](ex11_20.cpp)
> 重写11.1节练习（第 376 页）的单词计数程序，使用 insert 代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。

使用`insert`需要自己构造一个`pair`，将其插入容器，返回的是一个迭代器和表示插入是否成功的布尔值的`pair`，接着又需要根据插入是否成功，来递增迭代器所指向的元素（也是一个`pair`）的`second`成员，所有操作都是程序员负责的。  
而使用下标操作时，若关键字已存在则获取已有元素的值，若不存在则自动将一个`pair`插入容器然后获取其值，相关处理是由下标运算符自动处理的，程序员无须关心。  
显然下标操作更容易编写和阅读。  

## 练习11.21
> 假定 word_count 是一个 string 到 size_t 的 map，word 是一个 string，解释下面循环的作用：
```cpp
while (cin >> word)
	++word_count.insert({word, 0}).first->second;
```
根据运算符优先级与结合律，第二行等价于
```cpp
++(((word_count.insert({word, 0})).first)->second);
```
`word_count.insert({word, 0})`将构造的`pair<string,size_t>(word, 0)`添加到`word_count`里。  
`insert`函数返回一个`pair<map<string,size_t>::iterator,bool>`，它的`first`成员是一个迭代器，`second`成员表示添加是否成功，若成功`first`成员的迭代器指向新添加的元素，若不成功`first`成员的迭代器指向已存在的元素。  
无论添加成功与否，`.first`都是一个指向关键字为`word`的元素的迭代器，元素是一个`pair<string,size_t>`。  
`->second`解引用并获取到`size_t`值。  
`++`运算符递增刚才获取到的`size_t`值。  

## 练习11.22

> 给定一个 map<string, vector< int >>，对此容器的插入一个元素的 insert 版本，写出其参数类型和返回类型。

参数类型：`pair<string, vector<int>>`
返回类型：`pair<map<string, vector<int>>::iterator,bool>`

## [练习11.23](ex11_23.cpp)
> 11.2.1节练习（第 378 页）中的 map 以孩子的姓为关键字，保存他们的名的 vector，用 multimap 重写此 map。  

## 练习11.24
> 下面的程序完成什么功能？
```cpp
map<int, int> m;
m[0] = 1;
```
若`m`中已有关键字`0`，下标操作提取出其值，赋值语句将值置为`1`。  
若`m`中没有关键字`0`，下标操作会创建一个`pair(0,0)`插入到`m`中，然后提取其值，赋值语句将值置为`1`。  

## 练习11.25
> 对比下面的程序与上一题程序
```cpp
vector<int> v;
v[0] = 1;
```
`map`中下标运算符的参数`0`表示关键字`0`，`vector`中下标运算符的参数`0`表示位置`0`。  
若`v`中有一个或以上的元素，下标操作将提取出位置为`0`的元素，赋值语句将值置为`1`。  
若`v`为空，下标操作是非法的。  

## 练习11.26
> 可以用什么类型来对一个 map 进行下标操作？下标运算符返回的类型是什么？请给出一个具体例子——即，定义一个 map，然后写出一个可以用来对 map 进行下标操作的类型以及下标运算符将会返回的类型。

可以使用`map`的`key_type`类型进行下标操作。  
下标运算符返回`map`的`mapped_type`类型。  
以`map<string,size_t>`为例，它可以使用`string`类型进行下标操作，返回的则是`size_t`类型。  

## 练习11.27
> 对于什么问题你会使用 count 来解决？什么时候你又会选择 find 呢？

`count`统计关键字出现的次数，`find`查找关键字在容器中出现的位置。  
对于允许重复关键字的容器，当希望知道容器中有多少元素的关键字与给定关键字相同时，应该用`count`。  
如果只需要知道关键字是否在容器中，又或者需要获取到具有给定关键字的元素时，使用`find`。  

## 练习11.28
> 对一个 string 到 int 的 vector 的 map，定义并初始化一个变量来保存在其上调用 find 所返回的结果。
```cpp
map<string, vector<int>>::iterator it;
```

## 练习11.29
> 如果给定的关键字不在容器中，upper_bound、lower_bound 和 equal_range 分别会返回什么？

`upper_bound`和`lower_bound`返回相同的迭代器，指向给定关键字的插入点，一个能保持容器中的元素顺序的插入位置。  
`equal_range`返回一个`pair`，其`first`成员等价于`lower_bound`返回的迭代器，`second`成员等价于`upper_bound`返回的迭代器。  

## 练习11.30
> 对于本节最后一个程序中的输出表达式，解释运算对象pos.first->second的含义。

等价于`(pos.first)->second`。  
`pos`是`equal_range`返回的`pair`，它的`first`成员是指向第一个与关键字匹配的元素的迭代器。  
该元素是一个`pair<string,string>`，通过箭头运算符解引用后访问其`second`成员，也就是`map`中对应关键字所保存的值。  

## [练习11.31](ex11_31.cpp)
> 编写程序，定义一个作者及其作品的 multimap。使用 find 在 multimap 中查找一个元素并用 erase 删除它。确保你的程序在元素不在 map 中时也能正常运行。

## [练习11.32](ex11_32.cpp)
> 使用上一题定义的 multimap 编写一个程序，按字典序打印作者列表和他们的作品。

## [练习11.33](ex11_33/ex11_33.cpp)
> 实现你自己版本的单词转换程序。

## 练习11.34
> 如果你将 transform 函数中的 find 替换为下标运算符，会发生什么情况？

当关键字不存在时，下标运算符会构造一个关键字-值的`pair`插入容器，其中值进行值初始化。  
由于下标运算符不能对常量对象使用，因此替换为下标运算符是非法的。  
如果将`map`修改为非常量引用，下标运算符合法，但对于每个进行查找的不在容器中的关键字，它都会将一个不存在的规则`<进行查找的单词，空串>`添加到转换`map`中，这显然是错误的。    

## 练习11.35
> 在 buildMap 中，如果进行如下改写，会有什么效果？
```cpp
trans_map[key] = value.substr(1);
改为 trans_map.insert({key, value.substr(1)});
```
当`map`中没有给定关键字时，下标与赋值操作的效果`insert`的效果是一样的。  
当`map`中有给定的关键字时，下标运算符会提取该关键字对应的元素，赋值语句将新值赋给它。而`insert`遇到关键字已存在的情况时不会插入元素，而是返回一个`pair`，`pair`的`first`成员是指向已存在元素的迭代器，`second`成员是表示插入未成功的布尔值。  
因此若一个单词在转换文件中多次出现，在使用下标运算符时，`map`中保存的是最后一次添加的对应短语。而使用`insert`时，`map`中保存的是第一次添加的对应短语。  

## 练习11.36
> 我们的程序并没有检查输入文件的合法性。特别是，它假定转换规则文件中的规则都是有意义的。如果文件中的某一行包含一个关键字、一个空格，然后就结束了，会发生什么？预测程序的行为并进行验证，再与你的程序进行比较。

`buildMap`函数中`if`语句的条件`value.size() > 1`将为`false`，程序抛出一个`runtime_error`异常。  

## 练习11.37
> 一个无序容器与其有序版本相比有何优势？有序版本有何优势？

无序版本能拥有更好的性能，当关键字类型没有明显的序关系，或者维护元素的序代价非常高时，无序容器有很大的优势。  
有序版本的优势是维护了元素的序，当必须要保持顺序时只能使用有序容器。另外，尽管理论上哈希技术能获得更好的平均性能，但实际中想要达到很好的效果还需要进行一些性能测试和调优，因此使用有序容器通常更简单，性能也更好。  

## [练习11.38](ex11_38)
> 用 unordered_map 重写单词计数程序（参见 11.1 节，第 375 页）和单词转换程序（参见 11.3.6 节，第 391 页）。