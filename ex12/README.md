## 练习12.1
> 在此代码的结尾，b1 和 b2 各包含多少个元素？
```cpp
StrBlob b1;
{
	StrBlob b2 = {"a", "an", "the"};
	b1 = b2;
	b2.push_back("about");
}
```
`4`个。所有`StrBlob`对象共享同一个创建于堆上的`vector`对象，该对象是使用智能指针管理的，因此`b1 = b2`只是拷贝了智能指针，`push_back`是在同一个`vector`上进行的操作。  

## [练习12.2](ex12_02)
> 编写你自己的 StrBlob 类，包含 const 版本的 front 和 back。

## 练习12.3
> StrBlob 需要 const 版本的 push_back 和 pop_back 吗？如需要，添加进去。否则，解释为什么不需要。

不需要。`push_back`和`pop_back`的作用是向`StrBlob`对象共享的`vector`添加或删除元素，而常量`StrBlob`对象不应该被允许修改`vector`的内容，因此不应重载`const`版本。  

## 练习12.4
> 在我们的 check 函数中，没有检查 i 是否大于0。为什么可以忽略这个检查？

因为`i`是一个`size_type`类型，它是无符号整数，当传递给它一个小于`0`的实参时，会被自动转换为一个非常大的无符号数。因此`i >= data->size()`也是有效的。  

## 练习12.5
> 我们未编写接受一个 initializer_list explicit（参见 7.5.4 节，第 264 页）参数的构造函数。讨论这个设计策略的优点和缺点。

接受一个`initializer_list`的构造函数不是`explicit`的，意味着可以进行列表向`StrBlob`的隐式类型转换，即在需要`StrBlob`的地方可以用列表代替。  
由于列表和`StrBlob`都表示一些字符串，这个转换在逻辑上是成立的，同时令程序的编写更加方便，例如可以用列表为`StrBlob`赋值，或者为接受`StrBlob`参数的函数传递列表。    
这个设计策略的一个缺点在于，用一个`StrBlob`为另一个`StrBlob`赋值总是合法的，但用一个列表为`StrBlob`赋值时，列表中可能并非都是合法的值。  

## [练习12.6](ex12_06.cpp)
> 编写函数，返回一个动态分配的 int 的 vector。将此 vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。再将 vector 传递给另一个函数，打印读入的值。记得在恰当的时刻 delete vector。

## [练习12.7](ex12_07.cpp)
> 重做上一题，这次使用 shared_ptr 而不是内置指针。

## 练习12.8
> 下面的函数是否有错误？如果有，解释错误原因。
```cpp
bool b() {
	int* p = new int;
	// ...
	return p;
}
```
有错。程序的目的是根据`new`返回的指针值来判断内存分配成功还是失败，合法的指针转换为布尔值`true`，空指针转换为布尔值`false`。  
但普通`new`在分配失败时会抛出`bad_alloc`异常而不是返回`nullptr`。因此无法达到目的。同时，如果在函数内没有`delete`指针，在指针被转换为布尔值返回后就无法再释放对应空间的内存了。  

## 练习12.9
> 解释下面代码执行的结果。
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```
`r`和`q`是普通指针，不会自动释放内存，当`r = q`令`r`和`q`指向同一处内存空间后，`r`之前所指向的值为`100`的内存空间就无法再被释放了，导致内存泄露。  
`r2`和`q2`是智能指针，`r2 = q2`令`r2`和`q2`指向同一处内存空间，同时会递增`q2`指向的对象的的引用计数，递减`r2`原来指向的对象的引用计数。  
由于`r2`原来所指向对象的引用计数为`0`，内存被自动释放了。  

## 练习12.10
> 下面的代码调用了第 413 页中定义的 process 函数，解释此调用是否正确。如果不正确，应如何修改？
```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```
正确。`shared_ptr<int>(p)`利用`p`创建一个临时的智能指针，它们指向相同的对象，拷贝使引用计数递增，当`process`函数结束时，临时创建的智能指针被销毁，引用计数递减。此时只有`p`指向该对象，引用计数为`1`。  

## 练习12.11
> 如果我们像下面这样调用 process，会发生什么？
```cpp
process(shared_ptr<int>(p.get()));
```
`p.get()`获得一个普通指针，指向智能指针`p`所管理的对象，利用该普通指针而不是智能指针`p`创建`shared_ptr`将不会形成正确的动态对象共享，二者的引用计数会独自计算。当`process`结束后临时创建的智能指针被销毁，引用计数变为`0`，它所管理的内存被释放，由于被释放的内存也是`p`所管理的，这导致`p`成为一个空悬指针。  

## 练习12.12

> p 和 sp 的定义如下，对于接下来的对 process 的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因：
```cpp
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```
(a) 合法。它从智能指针`sp`创建了一个临时智能指针`ptr`在函数内使用。它们所管理的是同一块内存，引用计数为`2`，当函数结束后`ptr`被销毁，引用计数变为`1`。    
(b) 不合法。`new int()`返回一个普通指针，而接受一个指针参数的智能指针构造函数是`explicit`的，不能将一个内置指针隐式转换为一个智能指针。  
(c) 不合法。不能将一个内置指针隐式转换为一个智能指针。  
(d) 合法，但存在隐患。`shared_ptr<int>(p)`从普通指针`p`创建了一个临时智能指针`ptr`，此时它的引用计数为`1`，当函数结束后，`ptr`被销毁，引用计数递减变为`0`，所管理的内存被释放，而此时普通指针`p`仍然指向已经被释放的内存，导致`p`成为空悬指针。  

## 练习12.13
> 如果执行下面的代码，会发生什么？
```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```
`sp.get()`获取到指向智能指针所管理对象的一个普通指针，对它`delete`后释放它指向的内存空间，智能指针`sp`的引用计数不变，`sp`变成了空悬指针。之后若智能指针的引用计数变为`0`，则会导致再次`delete`释放一块已经被释放过的内存空间。  

## [练习12.14](ex12_14.cpp)
> 编写你自己版本的用 shared_ptr 管理 connection 的函数。

## [练习12.15](ex12_15.cpp)
> 重写第一题的程序，用 lambda（参见 10.3.2 节，第 346 页）代替 end_connection 函数。

## [练习12.16](ex12_16.cpp)
> 如果你试图拷贝或赋值 unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种错误的程序，观察编译器如何诊断这种错误。

无法引用函数，它是已删除的函数。  

## 练习12.17
> 下面的 unique_ptr 声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。
```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
(a) IntP p0(ix);             (b) IntP p1(pi);
(c) IntP p2(pi2);            (d) IntP p3(&ix);
(e) IntP p4(new int(2048));  (f) IntP p5(p2.get());
```
(a) 不合法，只能使用指针初始化一个`unique_ptr`。  
(b) 合法，但存在问题。它用一个普通变量的地址初始化`p1`，当`p1`被销毁时会释放此内存，但释放一个不是动态分配的对象的内存，其结果是未定义的。  
(c) 合法，但存在问题。`p2`被销毁时会自动释放内存，这会导致`pi2`成为空悬指针。  
(d) 合法，但存在问题。和 (b) 的问题相同，销毁时会释放一个非动态分配对象的内存，结果是未定义的。  
(e) 合法。  
(f) 合法，但存在问题。用`p2`所管理的对象的地址来初始化`p5`，两个`unique_ptr`指向相同的内存空间，当其中一个被销毁时内存被释放，另一个`unique_ptr`变成空悬指针，而它销毁时会导致释放一块已经被释放的内存空间。  

## 练习12.18
> shared_ptr 为什么没有 release 成员？

`unique_ptr`独占对象的所有权，不能拷贝和赋值，`release`用来将对象的所有权转移给另一个`unique_ptr`。  
`shared_ptr`可以共享对象的所有权，允许拷贝和赋值，转移所有权时只需简单的赋值即可，不需要`release`。  

## [练习12.19](ex12_19)
> 定义你自己版本的 StrBlobPtr，更新 StrBlob 类，加入恰当的 friend 声明以及 begin 和 end 成员。

## [练习12.20](ex12_20/ex12_20.cpp)
> 编写程序，逐行读入一个输入文件，将内容存入一个 StrBlob 中，用一个 StrBlobPtr 打印出 StrBlob 中的每个元素。

## 练习12.21
> 也可以这样编写 StrBlobPtr 的 deref 成员：
```cpp
std::string& deref() const {
	return (*check(curr, "dereference past end"))[curr];
}
```
> 你认为哪个版本更好？为什么？

两个版本的效果是一样的。原来的版本将合法性检查与获取元素的语句分开，可读性更好，也便于修改。  

## [练习12.22](ex12_22)
> 为了能让 StrBlobPtr 使用 const StrBlob，你觉得应该如何修改？定义一个名为 ConstStrBlobPtr 的类，使其能够指向 const StrBlob。

要想让`StrBlobPtr`使用`const StrBlob`，应该将`StrBlobPtr(StrBlob &)`构造函数改为`StrBlobPtr(const StrBlob &)`。  

## [练习12.23](ex12_23.cpp)
> 编写一个程序，连接两个字符串字面常量，将结果保存在一个动态分配的 char 数组中。重写这个程序，连接两个标准库 string 对象。

## [练习12.24](ex12_24.cpp)
> 编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度的字符串。

## 练习12.25
> 给定下面的 new 表达式，你应该如何释放 pa？  
> `int *pa = new int[10];`  

```cpp
delete [] pa;
```

## [练习12.26](ex12_26.cpp)
> 用 allocator 重写第 427 页中的程序。

## [练习12.27](ex12_27)
> TextQuery 和 QueryResult 类只使用了我们已经介绍过的语言和标准库特性。不要提前看后续章节内容，只用已经学到的知识对这两个类编写你自己的版本。

## [练习12.28](ex12_28/ex12_28.cpp)
> 编写程序实现文本查询，不要定义类来管理数据。你的程序应该接受一个文件，并与用户交互来查询单词。使用 vector、map 和 set 容器来保存来自文件的数据并生成查询结果。

## [练习12.29](ex12_29/ex12_29.cpp)
> 我们曾经用 do while 循环来编写管理用户交互的循环（参见 5.4.4 节，第 169 页）。用 do while 重写本节程序，解释你倾向于哪个版本，为什么？

循环中的步骤是输入——检查循环条件——执行查询，检查循环条件是中间步骤，因此`while`和`do while`循环没有什么区别。  

## [练习12.30](ex12_30)
> 定义你自己版本的 TextQuery 和 QueryResult 类，并执行 12.3.1 节（第 431 页）中的 runQueries 函数。

## 练习12.31
> 如果用 vector 代替 set 保存行号，会有什么差别？哪个方法更好？为什么？

`vector`不会维护元素的序，允许元素重复，而`set`会维护关键字的序，不允许元素重复。    
对于本例而言，`vector`更好。  
1. 因为读取文本是逐行进行，所以添加到容器中的行号天然是升序的，不必利用`set`来保证元素的升序。  
2. 对于插入操作，`vector`的`push_back`可以达到常量时间，而`set`的`insert`通常需要对数时间。  
3. 对于一个单词在同一行出现多次的情况，使用`set`可以自动保证关键字不重复，而使用`vector`也很好解决，只需检查准备添加的行号与目前`vector`中最后一个行号是否不同，若不同才`push_back`行号，每次只会进行一次比较，性能较高。  

## [练习12.32](ex12_32)
> 重写 TextQuery 和 QueryResult 类，用 StrBlob 代替 vector< string > 保存输入文件。

## [练习12.33](ex12_33)
> 在第15章中我们将扩展查询系统，在 QueryResult 类中将会需要一些额外的成员。添加名为 begin 和 end 的成员，返回一个迭代器，指向一个给定查询返回的行号的 set 中的位置。再添加一个名为 get_file 的成员，返回一个 shared_ptr，指向 QueryResult 对象中的文件。