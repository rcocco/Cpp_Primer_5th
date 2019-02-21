## [练习19.1](ex19_01.cpp)
> 使用 malloc 编写你自己的 operator new(sizt_t) 函数，使用 free 编写 operator delete(void *) 函数。

## [练习19.2](ex19_02)
> 默认情况下，allocator 类使用 operator new 获取存储空间，然后使用 operator delete 释放它。利用上一题中的两个函数重新编译并运行你的 StrVec 程序（参见 13.5 节，第 465 页）。

## 练习19.3
> 已知存在如下的类继承体系，其中每个类分别定义了一个公有的默认构造函数和一个析构函数：
```cpp
class A { /* ... */};
class B : public A { /* ... */};
class C : public B { /* ... */};
class D : public B, public A { /* ... */};
```
> 下面哪个 dynamic_cast 将失败？
```cpp
(a) A *pa = new C;
	B *pb = dynamic_cast<B*>(pa);
(b) B *pb = new B;
	C *pc = dynamic_cast<C*>(pb);
(c) A *pa = new D;
	B *pb = dynamic_cast<B*>(pa);
```
(b) 将失败，因为指针`B`实际指向的就是一个`B`类型对象，它不包含派生类`C`的部分，因此不能让一个指向派生类对象的指针去指向基类对象。  
(c) `A *pa  = new D;`存在二义性，不清楚所指向的由`B`继承来的`A`子对象，还是直接继承来的`A`子对象。  

## 练习19.4
> 使用上一个练习定义的类改写下面的代码，将表达式 *pa 转换成类型 C&：
```cpp
if (C *pc = dynamic_cast<C*>(pa))
{
	//使用C的成员
} else {
	//使用A的成员
}
```
应改为：
```cpp
try{
    C &pc = dynamic_cast<C&>(*pa);
    //使用C的成员
}catch(bad_cast){
    //使用A的成员
}
```

## 练习19.5
> 在什么情况下你应该用 dynamic_cast 替代虚函数？

如果不能改动基类使某个函数成为虚函数，又希望通过传递基类指针来调用在派生类中新增加的函数，此时应该使用`dynamic_cast`将基类指针转换为派生类指针，再进行调用。  

## [练习19.6](ex19_06.cpp)
> 编写一条表达式将 Query_base 指针动态转换为 AndQuery 指针（参见 15.9.1 节，第 564 页）。分别使用 AndQuery 的对象以及其他类型的对象测试转换是否有效。打印一条表示类型转换是否成功的信息，确保实际输出的结果与期望的一致。

## [练习19.7](ex19_07.cpp)
> 编写与上一个练习类似的转换，这一次将 Query_base 对象转换为 AndQuery 的引用。重复上面的测试过程，确保转换能正常工作。

## [练习19.8](ex19_08.cpp)
> 编写一条 typeid 表达式检查两个 Query_base 对象是否指向同一种类型。再检查该类型是否是 AndQuery。

## [练习19.9](ex19_09.cpp)
> 编写与本节最后一个程序类似的代码，令其打印你的编译器为一些常见类型所起的名字。如果你得到的输出结果与本书类似，尝试编写一个函数将这些字符串翻译成人们更容易读懂的形式。

## 练习19.10
> 已知存在如下的类继承体系，其中每个类定义了一个默认公有的构造函数和一个虚析构函数。下面的语句将打印哪些类型名字？
```cpp
class A { /* ... */ };
class B : public A { /* ... */ };
class C : public B { /*...*/ };
(a) A *pa = new C;
	cout << typeid(pa).name() << endl;
(b) C cobj;
	A& ra = cobj;
	cout << typeid(&ra).name() << endl;
(c) B *px = new B;
	A& ra = *px;
	cout << typeid(ra).name() << endl;
```
(a) `class A *`，typeid作用于指针时，返回的结果是指针静态编译时的类型。  
(b) `class A *`  
(c) `class B`  

## 练习19.11
> 普通的数据指针和指向数据成员的指针有何区别？

指向数据成员的指针，除了所指对象的类型之外，还需要包含成员所属的类。例如`int *p`和`int A::*p`。  
使用普通指针可以直接解引用`*p`来得到所指对象，使用指向数据成员的指针则必须通过对应类型的对象`a.*p`的形式来调用。  

## 练习19.12
> 定义一个成员指针，令其可以指向 Screen 类的 cursor 成员。通过该指针获得 Screen::cursor 的值。

```cpp
Screen::pos Screen::*p = &Screen::cursor;
Screen a, *b;
cout << (a.*p) << endl;
cout << (b->*p) << endl;
```

## 练习19.13
> 定义一个类型，使其可以表示指向 Sales_data 类的 bookNo 成员的指针。

```cpp
using bookNo = string Sales_data::*;
```

## 练习19.14
> 下面的代码合法吗？如果合法，代码的含义是什么？如果不合法，解释原因。
```cpp
auto pmf = &Screen::get_cursor;
pmf = &Screen::get;
```
合法，`pmf`是一个指向`Screen`类`get_cursor`成员的指针，`auto`推断出这个指针的类型是一个`Screen`类无参返回`char`的成员函数指针。  
第二行令指针指向`Screen`类的`get`成员函数，虽然`get`有两个重载函数，但只有无参返回`char`的版本与`auto`推断出的`pmf`类型匹配，因此指针会指向这个成员函数。  

## 练习19.15
> 普通函数指针和指向成员函数的指针有何区别？

指向成员函数的指针，除了普通函数指针中的返回类型参数列表之外，还需要指明成员所属的类以及成员函数是否是`const`的、是否有引用限定符。例如`int (*funp)(int,int)`和`int (A::*funp)(int,int) const`。  
使用普通函数指针可以直接通过`(*funp)(1,2)`或`funp(1,2)`的形式来调用，而使用指向成员函数的指针则必须通过对应类型的对象以`(a.*funp)(1,2)`或`(p->*funp)(1,2)`的形式调用。  

## 练习19.16
> 声明一个类型别名，令其作为指向 Sales_data 的 avg_price 成员的指针的同义词。

```cpp
using Avg = double (Sales_data::*)() const;
```

## 练习19.17
> 为 Screen 的所有成员函数类型各定义一个类型别名。

以下面的成员函数为例：
```cpp
char get_cursor() const;
char get() const;
char get(pos, pos) const;
Screen& home();
Screen& forward();
Screen& back();
Screen& up();
Screen& down();
Screen& move(Directions);
```
成员函数的类型由返回类型、形参列表和`const`属性以及引用限定符决定，以上9个函数共有四种不同的类型：
```cpp
using Getnoparams = char (Screen::*)() const;
using Getpos = char (Screen::*)(Screen::pos, Screen::pos) const;
using Action = Screen& (Screen::*)();
using Move = Screen& (Screen::*)(Screen::Directions);
```

## [练习19.18](ex19_18.cpp)
> 编写一个函数，使用 count_if 统计在给定的 vector 中有多少个空 string。

## [练习19.19](ex19_19.cpp)
> 编写一个函数，令其接受vector< Sales_data >并查找平均价格高于某个值的第一个元素。

## [练习19.20](ex19_20)
> 将你的 QueryResult 类嵌套在 TextQuery 中，然后重新运行 12.3.2 节（第 435 页）中使用了 TextQuery 的程序。

## [练习19.21](ex19_21)
> 编写你自己的 Token 类。

## [练习19.22](ex19_22)
> 为你的 Token 类添加一个 Sales_data 类型的成员。

## [练习19.23](ex19_23)
> 为你的 Token 类添加移动构造函数和移动赋值运算符。

## 练习19.24
> 如果我们将一个 Token 对象赋给它自己将发生什么情况？

由于没有进行检测，在重载的拷贝赋值或移动赋值运算符中会进行自赋值。  
但这并不会导致问题，因为`Token`类中有内置类型、枚举类型、`Sales_data`类类型和`string`类类型。枚举类型本质也是内置类型中的整型，而内置类型的自赋值是不会出现问题的。  
对于`Sales_data`类，它没有定义拷贝控制成员，有两个内置类型成员和一个`string`成员，它们都是可拷贝和可移动的，因此编译器会合成拷贝赋值和移动赋值运算符，同样，由于内置类型自赋值不会出现问题，只剩下`string`。  
对于标准库提供的`string`类，它会正确处理自赋值或自移动问题，在拷贝赋值和移动赋值中都对自赋值的情况进行了检测。  
所以，尽管`Token`对象没有检查自赋值的情况，进行自赋值后也仍然能正常工作。  

## [练习19.25](ex19_25/main.cpp)
> 编写一系列赋值运算符，令其分别接受 union 中各种类型的值。

## 练习19.26
> 说明下列声明语句的含义并判断它们是否合法：
```cpp
extern "C" int compute(int *, int);
extern "C" double compute(double *, double);
```
第一个声明的意思是，`compute`是一个用C语言编写的函数，它接受一个指向`int`的指针和`int`作为参数，返回一个`int`。  
第二个声明的意思是，`compute`是一个用C语言编写的函数，它接受一个指向`double`的指针和`double`作为参数，返回一个`double`。  
如果二者单独出现，则声明语句是正确的。  
如果二者一起出现，则是非法的，因为C语言不支持函数重载，名字相同的函数只能有一个。  