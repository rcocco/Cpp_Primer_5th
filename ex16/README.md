## 练习16.1
> 给出实例化的定义。

当调用模板时，编译器会利用给定的实参来推断模板实参，然后使用实际的模版实参代替对应的模版参数来创建出模版的一个新“实例”，这个过程叫做实例化。  

## [练习16.2](ex16_02.cpp)
> 编写并测试你自己版本的 compare 函数。

## [练习16.3](ex16_03.cpp)
> 对两个 Sales_data 对象调用你的 compare 函数，观察编译器在实例化过程中如何处理错误。

error C2676: 二进制“<”:“const T”不定义该运算符或到预定义运算符可接收的类型的转换

## [练习16.4](ex16_04.cpp)
> 编写行为类似标准库 find 算法的模版。函数需要两个模版类型参数，一个表示函数的迭代器参数，另一个表示值的类型。使用你的函数在一个 vector< int > 和一个list< string >中查找给定值。

## [练习16.5](ex16_05.cpp)
> 为 6.2.4 节（第 195 页）中的 print 函数编写模版版本，它接受一个数组的引用，能处理任意大小、任意元素类型的数组。

## [练习16.6](ex16_06.cpp)
> 你认为接受一个数组实参的标准库函数 begin 和 end 是如何工作的？定义你自己版本的 begin 和 end。

## [练习16.7](ex16_07.cpp)
> 编写一个 constexpr 模版，返回给定数组的大小。

## 练习16.8
> 在第97页的“关键概念”中，我们注意到，C++程序员喜欢使用 != 而不喜欢 < 。解释这个习惯的原因。

泛型编程的一个目标就是通用性，所有标准库容器的迭代器都定义了`==`和`!=`，但它们大多数都没有定义`<`。  

## 练习16.9
> 什么是函数模版，什么是类模版？

函数模板是可以实例化出特定函数的模板，类模板是可以实例化出特定类的模板。二者都以`template`开始后跟模板参数列表。使用函数模板时，编译器会根据传递给函数的参数来推断模板参数类型，而使用类模板时，必须显式指定模板参数。  

## 练习16.10
> 当一个类模版被实例化时，会发生什么？

编译器根据用户提供的显式模板实参来创建一个特定的类。  

## 练习16.11
> 下面 List 的定义是错误的。应如何修正它？
```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType> &);
	~List();
	void insert(ListItem *ptr, elemType value);
private:
	ListItem *front, *end;
};
```
类模板不是一个类型名，使用它时必须提供模板实参，唯一的例外是在类模板自己的作用域内，此时才可以直接使用它自己的模板名而不提供实参。  
因此在上述代码中，类模板内部的`ListItem`必须提供实参，而`List<elemType>`可以简化为`List`。  
```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List();
	List(const List &);
	List& operator=(const List &);
	~List();
	void insert(ListItem<elemType> *ptr, elemType value);
private:
	ListItem<elemType> *front, *end;
};
```

## [练习16.12](ex16_12)
> 编写你自己版本的 Blob 和 BlobPtr 模版，包含书中未定义的多个const成员。

注意，编写模板不能像此前一样简单的将声明放在头文件，实现放在cpp文件，而需要放在同一个头文件中。  
例如在`Blob.h`声明了函数模板`operator==`，在`Blob.cpp`定义了函数模板`operator==`，在`main.cpp`中使用了`Blob<int>() == Blob<int>()`，这会出现链接错误。  
在C++中，`cpp`文件独立编译，在编译`Blob.cpp`文件时编译器只看到了模板，没有看到使用`operator==<int>`，因此编译器不会实例化`operator==<int>`的代码，所以在将`main.obj`和`Blob.obj`进行链接时就会发生找不到`operator==<int>`代码的问题。  
  
以下几种办法可以解决这个问题：  
第一种解决办法也是目前的最佳实践，即将模板定义统一放在同一个头文件中。  
第二种解决办法就是在`Blob.cpp`模板定义的后面，显式实例化一个`operator==`：`template bool operator==(const Blob<int> &, const Blob<int> &);`，这种办法的缺点显而易见，每当你使用一个新类型都必须添加一句显式实例化语句。  
第三种解决办法就是在`main.cpp`文件中加一句`include "Blob.cpp"`，由于`include`本质是对文件内容的复制粘贴，这种办法和第一种没有区别。  
参见：  
1. [Why can templates only be implemented in the header file?](https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file)
2. [Operator overloading on class templates](https://stackoverflow.com/questions/4014294/operator-overloading-on-class-templates)
3. [c++函数模板声明与定义相分离](https://blog.csdn.net/qq_41230365/article/details/80207819)

## 练习16.13
> 解释你为 BlobPtr 的相等和关系运算符选择哪种类型的友好关系？

`BlobPtr`实例化出的每个类型都需要对应这种类型的相等和关系运算符，各类型彼此无关，因此应选择一对一友好关系。  

## [练习16.14](ex16_14/Screen.h)
> 编写 Screen 类模版，用非类型参数定义 Screen 的高和宽。

## [练习16.15](ex16_15/Screen.h)
> 为你的 Screen 模版实现输入和输出运算符。Screen 类需要哪些友元（如果需要的话）来令输入和输出运算符正确工作？解释每个友元声明（如果有的话）为什么是必要的。

不需要友元声明，因为输入和输出运算符可以调用`Screen`类的`public`成员函数`set`和`get`完成相应工作。  

## [练习16.16](ex16_16/Vec.h)
> 将 StrVec 类（参见 13.5 节，第 465 页）重写为模版，命名为 Vec。

## 练习16.17
> 声明为 typename 的类型参数和声明为 class 的类型参数有什么不同（如果有的话）？什么时候必须使用 typename？

在模板参数列表中，用来声明模板类型参数时，`typename`和`class`没有什么不同。  
当需要对模板类型参数使用作用域运算符，例如`T::size_type`时，编译器默认`size_type`是一个静态类型成员，如果希望编译器将`size_type`作为一个类型名字，就需要在前面加上`typename`，此时不能使用`class`。  

## 练习16.18
> 解释下面每个函数模版声明并指出它们是否非法。更正你发现的每个错误。
```cpp
(a) template <typename T, U, typename V> void f1(T, U, V);
(b) template <typename T> T f2(int &T);
(c) inline template <typename T> T foo(T, unsigned int *);
(d) template <typename T> f4(T, T);
(e) typedef char Ctype;
	template <typename Ctype> Ctype f5(Ctype a);
```
(a) 非法。模板参数列表当中的每个类型参数前面都需要加上`typename`或者`class`，每个非类型参数前面都需要加上特定的类型。应改为：  
```cpp
template <typename T, typename U, typename V> void f1(T, U, V);
```
(b) 非法。在模板作用域内，不能重用模板参数名，因此函数的参数名字不能为`T`。应改为：  
```cpp
template <typename T> T f2(int &t);
```
(c) 非法。`inline`关键字应在模板参数列表后，类型名之前。应改为：  
```cpp
template <typename T> inline T foo(T, unsigned int *);
```
(d) 非法。没有提供函数的返回类型，假定返回`bool`，应改为：  
```cpp
template <typename T> bool f4(T, T);
```
(e) 合法。但在模板作用域内，作为模板类型参数的`Ctype`隐藏了外部的类型别名`Ctype`。函数的返回值和参数类型是传递进来的实参的类型，而不是`char`。  

## [练习16.19](ex16_19.cpp)
> 编写函数，接受一个容器的引用，打印容器中的元素。使用容器的 size_type 和 size 成员来控制打印元素的循环。

由于只能使用`size_type`和`size`，在不使用迭代器的情况下该函数下对`list`等不支持随机访问的容器无效。使用迭代器的情况见下一题。  

## [练习16.20](ex16_20.cpp)
> 重写上一题的函数，使用 begin 和 end 返回的迭代器来控制循环。

## [练习16.21](ex16_21.cpp)
> 编写你自己的 DebugDelete 版本。

## [练习16.22](ex16_22/TextQuery.cpp)
> 修改 12.3 节（第 430 页）中你的 TextQuery 程序，令 shared_ptr 成员使用 DebugDelete 作为它们的删除器。（参见 12.1.4 节，第 415 页）。

## [练习16.23](ex16_23/main.cpp)
> 预测在你的查询主程序中何时会执行调用运算符。如果你的预测和实际不符，确认你理解了原因。

当`shared_ptr`的引用计数变为`0`时才会调用`DebugDelete`进行释放操作。在主程序中，只有`runQueries`函数里的`TextQuery tq`对象有`shared_ptr`成员，因此当`runQueries`函数结束时引用计数变为`0`，此时会执行调用运算符。  

## [练习16.24](ex16_24/Blob.h)
> 为你的 Blob 模版添加一个构造函数，它接受两个迭代器。

## 练习16.25
> 解释下面这些声明的含义。
```cpp
extern template class vector<string>;
template class vector<Sales_data>;
```
第一行是实例化模板的声明，表示不在本文件中实例化一个`vector<string>`类，该实例化的定义在其他文件中。  
第二行是实例化模板的定义，表示要求编译器实例化一个`vector<Sales_data>`类，由于编译器不清楚将使用哪些成员函数，它会实例化该类的所有成员。  

## 练习16.26
> 假设 NoDefault 是一个没有默认构造函数的类，我们可以显式实例化 vector< NoDefualt >吗？如果不可以，解释为什么。

不可以。显式实例化会实例化该类的所有成员，这要求用来实例化的类型必须能用于模板的所有成员函数。  
在`vector`中存在构造函数`vector(size_type n)`，该函数使用模板类型参数的默认构造函数来构造一个含有`n`个默认初始化元素的容器。由于`NoDefault`没有默认构造函数，这个构造函数无法实例化。  

## [练习16.27](ex16_27.cpp)
> 对下面每条带标签的语句，解释发生了什么样的实例化（如果有的话）。如果一个模版被实例化，解释为什么；如果未实例化，解释为什么没有。
```cpp
template <typename T> class Stack {	};
void f1(Stack<char>); 		//(a)
class Exercise {
	Stack<double> &rsd;		//(b)
	Stack<int> si;			//(c)
};
int main() {
	Stack<char> *sc;		//(d)
	f1(*sc);				//(e)
	int iObj = sizeof(Stack<string>);	//(f)
}
```
(a) 没有实例化，函数声明中的参数，编译器只需要知道名字，而不需要知道具体定义。  
(b) 没有实例化，对于引用的声明，编译器不需要知道引用类型的具体定义。  
(c) 实例化了`Stack<int>`，作为一个非引用或指针成员，编译器需要知道应为该成员分配多大空间，因此需要知道类型的定义。  
(d) 没有实例化，定义了一个指针，任何指针的值都是地址，编译器知道存放一个地址所需要的空间，它不需要知道指针所指对象的具体定义。  
(e) 实例化了`Stack<char>`，对一个类类型变量解引用，需要知道这个类的解引用运算符的定义。  
(f) 实例化了`Stack<string`，`sizeof`获取类型或对象所占大小，编译器必须知道该类型的具体定义才能计算占用内存大小。  

测试办法参见：[How is a template instantiated?](https://stackoverflow.com/questions/21598635/how-is-a-template-instantiated)
该方法是在模板中使用了一个不可能存在的类型，如果编译器实例化了模板，它就会发现这个类型不存在从而编译失败。如果编译器没有实例化模板，它就不会发现问题，编译通过。因此根据编译是否通过可以判断有没有进行实例化。    


## [练习16.28](ex16_28)
> 编写你自己版本的 shared_ptr 和 unique_ptr。

## [练习16.29](ex16_29/Blob.h)
> 修改你的 Blob 类，用你自己的 shared_ptr 代替标准库中的版本。

## [练习16.30](ex16_30)
> 重新运行你的一些程序，验证你的 shared_ptr 类和修改后的 Blob 类。（注意：实现 weak_ptr 类型超出了本书范围，因此你不能将 BlobPtr 类与你修改后的 Blob 一起使用。）

## 练习16.31
> 如果我们将 DebugDelete 与 unique_ptr 一起使用，解释编译器将删除器处理为内联形式的可能方式。

`unique_ptr`有两个模板参数，一个是所管理对象的类型，另一个是删除器类型。由于删除器类型是`unique_ptr`的一部分，删除器对象可以直接保存在`unique_ptr`对象中。由于编译器已知删除器类型的定义，也清楚删除器可调用对象的代码，因此可以在调用点进行内联展开。    

## 练习16.32
> 在模版实参推断过程中发生了什么？

对于函数模板，编译器利用调用中的函数实参来确定其模板参数，从函数实参来确定模板实参的过程称为模板类型推断。在模版实参推断过程中，编译器使用函数调用中的实参类型来寻找模版实参，用这些模版实参生成的函数版本与给定的函数调用最为匹配。

## 练习16.33
> 指出在模版实参推断过程中允许对函数实参进行的两种类型转换。

1. const 转换：可以将一个非 const 对象的引用（或指针）传递给一个 const 的引用（或指针）形参。
2. 数组或函数指针转换：如果函数形参不是引用类型，则可以对数组或函数类型的实参应用正常的指针转换。一个数组实参可以转换为一个指向其首元素的指针。类似的，一个函数实参可以转换为一个该函数类型的指针。

## 练习16.34
> 对下面的代码解释每个调用是否合法。如果合法，T 的类型是什么？如果不合法，为什么？
```cpp
template <class T> int compare(const T&, const T&);
(a) compare("hi", "world");
(b) compare("bye", "dad");
```
(a) 不合法。函数实参是`(const char[3], const char[6])`，由第一个参数推断出的`T`是`char[3]`，第二个参数推断出的`T`是`char[6]`，二者不匹配。  
(b) 合法。函数实参是`(const char[4], const char[4])`，推断出的`T`是`char[4]`类型。  

## 练习16.35
> 下面调用中哪些是错误的（如果有的话）？如果调用合法，T 的类型是什么？如果调用不合法，问题何在？
```cpp
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
double d; float f; char c;
(a) calc(c, 'c');  (b) calc(d, f);
(c) fcn(c, 'c');   (d) fcn(d, f);
```
(a) 合法，`T`的类型是`char`。  
(b) 合法，`T`的类型是`double`。  
(c) 合法，`T`的类型是`char`。  
(d) 非法，由第一个参数编译器推断出`T`的类型为`double`，模板中两个参数类型都是`T`，因此第二个参数也应该为`double`类型，但第二个参数却是`float`，类型不匹配。  

## 练习16.36
> 进行下面的调用会发生什么：
```cpp
template <typename T> f1(T, T);
template <typename T1, typename T2) f2(T1, T2);
int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
(a) f1(p1, p2);    (b) f2(p1, p2);
(c) f1(cp1, cp2);  (d) f2(cp1, cp2);
(e) f1(p1, cp1);   (f) f2(p1, cp1);
```
函数模板`f1`和`f2`没有返回类型，是错误的。`f2`的模板参数列表应该用`< >`扩起来，而不是用`< )`。  
假设返回`void`，`f2`模板参数列表修正为尖括号。  
(a) 合法，`T`的类型为`int *`。  
(b) 合法，`T1`的类型为`int *`，`T2`的类型为`int *`。  
(c) 合法，`T`的类型是`const int *`。  
(d) 合法，`T1`的类型是`const int *`，`T2`的类型是`const int *`。  
(e) 非法，由第一个参数推断出`T`的类型是`int *`，模板要求第二个参数也是`int *`，但传递的却是`const int *`。  
(f) 合法，`T1`的类型是`int *`，`T2`的类型是`const int *`。  

## 练习16.37
> 标准库 max 函数有两个参数，它返回实参中的较大者。此函数有一个模版类型参数。你能在调用 max 时传递给它一个 int 和一个 double 吗？如果可以，如何做？如果不可以，为什么？

标准库`max`函数模板有一个模板参数`T`，接受的两个参数都是类型`T`。  
由于模板实参推断过程中，不会进行算术转换，因此`max(1, 2.0)`的形式调用该函数是非法的，编译器从第一个参数推断出类型`T`是`int`，而传递进来的第二个参数类型却是`double`。  
如果一定要传递一个`int`和一个`double`，需要提供显式模板实参，之后函数参数就可以进行正常的类型转换。因此需要以`max<double>(1, 2.0)`的形式调用。  

## 练习16.38
> 当我们调用 make_shared（参见 12.1.1 节，第 401 页）时，必须提供一个显式模版实参。解释为什么需要显式模版实参以及它是如何使用的。

`make_shared`的参数是模板实参类型的构造函数的参数，而该类型的构造函数的参数可能是`0`个，也可能是任意类型的任意个参数，无法仅从由参数列表推断出该类型是什么，因此必须提供显式模板实参。  

## 练习16.39
> 对 16.1.1节（第 578 页）中的原始版本的 compare 函数，使用一个显式模版实参，使得可以向函数传递两个字符串字面常量。
```cpp
compare<std::string>("a", "bb");  
```

## 练习16.40
> 下面的函数是否合法？如果不合法，为什么？如果合法，对可以传递的实参类型有什么限制（如果有的话）？返回类型是什么？
```cpp
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	// 处理序列
	return *beg; // 返回序列中一个元素的拷贝
}
```
合法。但对`IT`解引用得到的类型必须支持与`0`的加法运算符。  
函数的返回类型取决于`+`运算符的返回类型。  

## 练习16.41
> 编写一个新的 sum 版本，它返回类型保证足够大，足以容纳加法结果。
```cpp
template <typename T1,typename T2>
auto sum(T1 a, T2 b)->decltype(a + b) {
	return a + b;
}
```
根据本节内容，以上代码似乎显而易见，但`decltype`并不计算表达式，它得到的类型仅仅是加法运算符的返回类型（通常是`a`或`b`中更大的那个），不能保证足够大以容纳返回结果。例如两个`int`类型中最大的数相加，`decltype(a +b)`仍然是`int`，显然无法容纳结果。  
```cpp
long long sum(long long a, long long b) {
	return a + b;
}
long double sum(long double a, long double b) {
	return a + b;
}
```
直接将返回类型定位最大的类型，能容纳大多数情况，但若将两个`long long`中最大的数相加，仍然无法容纳返回结果。  
显然仅利用内置类型作为返回结果无法完成该任务，需要利用一定的数据结构编写用于大数计算的类。  

## 练习16.42
> 对下面每个调用，确定 T 和 val 的类型：
```cpp
template <typename T> void g(T&& val);
int i = 0; const int ci = i;
(a) g(i);  (b) g(ci);  (c) g(i * ci);
```
(a) `T`的类型是`int &`，`val`的类型是`int &`。  
(b) `T`的类型是`const int &`，`val`的类型是`const int &`。  
(c) `T`的类型是`int`，`val`的类型是`int &&`。  

## 练习16.43
> 使用上一题定义的函数，如果我们调用 g(i = ci)，g 的模版参数将是什么？

赋值运算符返回左值对象的引用，因此`T`的类型是`int &`，`val`的类型是`int &`。  

## 练习16.44
> 使用与第一题中相同的三个调用，如果 g 的函数参数声明为 T（而不是T&&），确定 T 的类型。如果 g 的函数参数是 const T& 呢？

如果参数声明为`T`，则`T`的类型都是`int`，因为在模板实参推断过程中，顶层`const`会被忽略，所以即便传递的是`const int`，推断出的仍然是`int`。  
如果参数声明为`const T&`，则`T`的类型都是`int`，因为const已经是函数参数类型的一部分，它不会也是模板参数类型的一部分。  

## 练习16.45
> 给定下面的模版，如果我们对一个像 42 这样的字面常量调用 g，解释会发生什么？如果我们对一个 int 类型的变量调用 g 呢？
```cpp
template <typename T> void g(T&& val) { vector<T> v; }
```
使用`42`调用`g`，T的类型被推断为`int`。`v`是保存`int`的`vector`。  
使用`int`类型变量调用`g`，T的类型被推断为`int &`。`vector`在动态内存空间中保存元素，需要维护指向动态内存空间的指针，这个指针的类型是指向元素类型的指针，由于引用不是对象，不能定义引用的指针，因此`vector<T> v;`会编译失败。  

## 练习16.46
> 解释下面的循环，它来自 13.5 节（第 469 页）中的 StrVec::reallocate:
```cpp
for (size_t i = 0; i != size(); ++i)
	alloc.construct(dest++, std::move(*elem++));
```
`elem`是一个`string`指针，对它解引用得到一个`string`的左值，通过`std::move`返回一个绑定到这个左值的右值引用。`construct`将这个右值引用传递给`string`的构造函数，它匹配了`string`的移动构造函数，因此`construct`会调用`string`的移动构造函数将数据从旧空间移动到新空间，从而避免了不必要的拷贝。  

## [练习16.47](ex16_47.cpp)
> 编写你自己版本的翻转函数，通过调用接受左值和右值引用参数的函数来测试它。

## [练习16.48](ex16_48.cpp)
> 编写你自己版本的 debug_rep 函数。

## 练习16.49
> 解释下面每个调用会发生什么：
```cpp
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);
int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;
g(42); g(p); g(ci); g(p2);
f(42); f(p); f(ci); f(p2);
```
1. `g(42)`的可行函数只有`g(T)`，`T`是`int`，参数列表`(int)`。  
2. `g(p)`的可行函数有：   
  - `g(T)`，`T`是`int *`，参数列表`(int *)`。   
  - `g(T*)`，`T`是`int`，参数列表`(int *)`。  
  - 二者都是精确匹配，`g(T*)` 更特例化，因此选择它。  
3. `g(ci)`的可行函数只有`g(T)`，`T`是`int`，参数列表是`(int)`，顶层`const`被忽略。  
4. `g(p2)`的可行函数有：  
  - `g(T)`，`T`是`const int *`，参数列表`(const int *)`。  
  - `g(T*)`，`T`是`const int`，参数列表`(const int *)`。  
  - 二者都是精确匹配，`g(T*)` 更特例化，因此选择它。  
5. `f(42)`的可行函数只有`f(T)`，`T`是`int`，参数列表`(int)`。  
6. `f(p)`的可行函数有：  
  - `f(T)`，`T`是`int *`，参数列表`(int *)`。  
  - `f(const T*)`，`T`是`int`，参数列表`(const int *)`。  
  - `f(T)`是精确匹配，`f(const T*)`需要一次从非`const`指针到`const`指针的转换。因此选择`f(T)`。  
7. `f(ci)`的可行函数只有`f(T)`，T是`int`，参数列表`(int)`，顶层`const`被忽略。  
8. `f(p2)`的可行函数有：
  - `f(T)`，`T`是`const int *`，参数列表`(const int *)`。  
  - `f(const T*)`，`T`是`int`，参数列表`(const int *)`。  
  - 二者都是精确匹配，`f(const T*)`更特例化，因此选择它。  

## [练习16.50](ex16_50.cpp)
> 定义上一个练习中的函数，令它们打印一条身份信息。运行该练习中的代码。如果函数调用的行为与你预期不符，确定你理解了原因。

## 练习16.51
> 调用本节中的每个 foo，确定 sizeof...(Args) 和 sizeof...(rest)分别返回什么。

`foo(i, s, 42, d)`返回`3`和`3`。  
`foo(s, 42, "hi")`返回`2`和`2`。  
`foo(d, s)`返回`1`和`1`。  
`foo("hi")`返回`0`和`0`。  

## [练习16.52](ex16_52.cpp)
> 编写一个程序验证上一题的答案。

## [练习16.53](ex16_53.cpp)
> 编写你自己版本的 print 函数，并打印一个、两个及五个实参来测试它，要打印的每个实参都应有不同的类型。 

## 练习16.54
> 如果我们对一个没有 << 运算符的类型调用 print，会发生什么？

`os << `语句编译失败。  

## 练习16.55
> 如果我们的可变参数版本 print 的定义之后声明非可变参数版本，解释可变参数的版本会如何执行。

对于打印一个实参的情况，可以正常运行，因为会匹配非可变参数版本。  
对于打印多于一个实参的情况，会在编译时无限递归，以至于找不到可以匹配的版本。  
例如`print(cout, 1, 2.5, 'c')`。编译时返回语句第一次调用`print(cout, 2.5, 'c')`，第二次调用`print(cout, 'c')`，第三次调用`print(cout)`但找不到任何可匹配的模板，编译失败。  

## [练习16.56](ex16_56.cpp)
> 编写并测试可变参数版本的 errorMsg。

## 练习16.57
> 比较你的可变参数版本的 errorMsg 和 6.2.6 节（第 198 页）中的 error_msg 函数。两种方法的优点和缺点各是什么？

`initializer_list`版本的优点是编写简单、清楚。缺点是必须提供显式模板参数，还要求传递的参数能转换为模板参数类型类型。同时参数必须放在花括号里。当需要新类型时必须编写新的函数。    
可变参数版本的优点是不限参数类型，参数也不必放在花括号里。缺点是编写相对复杂，需要使用模板。  

## [练习16.58](ex16_58)
> 为你的 StrVec 类及你为 16.1.2 节（第 591 页）练习中编写的 Vec 类添加 emplace_back 函数。

## 练习16.59
> 假定 s 是一个 string，解释调用 svec.emplace_back(s) 会发生什么。

`emplace_back`对参数包进行扩展，将每个形参都是右值引用。  
传递一个左值的`string`，将调用`svec.emplace_back(string &&s)`。由于引用折叠，`s`仍是一个左值引用。在函数内通过`std::forward<string>(s)`转发参数，结果仍是一个左值引用，最终`construct`将一个`string`的左值引用传递给`string`的构造函数，这会调用`string`的拷贝构造函数。  

## 练习16.60
> 解释 make_shared（参见 12.1.1 节，第 401 页）是如何工作的。

`make_shared`是有可变参数的函数模板，它接受参数包，经过扩展后转发给模板参数的构造函数来构造一个对象（例如转发给`new`），最后返回一个指向该对象的智能指针。  

## [练习16.61](ex16_61)
> 定义你自己版本的 make_shared。

## [练习16.62](ex16_62)
> 定义你自己版本的 hash<Sales_data>, 并定义一个 Sales_data 对象的 unorder_multiset。将多条交易记录保存到容器中，并打印其内容。

## [练习16.63](ex16_63.cpp)
> 定义一个函数模版，统计一个给定值在一个 vecor 中出现的次数。测试你的函数，分别传递给它一个 double 的 vector，一个 int 的 vector 以及一个 string 的 vector。

## [练习16.64](ex16_64.cpp)
> 为上一题的模版编写特例化版本来处理 vector< const char* >。编写程序使用这个特例化版本。

## [练习16.65](ex16_65.cpp)
> 在 16.3 节（第 617 页）中我们定义了两个重载的 debug_rep 版本，一个接受 const char* 参数，另一个接受 char * 参数。将这两个函数重写为特例化版本。

## 练习16.66
> 重载 debug_rep 函数与特例化它相比，有何优点和缺点？

重载函数的优点是当非模板函数提供与函数模板同样好的匹配时，会选择非模板版本。它的缺点同样是会影响函数匹配，当重载函数较多时，彼此之间的影响可能可能出现预期之外的匹配情况。  
特例化版本的优点是不影响函数匹配，它只是为模板提供一个特殊实例，这个实例有自己专门的定义。  

## 练习16.67
> 定义特例化版本会影响 debug_rep 的函数匹配吗？如果不影响，为什么？

不影响，因为它只是为模板提供一个特殊实例，不参与函数匹配过程。  
当编译器通过函数匹配过程选中某个函数模板后，编译器不会从模板实例化一个函数，而是直接使用这个特例化的版本。  