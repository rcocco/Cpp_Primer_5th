## 练习15.1
> 什么是虚成员？

在基类中声明为`virtual`的函数是虚函数，任何构造函数之外的非`static`函数都可以是虚函数，基类中的虚函数在派生类中隐式地也是虚函数。  
对于某些函数，当基类希望它的派生类定义适合自身的版本，基类就将函数声明为虚函数。  使用基类的引用或指针调用一个虚函数时会发生动态绑定，函数的解析过程发生在运行时，基类引用或指针实际绑定或指向的类型，决定了运行时选择函数的版本。  

## 练习15.2
> protected 访问说明符与 private 有何区别？

`protected`：可以被该类的成员、该类的友元，以及其派生类的成员访问。  
`private`：可以被该类的成员、该类的友元访问。  

## [练习15.3](ex15_03)
> 定义你自己的 Quote 类和 print_total 函数。

## 练习15.4
> 下面哪条声明语句是不正确的？请解释原因。
```cpp
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```

(a) 不正确，被作用基类的类必须已经定义，因此它不能继承它本身。  
(b) 正确。  
(c) 不正确，声明语句的目的是令程序知晓某个名字的存在以及该名字表示什么样的实体（类、函数、变量），派生列表以及与定义有关的细节必须与类的主体一起出现。  

## [练习15.5](ex15_05)
> 定义你自己的 Bulk_quote 类。

## [练习15.6](ex15_06/main.cpp)
> 将 Quote 和 Bulk_quote 的对象传给 15.2.1 节（第 529 页）练习中的 print_total 函数，检查该函数是否正确。

## [练习15.7](ex15_07)
> 定义一个类使其实现一种数量受限的折扣策略，具体策略是：当购买书籍的数量不超过一个给定的限量时享受折扣，如果购买量一旦超过了限量，则超出的部分将以原价销售。

## 练习15.8
> 给出静态类型和动态类型的定义。

静态类型是变量声明时的类型或表达式生成的类型，它在编译时总是已知的。  
动态类型是变量或表达式表示的内存中的对象的类型。它直到运行时才可知。  

## 练习15.9
> 在什么情况下表达式的静态类型可能与动态类型不同？请给出三个静态类型与动态类型不同的例子。

基类的指针或引用的静态类型可能与其动态类型不一致。如果表达式既不是引用也不是指针，则它的动态类型永远与静态类型一致。  
```cpp
Bulk_quote bulk;
const Bulk_quote cbulk;
Quote *p = &bulk;
Quote &r = bulk;
const Quote *cp = &cbulk;
const Quote &cr = &cbulk;
```

## 练习15.10
> 回忆我们在 8.1 节（第 279 页）进行的讨论，解释第 284 页中将 ifstream 传递给 Sales_data 的 read 函数的程序是如何工作的。

`read`的参数是`istream`引用，而`ifstream`类是`istream`的派生类，因此可以给函数传递一个`ifstream`对象，基类的引用会绑定到该派生类对象上。  

## [练习15.11](ex15_11)
> 为你的 Quote 类体系添加一个名为 debug 的虚函数，令其分别显示每个类的数据成员。

## 练习15.12
> 有必要将一个成员函数同时声明成 override 和 final 吗？为什么？

有必要。`override`和`final`都是虚函数的说明符，它们无法用于非虚函数。  
`override`的作用是通知编译器这个函数的目的是要覆盖基类中的虚函数，如果没有覆盖已存在的虚函数则报错。  
`final`的作用是禁止它的派生类覆盖该虚函数。  
因此，如果在一个类中，我们需要覆盖基类中的某个虚函数，同时又不希望该类的派生类覆盖这个虚函数，那么应该将该虚函数同时声明成`override`和`final`的。  

## 练习15.13
> 给定下面的类，解释每个 print 函数的机理：
```cpp
class base {
public:
	string name() { return basename;}
	virtual void print(ostream &os) { os << basename; }
private:
	string basename;
};
class derived : public base {
public:
	void print(ostream &os) { print(os); os << " " << i; }
private:
	int i;
};
```
> 在上述代码中存在问题吗？如果有，你该如何修改它？

存在问题，`derived`类的`print`函数中调用了自己，这导致函数无限递归。  
程序的目的是调用基类版本的`print`，应使用作用域运算符指明：  
```cpp
void print(ostream &os) { base::print(os); os << " " << i; }
```

## 练习15.14
> 给定上一题中的类以及下面这些对象，说明在运行时调用哪个函数：
```cpp
base bobj; 		base *bp1 = &bobj; 	base &br1 = bobj;
derived dobj; 	base *bp2 = &dobj; 	base &br2 = dobj;
(a)bobj.print();	(b)dobj.print();	(c)bp1->name();
(d)bp2->name();		(e)br1.print();		(f)br2.print();
```

(a) 非引用和指针，编译时根据静态类型`base`确定调用`base::print()`  
(b) 非引用和指针，编译时根据静态类型`derived`确定调用`derived::print()`  
(c) `base`指针，调用非虚函数`name()`，编译时根据静态类型`base`确定调用`base::name()`  
(d) `base`指针，调用非虚函数`name()`，编译时根据静态类型`base`确定调用`base::name()`  
(e) `base`引用，调用虚函数`print()`，运行时根据动态类型`base`确定调用`base::print()`  
(f) `base`引用，调用虚函数`print()`，运行时根据动态类型`derived`确定调用`derived::print()`  

## [练习15.15](ex15_15)
> 定义你自己的 Disc_quote 和 Bulk_quote。

## [练习15.16](ex15_16)
> 改写你在 15.2.2 节（第 533 页）练习中编写的数量受限的折扣策略，令其继承 Disc_quote。

## 练习15.17
> 尝试定义一个 Disc_quote 的对象，看看编译器给出的错误信息是什么？

不允许使用抽象类类型"Disc_quote"的对象：函数"Disc_quote::net_price"是纯虚函数

## 练习15.18
> 假设给定了第 543 页和第 544 页的类，同时已知每个对象的类型如注释所示，判断下面的哪些赋值语句是合法的。解释那些不合法的语句为什么不被允许：
```cpp
Base *p = &d1;  // d1 的类型是 Pub_Derv
p = &d2;		// d2 的类型是 Priv_Derv
p = &d3;		// d3 的类型是 Prot_Derv
p = &dd1;		// dd1 的类型是 Derived_from_Public	
p = &dd2;		// dd2 的类型是 Derived_from_Private
p = &dd3;		// dd3 的类型是 Derived_from_Protected
```
只有派生类公有继承基类时，用户代码才能使用派生类向基类的转换。  
第一行合法，`Pub_Derv`公有继承`Base`。  
第二行不合法，`Priv_Derv`私有继承`Base`。  
第三行不合法，`Prot_Derv`保护继承`Base`。  
第四行合法，`Derived_from_Public`公有继承`Pub_Derv`，因此用户代码可以使用`Derived_from_Public`向`Pub_Derv`的转换，又因为`Pub_Derv`公有继承`Base`，所以用户代码可以使用`Pub_Derv`向`Base`的转换，最终`Derived_from_Public`转换为`Pub_Derv`再转换为`Base`是可行的。  
第五行不合法，`Derived_from_Private`公有继承`Priv_Derv`，因此用户代码可以使用``Derived_from_Private``向`Priv_Derv`的转换，但`Priv_Derv`私有继承`Base`，所以用户代码不能使用`Priv_Derv`向`Base`的转换，最终`Derived_from_Private`转换为`Priv_Derv`再转换为`Base`是不可行的。  
第六行不合法，`Derived_from_Protected`公有继承`Prot_Derv`，因此用户代码可以使用``Derived_from_Protected``向`Prot_Derv`的转换，但`Prot_Derv`保护继承`Base`，所以用户代码不能使用`Prot_Derv`向`Base`的转换，最终`Derived_from_Protected`转换为`Prot_Derv`再转换为`Base`是不可行的。  

## 练习15.19
> 假设 543 页和 544 页的每个类都有如下形式的成员函数：
```cpp
void memfcn(Base &b) { b = *this; }
```
> 对于每个类，分别判断上面的函数是否合法。

`b = *this`调用了`Base`类的拷贝赋值运算符`Base &operator=(const Base &)`，这意味着需要对`*this`也就是定义了这个函数的类的对象进行向`Base`的转换。  
不管派生类以什么方式继承基类，派生类的成员函数和友元都能使用派生类向基类的转换。因此定义在`Pub_Derv`、`Priv_Derv`、`Prot_Derv`是合法的。  
如果一个类`D`公有或保护继承基类`B`，那么`D`的派生类`DD`的成员和友元可以使用`D`向`B`的类型转换，同时根据上一段的规则，无论`DD`如何继承`D`，`DD`的成员和友元都可以使用`DD`向`D`的转换，所以`DD`转换为`D`再转换`B`是可行的。因此定义在`Derived_from_Public`和`Derived_from_Private`是合法的。  

由于`Priv_Derv`私有继承`Base`，因此`Priv_Derv`的派生类`Derived_from_Private`不能使用`Priv_Derv`向`Base`的转换，所以`Derived_from_Private`向`Base`的转换也是不可行的，函数体的`b = *this`语句非法。  
除了该语句的错误，`Derived_from_Private`中`memfcn`函数的参数`Base &`也是非法的，类名`Base`不可访问。原因是`private`继承访问说明符将**注入类名(injected-class-name)**变成了私有成员。  
在类的作用域内，当前类的类名作为公有成员被加入到类中，这叫做[注入类名](https://timsong-cpp.github.io/cppwp/n3337/class#2)。例如：
```cpp
int A() { return 1; }
struct A {
	void f() { auto d = A(); }
};
```
在上述代码中，由于类名也是类的成员，它隐藏了外层作用域中的名字，`A()`将返回该类的对象，而不是调用函数`int A()`，所以`d`的类型是`A`而不是`int`。  
由于`Priv_Derv`私有继承`Base`，在`Priv_Derv`中，公有的注入类名`Base`被变成了私有的，因此`Priv_Derv`的派生类`Derived_from_Private`也就无法访问基类中的私有注入类名`Base`。尽管注入类名`Base`无法访问，但它依然隐藏了外部作用域中的`Base`类名，所以名字查找在找到注入类名`Base`时就停止了。C++11标准对此的规定参见：[class.access.spec](https://timsong-cpp.github.io/cppwp/n3337/class.access.spec#5)    
要想使用外部作用域中的类名而非注入类名，可以使用作用域运算符：  
```cpp
void memfcn(::Base &b) { b.pub_mem(); }
```

## [练习15.20](ex15_20.cpp)
> 编写代码检验你对前面两题的回答是否正确。

## 练习15.21
> 从下面这些一般性抽象概念中任选一个（或者选一个你自己的），将其对应的一组类型组织成一个继承体系：  
> (a) 图形文件格式（如gif、tiff、jpeg、bmp）  
> (b) 图形基元（如方格、圆、球、圆锥）  
> (c) C++语言中的类型（如类、函数、成员函数）  

以图形基元为例，继承体系可按以下形式组织：  
- 图形
  - 二维图形
     - 方格
     - 圆
  - 三维图形
     - 球
     - 圆锥

## [练习15.22](ex15_22)
> 对于你在上一题中选择的类，为其添加合适的虚函数及公有成员和受保护的成员。

## 练习15.23
> 假设第 550 页的 D1 类需要覆盖它继承而来的 fcn 函数，你应该如何对其进行修改？如果你修改之后 fcn 匹配了 Base 中的定义，则该节的那些调用语句将如何解析？

在`D1`中增加`int fcn()`函数。  
修改之后`bp2->fcn()`将在运行时调用`D1::fcn`。其他调用语句的解析仍和书中所写相同。  

## 练习15.24
> 哪种类需要虚析构函数？虚析构函数必须执行什么样的操作？

基类需要虚析构函数，以保证在删除指向动态分配对象的基类指针时，能根据指针所指的对象的动态类型来调用恰当的析构函数。  
虚析构函数需要负责销毁类的成员，如果该类没有指针成员，虚析构函数的函数体部分可以为空。  

## 练习15.25
> 我们为什么为 Disc_quote 定义一个默认构造函数？如果去掉该构造函数的话会对 Bulk_quote 的行为产生什么影响？

由于`Disc_quote`定义了其他构造函数，编译器不会为其合成默认构造函数，去掉显式定义的合成默认构造函数后，`Disc_quote`将没有默认构造函数。  
由于`Disc_quote`类没有默认构造函数，派生类`Bulk_quote`的默认构造函数`Bulk_quote() = default`将是被删除的，因为编译器不能使用基类的默认构造函数来初始化派生类对象的基类部分，除非不由编译器合成，而是显式定义`Bulk_quote`的默认构造函数来完成基类部分的初始化工作。  

## [练习15.26](ex15_26)
> 定义 Quote 和 Bulk_quote 的拷贝控制成员，令其与合成的版本行为一致。为这些成员以及其他构造函数添加打印状态的语句，使得我们能够知道正在运行哪个程序。使用这些类编写程序，预测程序将创建和销毁哪些对象。重复实验，不断比较你的预测和实际输出结果是否相同，直到预测完全准确再结束。

## [练习15.27](ex15_27/Bulk_quote.h)
> 重新定义你的 Bulk_quote 类，令其继承构造函数。

## [练习15.28](ex15_28)
> 定义一个存放 Quote 对象的 vector，将 Bulk_quote 对象传入其中。计算 vector 中所有元素总的 net_price。

## 练习15.29
> 再运行一次你的程序，这次传入 Quote 对象的 shared_ptr 。如果这次计算出的总额与之前的不一致，解释为什么；如果一致，也请说明原因。

上一题`vector`中存放的是`Quote`对象，传入`Bulk_quote`对象后触发了`Quote`的拷贝构造函数，它只拷贝基类部分，派生类部分被忽略了。之后通过`Quote`对象而非指针或引用调用虚函数，实际调用的版本就是静态类型`Quote`的版本。  
本题`vector`中存放的是指向`Quote`的智能指针，传入`shared_ptr<Bulk_quote>`对象后拷贝的是智能指针，而通过指向`Quote`的智能指针调用虚函数，实际调用的函数是智能指针所指对象的动态类型`Bulk_quote`的版本。  

## [练习15.30](ex15_30)
> 编写你自己的 Basket 类，用它计算上一个练习中交易记录的总价格。

## 练习15.31
> 已知 s1、s2、s3 和 s4 都是 string，判断下面的表达式分别创建了什么样的对象：
> (a) Query(s1) | Query(s2) & ~Query(s3);
> (b) Query(s1) | (Query(s2) & ~Query(s3));
> (c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));

(a) 等价于`Query(s1) | (Query(s2) & (~Query(s3)))`。  
`Query(s3)`创建了绑定到`WordQuery`的`Query`对象，`~Query(s3)`创建了绑定到`NotQuery`的`Query`对象，`Query(s2)`创建了绑定到`WordQuery`的`Query`对象，`Query(s2) & (~Query(s3))`创建了绑定到`AndQuery`的`Query`对象，`Query(s1)`创建了绑定到`WordQuery`的`Query`对象，`Query(s1) | (Query(s2) & (~Query(s3)))`创建了绑定到`OrQuery`的`Query`对象。  
(b) 与(a)相同。  
(c) `Query(s1)`创建了绑定到`WordQuery`的`Query`对象，`(Query(s2))`创建了绑定到`WordQuery`的`Query`对象，`(Query(s1) & (Query(s2))`创建了绑定到`AndQuery`的`Query`对象，`Query(s3)`创建了绑定到`WordQuery`的`Query`对象，`Query(s4)`创建了绑定到`WordQuery`的`Query`对象，`(Query(s3) & Query(s4))`创建了绑定到`AndQuery`的`Query`对象，`(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)))`创建了绑定到`OrQuery`的`Query`对象。  

## 练习15.32
> 当一个 Query 类型的对象被拷贝、移动、赋值或销毁时，将分别发生什么？

`Query`类型没有定义拷贝控制成员，编译器会为其合成相关的拷贝控制成员，即对各成员逐个拷贝、移动、赋值或销毁。  
`Query`类只有一个`shared_ptr`成员，因此`Query`类合成的拷贝控制成员会调用`shared_ptr`类的拷贝控制成员完成相关操作。  

## 练习15.33
> 当一个 Query_base 类型的对象被拷贝、移动、赋值或销毁时，将分别发生什么？

`Query_base`是一个抽象基类，因此无法定义一个`Query_base`类型对象。  
`Query_base`的派生类执行相关操作时，会调用`Query_base`的拷贝控制成员来执行对基类部分的拷贝控制。  
由于`Query_base`没有定义自己的拷贝控制成员，编译器会为其合成拷贝控制成员，即对各成员逐个拷贝、移动、赋值或销毁，又因为`Query_base`没有数据成员，合成的拷贝控制成员什么也不会做。  

## 练习15.34
> 针对图 15.3（第 565 页）构建的表达式：
> (a) 列举出在处理表达式的过程中执行的所有构造函数。
> (b) 列举出 cout << q 所调用的 rep。
> (c) 列举出 q.eval() 所调用的 eval。

(a) 对于表达式`Query q = Query("fiery") & Query("bird") | Query("wind");`：  
1. `Query("fiery")`、`Query("bird")`和`Query("wind")`调用了`Query(const string &s)`，又调用了`WordQuery(const string &s)`。  
2. `Query("fiery") & Query("bird")`调用了`AndQuery(const Query , const Query &)`，又调用了`BinaryQuery(const Query &, const Query &, string)`，随后调用了两次`Query`的拷贝构造函数。  
3. `Query("fiery") & Query("bird") | Query("wind")`调用了`OrQuery(const Query &, const Query &)`，又调用了`BinaryQuery(const Query &, const Query &, string)`，随后调用了两次`Query`的拷贝构造函数。  
4. 最后`=`号调用了`Query(shared_ptr<Query_base>)`。  

(b)    
1. `Query::rep()`，其中指针`q`所指对象的动态类型是`OrQuery`。  
2. `BinaryQuery::rep()`，其中`lhs = Query("fiery") & Query("bird")`，`rhs = Query("wind")`。  
3. `Query::rep()`，其中指针`q`所指对象的动态类型是`AndQuery`。  
4. `BinaryQuery::rep()`，其中`lhs = Query("fiery")`，`rhs = Query("bird")`。  
5. `Query::rep()`，其中指针`q`所指对象的动态类型是`WordQuery`。  
6. `WordQuery::rep()`  
7. `Query::rep()`，其中指针`q`所指对象的动态类型是`WordQuery`。 
8. `WordQuery::rep()`  
9. `Query::rep()`，其中指针`q`所指对象的动态类型是`WordQuery`。 
10. `WordQuery::rep()`   

(c)  
1. `Query::eval()`，其中指针`q`所指对象的动态类型是`OrQuery`。  
2. `OrQuery::eval()`，其中`lhs = Query("fiery") & Query("bird")`，`rhs = Query("wind")`。  
3. `Query::eval()`，其中指针`q`所指对象的动态类型是`AndQuery`。  
4. `AndQuery::eval()`，其中`lhs = Query("fiery")`，`rhs = Query("bird")`。  
5. `Query::eval()`，其中指针`q`所指对象的动态类型是`WordQuery`。  
6. `WordQuery::eval()`  
7. `Query::eval()`，其中指针`q`所指对象的动态类型是`WordQuery`。 
8. `WordQuery::eval()`  
9. `Query::eval()`，其中指针`q`所指对象的动态类型是`WordQuery`。 
10. `WordQuery::eval()`   

## [练习15.35](ex15_35)
> 实现 Query 类和 Query_base 类，其中需要定义rep 而无须定义 eval。

## [练习15.36](ex15_36/main.cpp)
> 在构造函数和 rep 成员中添加打印语句，运行你的代码以检验你对本节第一个练习中(a)、(b) 两小题的回答是否正确。

(a) 构造函数的调用顺序和语句输出顺序是相反的，因为构造函数初始值列表调用了其他构造函数，而函数体在初始值列表执行完之后才执行。  
(b) 对于`Query("a") | Query("b")`，求值顺序是未定义的，因此编译器可能先对`Query("b")`求值也可能先对`Query("a")`求值，这导致输出顺序可能有略微不同（第一个练习中描述的顺序是假定先求值左边再求值右边）。    

## 练习15.37
> 如果在派生类中含有 shared_ptr<Query_base> 类型的成员而非 Query 类型的成员，则你的类需要做出怎样的改变？

凡是用到`Query`的地方都需要换成`shared_ptr<Query_base>`，而且需要直接创建派生类对象，才能让基类指针绑定到其上面。例如之前表达式中的`Query("fiery")`将变成`shared_ptr<Query_base>(new WordQuery("fiery"))`。  

## 练习15.38
> 下面的声明合法吗？如果不合法，请解释原因；如果合法，请指出该声明的含义。
```cpp
BinaryQuery a = Query("fiery") & Query("bird");
AndQuery b = Query("fiery") & Query("bird");
OrQuery c = Query("fiery") & Query("bird");
```

1. 不合法。`BinaryQuery`是抽象类，不能定义抽象类的对象。同时`&`返回的是`Query`对象，不能把`Query`转换成`BinaryQuery`。  
2. 不合法。`&`返回的是`Query`对象，不能把`Query`转换成`AndQuery`。  
3. 不合法。`&`返回的是`Query`对象，不能把`Query`转换成`OrQuery`。  

## [练习15.39](ex15_39)
> 实现 Query 类和 Query_base 类，求图 15.3（第 565 页）中表达式的值并打印相关信息，验证你的程序是否正确。

## 练习15.40
> 在 OrQuery 的 eval 函数中，如果 rhs 成员返回的是空集将发生什么？如果 lhs 是空集呢？如果 lhs 和 rhs 都是空集又将发生什么？

`set`接受迭代器范围的构造函数与`insert`成员函数都能正确处理当迭代器范围为空的情况，此时它们不会添加任何元素。  

## [练习15.41](ex15_41)
> 重新实现你的类，这次使用指向 Query_base 的内置指针而非 shared_ptr。请注意，做出上述改动后你的类将不能再使用合成的拷贝控制成员。

## [练习15.42](ex15_42)
> 从下面的几种改进中选择一种，设计并实现它:
> (a) 按句子查询并打印单词，而不再是按行打印。
> (b) 引入一个历史系统，用户可以按编号查阅之前的某个查询，并可以在其中添加内容或者将其与其他查询组合。
> (c) 允许用户对结果做出限制，比如从给定范围的行中挑出匹配的进行显示。