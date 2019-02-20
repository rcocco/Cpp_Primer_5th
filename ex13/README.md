## 练习13.1
> 拷贝构造函数是什么？什么时候使用它？

第一个参数是自身类类型的引用，且任何额外参数都有默认值的构造函数是拷贝构造函数。  
当使用拷贝初始化时通常会使用拷贝构造函数，拷贝初始化包括以下情况：  
- 用`=`定义变量  
- 将一个对象作为实参传递给一个非引用的形参  
- 从一个返回类型为非引用类型的函数返回一个对象  
- 用花括号列表初始化一个数组中的元素或一个聚合类中的成员  

## 练习13.2
> 解释为什么下面的声明是非法的：
```cpp
Sales_data::Sales_data(Sales_data rhs);
```
拷贝构造函数的第一个参数应该是自身类类型的引用，在上述代码中，为了调用拷贝构造函数，需要拷贝它的实参，而为了拷贝实参又需要调用拷贝构造函数，导致无限循环。  

## 练习13.3
> 当我们拷贝一个 StrBlob 时，会发生什么？拷贝一个 StrBlobPtr 呢？

`StrBlob`和`StrBlobPtr`没有定义拷贝构造函数，当没有为类定义拷贝构造函数时，编译器会定义一个合成拷贝构造函数，它逐个拷贝非`static`成员，对类类型成员调用其拷贝构造函数来拷贝，内置类型成员则直接拷贝，数组类型会逐元素拷贝。  
`StrBlob`的唯一成员是`shared_ptr<vector<string>> data`，它是类类型成员，会调用智能指针的拷贝构造函数来拷贝，拷贝后引用计数加`1`，二者管理相同的内存对象。  
`StrBlobPtr`的一个成员是`weak_ptr<vector<string>> wptr`，它是类类型成员，会调用`weak_ptr`的拷贝构造函数来拷贝，拷贝后引用计数不变，二者管理相同的内存对象。另一个成员是`size_t curr`，它是内置类型成员，会直接拷贝。  

## 练习13.4
> 假定 Point 是一个类类型，它有一个 public 的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
```cpp
Point global;
Point foo_bar(Point arg)
{
	Point local = arg, *heap = new Point(global);
	*heap = local; 
	Point pa[4] = { local, *heap };
	return *heap;
}
```
1. 函数参数中的`Point arg`，将一个对象作为实参传递给一个非引用的形参，使用了拷贝构造函数。  
2. `Point local = arg`，用`=`定义变量，使用了拷贝构造函数。  
3. `new Point(global)`直接调用了拷贝构造函数。  
4. `Point pa[4] = { local, *heap }`，用花括号列表初始化一个数组中的元素，使用了拷贝构造函数。  
5. `return *heap`，从一个返回类型为非引用类型的函数返回一个对象，使用了拷贝构造函数。    

## [练习13.5](ex13_05/HasPtr.h)
> 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的 string（参见 12.1.2 节，第 407 页），并将对象拷贝到 ps 指向的位置，而不是 ps 本身的位置。
```cpp
class HasPtr {
public:
	HasPtr(const std::string& s = std::string()):
		ps(new std::string(s)), i(0) { }
private:
	std::string *ps;
	int i;
}
```

## 练习13.6
> 拷贝赋值运算符是什么？什么时候使用它？合成拷贝赋值运算符完成什么工作？什么时候会生成合成拷贝赋值运算符？

拷贝赋值运算符是重载的赋值运算符，它是类的成员函数，接受一个与其所在类相同类型的参数，左侧运算对象绑定到隐式的`this`参数，右侧运算对象作为显式参数传递。  
当对类对象进行赋值时，会使用拷贝赋值运算符。  
合成拷贝赋值运算符通常会将右侧运算对象的每个非`static`成员赋予左侧运算对象的对应成员，成员的赋值是通过成员类型的拷贝赋值运算符完成的。对于数组类型成员，会逐个赋值数组元素。最后会返回一个指向其左侧运算对象的引用。  
如果类未定义自己的拷贝赋值运算符，编译器会生成一个合成拷贝赋值运算符。  

## 练习13.7
> 当我们将一个 StrBlob 赋值给另一个 StrBlob 时，会发生什么？赋值 StrBlobPtr 呢？

`StrBlob`和`StrBlobPtr`没有定义拷贝赋值运算符，当没有为类定义拷贝赋值运算符时，编译器会定义一个合成拷贝赋值运算符，它将右侧运算对象的每个非`static`赋予左侧运算对象的对应成员。成员的赋值是通过成员类型的拷贝赋值运算符完成的。对于数组类型成员，会逐个赋值数组元素。最后会返回一个指向其左侧运算对象的引用。    
`StrBlob`的唯一成员是`shared_ptr<vector<string>> data`，它是类类型成员，会调用智能指针的拷贝赋值运算符将右侧运算对象的`data`成员赋予左侧运算对象的`data`成员，赋值后右侧运算对象引用计数加`1`，左侧运算对象的引用计数减`1`，左侧运算对象现在指向右侧运算对象所管理的内存。  
`StrBlobPtr`的一个成员是`weak_ptr<vector<string>> wptr`，它是类类型成员，会调用`weak_ptr`的拷贝赋值运算符将右侧运算对象的`wptr`成员赋予左侧运算对象的`wptr`成员，赋值后二者的引用计数不变，左侧运算对象现在指向右侧运算对象所管理的内存。另一个成员是`size_t curr`，它是内置类型成员，会直接赋值。  

## [练习13.8](ex13_08/HasPtr.h)
> 为 13.1.1 节（第 443 页）练习13.5中的 HasPtr 类编写赋值运算符。类似拷贝构造函数，你的赋值运算符应该将对象拷贝到 ps 指向的位置。

## 练习13.9
> 析构函数是什么？合成析构函数完成什么工作？什么时候会生成合成析构函数？

析构函数是类的一个成员函数，名字由波浪号接类名构成。它没有返回值，也不接受参数。  
对于某些类，合成析构函数可用来阻止该类型的对象被销毁。如果不是这种情况，合成析构函数的函数体为空，函数体执行完后，在隐含的析构阶段，非`static`成员被自动销毁。  
当一个类未定义自己的析构函数时，编译器会为它定义一个合成析构函数。  

## 练习13.10
> 当一个 StrBlob 对象销毁时会发生什么？一个 StrBlobPtr 对象销毁时呢？

`StrBlob`和`StrBlobPtr`没有定义析构函数，当没有为类定义析构函数时，编译器会定义一个合成析构函数，它的函数体为空，在隐含的析构阶段，非`static`成员被自动销毁。  
`StrBlob`的唯一成员是`shared_ptr<vector<string>> data`，它是类类型成员，会调用智能指针的析构函数来销毁它，析构函数执行后它所管理的对象的引用计数减`1`，若引用计数为`0`，则销毁它所管理的`vector`对象。  
`StrBlobPtr`的一个成员是`weak_ptr<vector<string>> wptr`，它是类类型成员，会调用`weak_ptr`的析构函数来销毁它，销毁后引用计数不变。另一个成员是`size_t curr`，它是内置类型成员，销毁时不会有特殊操作。  

## [练习13.11](ex13_11/HasPtr.h)
> 为前面练习中的 HasPtr 类添加一个析构函数。

## 练习13.12
> 在下面的代码片段中会发生几次析构函数调用？
```cpp
bool fcn(const Sales_data *trans, Sales_data accum)
{
	Sales_data item1(*trans), item2(accum);
	return item1.isbn() != item2.isbn();
}
```
函数体执行完毕后，变量`trans`、`accum`、`item1`和`item2`因为离开其作用域被销毁。  
`trans`是内置指针类型，销毁它时什么也不会做。  
`accum`、`item1`和`item2`是类类型，销毁它们时会调用类的析构函数。  
因此一共有三次析构函数调用。  

## [练习13.13](exercise13_13.cpp)
> 理解拷贝控制成员和构造函数的一个好方法的定义一个简单的类，为该类定义这些成员，每个成员都打印出自己的名字：
```cpp
struct X {
	X() {std::cout << "X()" << std::endl;}
	X(const X&) {std::cout << "X(const X&)" << std::endl;}
};
```
> 给 X 添加拷贝赋值运算符和析构函数，并编写一个程序以不同方式使用 X 的对象：将它们作为非引用参数传递；动态分配它们；将它们存放于容器中；诸如此类。观察程序的输出，直到你确认理解了什么时候会使用拷贝控制成员，以及为什么会使用它们。当你观察程序输出时，记住编译器可以略过对拷贝构造函数的调用。

## 练习13.14
> 假定 numbered 是一个类，它有一个默认构造函数，能为每个对象生成一个唯一的序号，保存在名为 mysn 的数据成员中。假定 numbered 使用合成的拷贝控制成员，并给定如下函数：
```cpp
void f (numbered s) { cout << s.mysn < endl; }
```
> 则下面代码输出什么内容？
```cpp
numbered a, b = a, c = b;
f(a); f(b); f(c);
```
输出三个相同的序号，因为合成拷贝构造函数会简单的拷贝序号。  

## 练习13.15
> 假定 numbered 定义了一个拷贝构造函数，能生成一个新的序号。这会改变上一题中调用的输出结果吗？如果会改变，为什么？新的输出结果是什么？

会改变。假如序号从`0`开始递增，那么`a`、`b`、`c`中的序号分别为`0`、`1`、`2`。  
输出的结果将是`3`、`4`、`5`。因为函数`f`的参数是非引用形参，也调用了拷贝构造函数生成了一个新的序号。  

## 练习13.16
> 如果 f 中的参数是 const numbered&，将会怎样？这会改变输出结果吗？如果会改变，为什么？新的输出结果是什么？

会改变。因为函数`f`的参数是引用形参，不会调用拷贝构造函数，因此输出的结果将是`0`、`1`、`2`。  

## [练习13.17](ex13_17)
> 分别编写前三题中所描述的 numbered 和 f，验证你是否正确预测了输出结果。

## [练习13.18](ex13_18/Employee.h)
> 定义一个 Employee 类，它包含雇员的姓名和唯一的雇员证号。为这个类定义默认构造函数，以及接受一个表示雇员姓名的 string 的构造函数。每个构造函数应该通过递增一个 static 数据成员来生成一个唯一的证号。

## [练习13.19](ex13_19/Employee.h)
> 你的 Employee 类需要定义它自己的拷贝控制成员吗？如果需要，为什么？如果不需要，为什么？实现你认为 Employee 需要的拷贝控制成员。

它需要拷贝控制成员，合成的拷贝构造函数与拷贝赋值运算符会简单的复制唯一的雇员证号，这导致二者的雇员证号不唯一。  

## 练习13.20
> 解释当我们拷贝、赋值或销毁 TextQuery 和 QueryResult 类（参见 12.3 节，第 430 页）对象时会发生什么。

两个类都没有定义拷贝控制成员，编译器会定义合成的拷贝控制成员。  
当拷贝`TextQuery`时，合成版本会拷贝`file`和`wm`，对`file`，`shared_ptr`的引用计数加`1`。对`wm`，会调用`map`的拷贝构造函数。赋值操作类似，只是原来的`file`和`shared_ptr`被自动销毁，对`file`，原来的`shared_ptr`引用计数减`1`。销毁`TextQuery`时，合成版本会销毁`file`和`wm`，对`file`，它的引用计数减`1`，若变为`0`还会销毁所管理的`vector`的对象，对`wm`，会调用`map`的析构函数。  
当拷贝`QueryResult`时，合成版本会拷贝`sought`、`lines`和`file`，对`sought`会调用`string`的拷贝构造函数。对`lines`和`file`，各自`shared_ptr`的引用计数加`1`。赋值操作类似，只是`shared_ptr`引用计数减`1`。销毁`QueryResult`时，合成版本会销毁`sought`、`lines`和`file`。对`sought`，会调用`string`的析构函数。对`lines`和`file`会使引用计数减`1`，若引用计数变为`0`还会释放所管理对象的内存。  

## 练习13.21
> 你认为 TextQuery 和 QueryResult 类需要定义它们自己版本的拷贝控制成员吗？如果需要，为什么？如果不需要，为什么？实现你认为这两个类需要的拷贝控制操作。

不需要，这两个类使用智能指针管理动态对象，使用标准库容器保存多个元素，合成的拷贝控制成员会自动调用标准库类型所定义的设计良好的拷贝控制成员，可以保证它们有正确的拷贝、赋值与销毁操作。  

## [练习13.22](ex13_22/HasPtr.h)
> 假定我们希望 HasPtr 的行为像一个值。即，对于对象所指向的 string 成员，每个对象都有一份自己的拷贝。我们将在下一节介绍拷贝控制成员的定义。但是，你已经学习了定义这些成员所需的所有知识。在继续学习下一节之前，为 HasPtr 编写拷贝构造函数和拷贝赋值运算符。

## 练习13.23
> 比较上一节练习中你编写的拷贝控制成员和这一节中的代码。确定你理解了你的代码和我们的代码之间的差异（如果有的话）。

本节的代码保证了自赋值的情况是安全的。  

## 练习13.24
> 如果本节的 HasPtr 版本未定义析构函数，将会发生什么？如果未定义拷贝构造函数，将会发生什么？

如果未定义析构函数，在销毁`HasPtr`对象时合成的析构函数不会释放指针`ps`指向的内存，造成内存泄漏。  
如果未定义拷贝构造函数，在拷贝`HasPtr`对象时合成的拷贝构造函数会简单拷贝`ps`成员，导致两个`HasPtr`指向相同的`string`。当其中一个`HasPtr`修改了`string`的内容时，另一个`HasPtr`也被改变。当销毁其中一个`HasPtr`时，指针`ps`所指向的内存被释放，另一个`HasPtr`的`ps`变成了空悬指针。  

## 练习13.25
> 假定希望定义 StrBlob 的类值版本，而且希望继续使用 shared_ptr，这样我们的 StrBlobPtr 类就仍能使用指向 vector 的 weak_ptr 了。你修改后的类将需要一个拷贝的构造函数和一个拷贝赋值运算符，但不需要析构函数。解释拷贝构造函数和拷贝赋值运算符必须要做什么。解释为什么不需要析构函数。

拷贝构造函数和拷贝赋值运算符需要动态分配一个新的`vector`，它的内容是原来`vector`的拷贝，此时两个`vector`是各自独立的，然后令`shared_ptr`管理这个新的`vector`。  
`StrBlob`唯一的成员就是`shared_ptr`，当`StrBlob`对象销毁时，合成的析构函数会自动调用`shared_ptr`的析构函数，它会递减引用计数，同时当引用计数变为`0`时释放`vector`，因此合成版本已经能正确的释放资源，不需要进行额外的操作。  

## [练习13.26](ex13_26)
> 对上一题中描述的 StrBlob 类，编写你自己的版本。

## [练习13.27](ex13_27)
> 定义你自己的使用引用计数版本的 HasPtr。

## [练习13.28](ex13_28)
> 给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员。
```cpp
(a) 
class TreeNode {
pravite:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;	
};
(b)
class BinStrTree{
pravite:
	TreeNode *root;	
};
```
本题的目的是定义类值版本的`TreeNode`，在本书第四版中，该题位于`13.5.2. Defining Valuelike Classes`的练习当中。  
在本书第五版中该题题目未变，却放在了类指针版本一节，出于本节前面提到的“计数器不能直接作为`HasPtr`对象的成员”相同的原因，`int count`无法实现引用计数，需要改为`int *count`。  
因此这里给出类值和类指针两种版本的解答。  

## 练习13.29
> 解释 swap(HasPtr&, HasPtr&) 中对 swap 的调用不会导致递归循环。

函数中两次调用`swap`的参数分别是指针类型和整型，不会匹配`swap(HasPtr &,HasPtr &)`，因此不会导致递归循环。  

## [练习13.30](ex13_30)
> 为你的类值版本的 HasPtr 编写 swap 函数，并测试它。为你的 swap 函数添加一个打印语句，指出函数什么时候执行。

## [练习13.31](ex13_31)
> 为你的 HasPtr 类定义一个 < 运算符，并定义一个 HasPtr 的 vector。为这个 vector 添加一些元素，并对它执行 sort。注意何时会调用 swap。

在`Visual Studio 2017`的测试中，只有`vector`中元素数量大于等于`33`时，`sort`函数才会调用`swap`。  

## 练习13.32
> 类指针的 HasPtr 版本会从 swap 函数受益吗？如果会，得到了什么益处？如果不是，为什么？

不会，标准库版本的`swap`等价于对`HasPtr`对象调用一次拷贝构造和两次拷贝赋值，对于类指针版本的`HasPtr`，拷贝构造和拷贝赋值都是直接拷贝了`string`指针和引用计数指针的值，和专用`swap`版本交换指针的操作是一样的，因此专用`swap`版本不会有更多的收益。  

## 练习13.33
> 为什么 Message 的成员 save 和 remove 的参数是一个 Folder&？为什么我们不将参数定义为 Folder 或是 const Folder&？

因为需要将给定`Folder`的指针添加到当前`Message`的`folders`集合中，所以参数不能是`Folder`，否则`folders.insert`添加的就是形参的指针，在函数结束后形参被销毁，指向它的指针也就无效了。  
其次需要将当前`Message`指针添加到`Folder`的`messages`集合中，这会修改`Folder`的内容，所以参数不能是`const Folder &`。  

## [练习13.34](ex13_34)
> 编写本节所描述的 Message。

## 练习13.35
> 如果 Message 使用合成的拷贝控制成员，将会发生什么？

`Message`的成员是`string`和`set`类型，合成的拷贝控制成员能正确的构造、拷贝与销毁它们，但合成版本不会更新对应的`Folder`中的`messages`集合，这导致`Message`和`Folder`保存的数据不同步。  

## [练习13.36](ex13_36)
> 设计并实现对应的 Folder 类。此类应该保存一个指向 Folder 中包含的 Message 的 set。

## [练习13.37](ex13_37)
> 为 Message 类添加成员，实现向 folders 添加和删除一个给定的 Folder*。这两个成员类似 Folder 类的 addMsg 和 remMsg 操作。

## 练习13.38
> 我们并未使用拷贝和交换方式来设计 Message 的赋值运算符。你认为其原因是什么？

拷贝和交换首先会将实参拷贝给形参`rhs`，这会触发拷贝构造函数，将实参的`contents`和`folders`拷贝给`rhs`，并调用`add_to_Folders`将`rhs`指针添加到`folders`的每个`Folder`中。随后调用`swap`交换`*this`和`rhs`，这导致各自遍历了两次`folders`来进行相应的添加和删除操作。最后`rhs`被销毁，析构函数调用`remove_from_Folders`将`rhs`从所有`Folder`中删除。  
逻辑上是正确的，能够达到预期目的，但效率低下，拷贝和交换操作总共遍历了`6`次`folders`，而将形参定义为引用类型后只需要遍历`2`次`folders`。  

## [练习13.39](ex13_39)
> 编写你自己版本的 StrVec，包括自己版本的 reserve、capacity（参见 9.4 节，第 318 页）和 resize（参见 9.3.5 节，第 314 页）。

## [练习13.40](ex13_40)
> 为你的 StrVec 类添加一个构造函数，它接受一个 initializer_list< string > 参数。

## 练习13.41
> 在 push_back 中，我们为什么在 construct 调用中使用后置递增运算？如果使用前置递增运算的话，会发生什么？

`first_free`指向第一个空闲位置，后置递增使`construct`的元素保存在该空闲位置，然后将`first_free`推进一个位置，它仍然指向第一个空闲位置。  
若使用前置递增运算，会先将`first_free`推进一个位置，然后将`construct`的元素保存在新位置上，这导致每次`push_back`会空出一个未构造元素的位置，同时`first_free`会指向最后一个元素，而不是第一个空闲位置。  

## [练习13.42](ex13_42)
> 在你的 TextQuery 和 QueryResult 类（参见 12.3 节，第 431 页）中用你的 StrVec 类代替 vector< string >，以此来测试你的 StrVec 类。

## 练习13.43
> 重写 free 成员，用 for_each 和 lambda（参见 10.3.2 节，第 346 页）来代替 for 循环 destroy 元素。你更倾向于哪种实现，为什么？
```cpp
for_each(elements, first_free,
	[](string &s) {alloc.destroy(&s); });
```
`for_each`更好，不必手动管理指针的增减，只需关注要对范围内的元素执行什么操作。  

## [练习13.44](ex13_44)
> 编写标准库 string 类的简化版本，命名为 String。你的类应该至少有一个默认构造函数和一个接受 C 风格字符串指针参数的构造函数。使用 allocator 为你的 String 类分配所需内存。

## 练习13.45
> 解释右值引用和左值引用的区别？

右值引用是必须绑定到右值的引用，通过`&&`获得，右值引用只能绑定到一个将要销毁的对象上，包括要转换的表达式、字面常量或返回右值的表达式，不能绑定到一个左值上。因此可以自由的移动其资源。  
左值引用是必须绑定到左值的引用，通过`&`获得，它是所绑定的对象的别名。  

## 练习13.46
> 什么类型的引用可以绑定到下面的初始化器上？
```cpp
int f();
vector<int> vi(100);
int? r1 = f();
int? r2 = vi[0];
int? r3 = r1;
int? r4 = vi[0] * f();
```
变量表达式、返回左值引用的函数、赋值、下标、解引用和前置递增/递减运算符，返回左值表达式，左值引用可以绑定到这类表达式上。  
返回非引用类型的函数、算术、关系、位以及后置递增/递减运算符，返回右值表达式，不能将左值引用绑定到这类表达式上面，可以将一个`const`的左值引用或者右值引用绑定到这类表达式上面。  
  
`f()`是一个返回非引用类型的函数，它返回右值，`r1`必须是右值引用。  
`vi[0]`下标运算符返回一个左值，`r2`必须是左值引用。  
`r1`是一个变量，它是变量表达式，因此是一个左值，`r3`必须是左值引用。  
`vi[0] * f()`是算术表达式，它返回右值，`r4`必须是右值引用。  

## [练习13.47](ex13_47)
> 对你在练习 13.44（13.5 节，第 470 页）中定义的 String 类，为它的拷贝构造函数和拷贝赋值运算符添加一条语句，在每次函数执行时打印一条信息。

## [练习13.48](ex13_48)
> 定义一个 vector< String > 并在其上多次调用 push_back。运行你的程序，并观察 String 被拷贝了多少次。

## [练习13.49](ex13_49)
> 为你的 StrVec、String 和 Message 类添加一个移动构造函数和一个移动赋值运算符。

## [练习13.50](ex13_50)
> 在你的 String 类的移动操作中添加打印语句，并重新运行 13.6.1 节（第 473 页）的练习 13.48 中的程序，它使用了一个 vector< String >，观察什么时候会避免拷贝。

## 练习13.51
> 虽然 unique_ptr 不能拷贝，但我们在 12.1.5 节（第 481 页）中编写了一个 clone 函数，它以值方式返回一个 unique_ptr。解释为什么函数是合法的，以及为什么它能正确工作。

`unique_ptr`不能拷贝，但有一个例外：可以拷贝或赋值一个将要被销毁的`unique_ptr`。`clone`返回一个将要销毁的`unique_ptr`是允许的，它实质是调用了移动构造函数来使用返回值初始化调用点的表达式。  

## 练习13.52
> 详细解释第 478 页中的 HasPtr 对象的赋值发生了什么？特别是，一步一步描述 hp、hp2 以及 HasPtr 的赋值运算符中的参数 rhs 的值发生了什么变化。

`hp = hp2`调用了`HasPtr`的赋值运算符，赋值运算符的参数`rhs`不是引用。  
将一个对象作为实参传递给一个非引用的形参会触发拷贝初始化，拷贝初始化会调用它的拷贝构造函数或者移动构造函数。  
由于`hp2`是一个左值，移动构造函数的参数是右值引用，无法绑定到左值上，因此会调用拷贝构造函数。拷贝构造函数使用实参的`string`动态分配了一个新的和该实参一样的`string`，此时`rhs`和`hp2`中的`string`值相同，但地址不同，各自无关。随后`swap`交换了`rhs`和`hp1`中的指针，原来`hp1`中的指针现在位于`rhs`中，最后函数结束`rhs`被销毁，指针所指对象内存被释放。  
`hp = std::move(hp2)`也调用了赋值运算符，赋值运算符又需要进行拷贝初始化，而`std::move(hp2)`是一个右值，拷贝构造函数和移动构造函数都可行，但移动构造函数的参数是一个右值引用，它是精确匹配。移动构造函数使`rhs`接管了`hp2`中的指针，随后`swap`交换了`rhs`和`hp1`中的指针，  原来`hp1`中的指针现在位于`rhs`中，最后函数结束`rhs`被销毁，指针所指对象内存被释放。  

## [练习13.53](ex13_53)
> 从底层效率的角度看，HasPtr 的赋值运算符并不理想，解释为什么？为 HasPtr 实现一个拷贝赋值运算符和一个移动赋值运算符，并比较你的新的移动赋值运算符中执行的操作和拷贝并交换版本中的执行的操作。

在进行拷贝赋值时，拷贝构造创建了`hp2`的拷贝`rhs`，然后交换了`hp`和`rhs`，其中`rhs`只起到了将值从`hp2`传递给`hp`的作用，它是冗余的，不需要`rhs`作媒介同样可以完成拷贝赋值操作。  
在进行移动赋值时，先从`hp2`转移到了`rhs`，再交换到`hp`，`rhs`同样是冗余的。  

## [练习13.54](ex13_54)
> 如果我们为 HasPtr 定义了移动赋值运算符，但未改变拷贝并交换运算符，会发生什么？编写代码验证你的答案。

对于`hp = hp2`，两个赋值运算符都是候选函数，但`hp2`是左值，`HasPtr &&`不能绑定到左值上，因此可行函数只有拷贝并交换运算符。  
对于`hp = std::move(hp2)`，`std::move(hp2)`是右值，移动赋值运算符和拷贝并交换运算符都是可行函数，对于参数来说都是精确匹配，没有一个函数优于另一个，调用具有二义性。  

## [练习13.55](ex13_55)
> 为你的 StrBlob 添加一个右值引用版本的 push_back。

## 练习13.56
> 如果 sorted 定义如下，会发生什么？
```cpp
Foo Foo::sorted() const & {
	Foo ret(*this);
	return ret.sorted();
}
```
变量`ret`是一个左值，`ret.sorted()`调用的将是接受左值`this`的`sorted()`，也就是该函数自身，这导致了无限递归。  

## 练习13.57
> 如果 sorted定义如下，会发生什么：
```cpp
Foo Foo::sorted() const & { return Foo(*this).sorted(); }
```
`Foo(*this)`是一个右值，将会调用接受右值`this`版本的`sorted`，函数可以正常执行。  

## [练习13.58](ex13_58.cpp)

> 编写新版本的 Foo 类，其 sorted 函数中有打印语句，测试这个类，来验证你对前两题的答案是否正确。