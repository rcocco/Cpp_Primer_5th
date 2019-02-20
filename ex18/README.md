## 练习18.1

> 在下列 throw 语句中异常对象的类型是什么？
```cpp
(a) range_error r("error");
	throw r;
(b) exception *p = &r;
	throw *p;
```
> 如果将 (b) 中的 throw 语句写成了 throw p 将发生什么情况？

(a) 的异常对象类型是`range_error`。  
(b) 的异常对象类型是`exception`，只有基类部分保留，派生类部分被切掉了。  
如果写成`throw p`，则抛出的将是`exception *`异常。  

## 练习18.2

> 当在指定的位置发生了异常时将出现什么情况？
```cpp
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	ifstream in("ints");
	//此处发生异常
}
```
指针`p`所指对象的空间没有释放，将出现内存泄漏。  

## [练习18.3](ex18_03.cpp)
> 要想让上面的代码在发生异常时能正常工作，有两种解决方案。请描述这两种方法并实现它们。

第一种解决办法是使用`try-catch`语句块，将可能发生异常的语句放在`try`块中，然后在`catch`块中`delete [] p`。  
第二种解决办法是使用类来控制资源分配，在类的析构函数中`delete [] p`，当因为抛出异常而使变量`p`离开作用域时，析构函数会被自动调用。例如标准库提供的`unique_ptr`智能指针。  

## 练习18.4

> 查看图18.1所示的继承体系，说明下面的 try 块有何错误并修改它。
```cpp
try {
	// 使用 C++ 标准库
} catch (exception) {
	// ...
} catch (const runtime_error &re) {
	// ...
} catch (overflow_error eobj) { /* ... */ }
```
`exception`是`runtime_error`的基类，而`runtime_error`又是`overflow_error`的基类，由于异常类型允许从派生类向基类的转换，这导致永远都是`catch(exception)`语句内的异常处理代码被执行，下面两个`catch`语句永远不会被执行。  
如果多个`catch`语句的类型之间存在着继承关系，应该把继承链最底端的类放在前面，而将继承链最顶端的类放在后面，应改为：  
```cpp
try {
	// 使用 C++ 标准库
} catch (overflow_error eobj) {
	// ...
} catch (const runtime_error &re) {
	// ...
} catch (exception) { /* ... */ }
```

## 练习18.5

> 修改下面的main函数，使其能捕获图18.1所示的任何异常类型：
```cpp
int main(){
	// 使用 C++标准库
}
```
> 处理代码应该首先打印异常相关的错误信息，然后调用 abort（定义在 cstdlib 头文件中）终止 main 函数。
```cpp
int main(){
	try {
		// 使用 C++标准库
	}
	catch (exception e) {
		cerr << e.what() << endl;
		abort();
	}
}
```

## 练习18.6
> 已知下面的异常类型和 catch 语句，书写一个 throw 表达式使其创建的异常对象能被这些 catch 语句捕获：
```cpp
(a) class exceptionType { };
	catch(exceptionType *pet) { }
(b) catch(...) { }
(c) typedef int EXCPTYPE;
	catch(EXCPTYPE) { }
```
(a) `throw new exceptionType();`  
(b) `throw exception();`，不只是`exception`类型，任意类型都可以。  
(c) `throw 1;`，只要是`int`类型就可以。  

## [练习18.7](ex18_07)
> 根据第 16 章的介绍定义你自己的 Blob 和 BlobPtr，注意将构造函数写成函数 try 语句块。

注意，对于构造函数的函数`try`语句块形式，`catch`语句最后总是会抛出一个异常。如果语句块内`throw`了一个异常，那么就抛出该异常，如果没有`throw`任何异常，在在执行完`catch`语句块后会自动抛出当前异常，相当于有一条隐式的语句`throw;`。  
详细参见`C++11`标准中的规定：[Handling an exception](https://timsong-cpp.github.io/cppwp/n3337/except#handle-15)

## 练习18.8
> 回顾你之前编写的各个类，为它们的构造函数和析构函数添加正确的异常说明。如果你认为某个析构函数可能抛出异常，尝试修改代码使得该析构函数不会抛出异常。

对不会抛出异常的构造或析构函数后面加`noexcept`。  

## [练习18.9](ex18_09)
> 定义本节描述的书店程序异常类，然后为 Sales_data 类重新编写一个复合赋值运算符并令其抛出一个异常。

## [练习18.10](ex18_10)
> 编写程序令其对两个 ISBN 编号不相同的对象执行 Sales_data 的加法运算。为该程序编写两个不同的版本：一个处理异常，另一个不处理异常。观察并比较这两个程序的行为，用心体会当出现了一个未被捕获的异常时程序会发生什么情况。

## 练习18.11
> 为什么 what 函数不应该抛出异常？

标准库的异常基类`exception`的`what`虚函数是`noexcept`的，因此其派生类的`what`函数也不应该抛出异常。  
其次，`what`函数用于获取异常相关信息，如果在这个过程中又抛出了异常，这会导致当前异常处理程序被中断，又抛出了新的异常。  

## [练习18.12](ex18_12)
> 将你为之前各章练习编写的程序放置在各自的命名空间中。也就是说，命名空间 chapter15 包含 Query 程序的代码，命名空间 chapter12 包含TextQuery的代码；使用这种结构重新编译 Query 代码实例。

## 练习18.13
> 什么时候应该使用未命名的命名空间？

当希望定义一个只在当前源文件使用，而不是在组成程序的所有源文件中使用的全局变量时，应该使用未命名的命名空间。  

## 练习18.14
> 假设下面的 operator* 声明的是嵌套的命名空间 mathLib::MatrixLib 的一个成员：
```cpp
namespace mathLib {
	namespace MatrixLib {
		class matrix { /* ... */ };
		matrix operator* (const matrix &, const matrix &);
		// ...
	}
}
```
> 请问你应该如何在全局作用域中声明该运算符？
```
mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*(const matrix &, const matrix &);
```

## 练习18.15
> 说明 using 指示与 using 声明的区别。

`using`声明一次引入某个特定命名空间的一个名字，声明可以出现在全局作用域、局部作用域、命名空间作用域以及类作用域。`using`声明的有效范围从声明的地方开始，一直到声明所在的作用域结束为止，在它的有效范围内外层作用域的同名实体被隐藏。  
`using`指示使得某个特定命名空间的所有名字都可见。简写的名字从`using`指示开始一直到`using`指示所在的作用域结束都能使用。`using`指示将命名空间成员提升到最近的外层作用域，在它的有效范围内，使用与最近的外层作用域同名的实体将会导致二义性。    

## 练习18.16
> 假定在下面的代码中标记为“位置1”的地方是对命名空间 Exercise 中所有成员的 using 声明，请解释代码的含义。如果这些 using 声明出现在“位置2”又会怎样呢？将 using 声明变为 using 指示，重新回答之前的问题。
```cpp
namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
//位置1
void main() {
	//位置2
	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}
```
`using`声明出现在位置1，会出现由于多次声明`ivar`导致的编译失败。其次`main`函数内部的`dvar`将隐藏外层的`dvar`。  
`using`声明出现在位置2，会出现由于多次声明`dvar`导致的编译失败。`++ivar`将是递增`++Exercise::ivar`，而`++::ivar`将是递增全局变量`ivar`。  
`using`指示出现在位置1，`++ivar`将是二义性的，编译器不清楚`ivar`指的是全局变量还是`Exercise`命名空间中的变量。`++::ivar`递增的将是全局变量。  
`using`指示出现在位置2，`++ivar`将是二义性的，编译器不清楚`ivar`指的是全局变量还是`Exercise`命名空间中的变量。`++::ivar`递增的将是全局变量。  

## [练习18.17](ex18_17.cpp)
> 实际编写代码检验你对上一题的回答是否正确。

## 练习18.18
> 已知有下面的 swap 的典型定义（参见 13.3 节，第 457 页），当 mem1 是一个 string 时程序使用 swap 的哪个版本？如果 mem1 是 int 呢？说明在这两种情况下名字查找的过程。
```cpp
void swap(T v1, T v2)
{
	using std::swap;
	swap(v1.mem1, v2.mem1);
	//交换类型的其他成员
}
```
当`mem1`是一个`string`时，编译器首先在当前作用域查找`swap`，由于存在`using`声明，标准库的所有`swap`都是候选函数，同时标准库的版本隐藏了当前函数的名字`swap(T,T)`。然后在外层作用域查找，没有找到`swap`。最后在`string`类所属的命名空间`std`中查找，找到的和之前已经找到的相同。最终选择了标准库的`swap(string &,string &)`版本。  
当`mem1`是一个`int`时，编译器首先在当前作用域查找`swap`，由于存在`using`声明，标准库的所有`swap`都是候选函数，同时标准库的版本隐藏了当前函数的名字`swap(T,T)`。然后在外层作用域查找，没有找到`swap`。最终选择了标准库的`swap(int &,int &)`版本。  

## 练习18.19
> 如果对 swap 的调用形如 std::swap(v1.mem1, v2.mem1) 将会发生什么情况？

将直接调用标准库版本，而不在当前作用域查找。  

## 练习18.20
> 在下面的代码中，确定哪个函数与 compute 调用匹配。列出所有候选函数和可行函数，对于每个可行函数的实参与形参的匹配过程来说，发生了哪种类型转换？
```cpp
namespace primerLib {
	void compute();
	void compute(const void *);
}
using primerLib::compute;
void compute(int);
void compute(double, double = 3.4);
void compute(char*, char* = 0);
void f()
{
	compute(0);
}
```
字面值`0`可以转换为任意指针类型。  
- 候选函数：
  1. `void compute()`
  2. `void compute(const void *)`
  3. `void compute(int)`
  4. `void compute(double, double = 3.4)`
  5. `void compute(char*, char* = 0)`
- 可行函数：
  1. `void compute(const void *)`
  2. `void compute(int)`
  3. `void compute(double, double = 3.4)`
  4. `void compute(char*, char* = 0)`
- 最佳匹配
  1. 可行函数1需要进行从字面值`0`向`const void *`的指针转换，它的转换级别是4。  
  2. 可行函数2是精确匹配。  
  3. 可行函数3需要进行从`int`向`double`的算术转换，它的转换级别是4。
  4. 可行函数4需要进行从字面值`0`向`char *`的指针转换，它的转换级别是4。  
  5. 可行函数2的优于其他可行函数，因此最佳匹配是它。  

> 如果将 using 声明置于 main 函数中 compute 的调用点之前将发生什么情况？重新回答之前的那些问题。

- 候选函数：
  1. `void compute()`
  2. `void compute(const void *)`
- 可行函数：
  1. `void compute(const void *)`
- 最佳匹配
  1. 可行函数只有一个，需要进行从字面值`0`向`const void *`的指针转换，最佳匹配就是它。    

## 练习18.21
> 解释下列声明的含义，在它们当中存在错误吗？如果有，请指出来并说明错误的原因。
```cpp
(a) class CADVehicle : public CAD, Vehicle { ... };
(b) class DbiList : public List, public List { ... };
(c) class iostream : public istream, public ostream { ... };
```
(a) 正确。`CADVehicle`类公有继承`CAD`类，私有继承`Vehicle`类。  
(b) 错误，在某个给定的派生列表中，同一个基类只能出现一次。  
(c) 正确，`iostream`类公有继承`istream`和`ostream`类。  

## 练习18.22
> 已知存在如下所示的类的继承体系，其中每个类都定义了一个默认构造函数：
```cpp
class A { ... };
class B : public A { ... };
class C : public B { ... };
class X { ... };
class Y { ... };
class Z : public X, public Y { ... };
class MI : public C, public Z { ... };
```
> 对于下面的定义来说，构造函数的执行顺序是怎样的？
```cpp
MI mi;
```
首先执行`MI()`，它的初始值列表中依次调用了`C()`和`Z()`。`C()`的初始值列表调用了`B()`，`B()`的初始值列表调用了`A()`。`Z()`的初始值列表中依次调用了`X()`和`Y()`。  
开始执行的顺序为：`MI()`、`C()`、`B()`、`A()`、`Z()`、`X()`、`Y()`。  
执行完毕的顺序为：`A()`、`B()`、`C()`、`X()`、`Y()`、`Z()`、`MI()`。  

## 练习18.23
> 使用练习 18.22 的继承体系以及下面定义的类 D，同时假定每个类都定义了默认构造函数，请问下面的哪些类型转换是不被允许的？
```cpp
class D : public X, public C { ... };
p *pd = new D;
(a) X *px = pd;  (b) A *pa = pd;
(c) B *pb = pd;  (d) C *pc = pd;
```
都是公有继承，因此四个类型转换都是允许的。  

## 练习18.24
> 在第 714 页，我们使用一个指向 Panda 对象的 Bear 指针进行了一系列调用，假设我们使用的是一个指向 Panda 对象的 ZooAnimal 指针将发生什么情况，请对这些调用语句逐一进行说明。
```cpp
ZooAnimal *pz = new Panda("ying_yang");
pz->print();      // 正确：Panda::print()
pz->cuddle();     // 错误：不属于 ZooAnimal 的接口
pz->highlight();  // 错误：不属于 ZooAnimal 的接口
delete pz;        // 正确：Panda::~Panda()
```

## 练习18.25
> 假设我们有两个基类 Base1 和 Base2，它们各自定义了一个名为 print 的虚成员和一个虚析构函数。从这两个基类中我们派生出下面的类，它们都重新定义了 print 函数：
```cpp
class D1 : public Base1 { /* ... */};
class D2 : public Base2 { /* ... */};
class MI : public D1, public D2 { /* ... */};
```
> 通过下面的指针，指出在每个调用中分别使用了哪个函数：
```cpp
Base1 *pb1 = new MI;
Base2 *pb2 = new MI;
D1 *pd1 = new MI;
D2 *pd2 = new MI;
(a) pb1->print();  (b) pd1->print();  (c) pd2->print();
(d) delete pb2;    (e) delete pd1;    (f) delete pd2;
```
六个都是调用`MI`中的虚函数。  

## 练习18.26
```cpp
struct Base1 {
	void print(int) const;
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};
struct Base2 {
	void print(double) const;
protected:
	double fval;
private:
	double dval;
};
struct Derived : public Base1 {
	void print(std::string) const;
protected:
	std::string sval;
	double dval;
};
struct MI : public Derived, public Base2 {
	void print(std::vector<double>);
protected:
	int *ival;
	std::vector<double> dvec;
};
```
> 已知如上所示的继承体系，下面对 print 的调用为什么是错误的？适当修改 MI，令其对 print 的调用可以编译通过并正确执行。
```cpp
MI mi;
mi.print(42);
```
名字查找先于类型检查，编译器在`MI`中找到了名字`print`，确定调用的是`MI`中定义的`print`。但`vector`接受一个`int`参数的构造函数是`explicit`的，因此在`mi.print(42)`中不会隐式的将`42`转换成`vector`，所以该调用语句的参数不匹配。    
`MI`中的`print`函数应该改为：
```cpp
void print(int n) {
	std::vector<double> vec(n);
	// else 
}
```

## 练习18.27
> 已知如上所示的继承体系，同时假定为MI添加了一个名为foo的函数：
```cpp
int ival;
double dval;
void MI::foo(double cval)
{
	int dval;
	//练习中的问题发生在此处
}
```
> (a) 列出在MI::foo中可见的所有名字。  
> (b) 是否存在某个可见的名字是继承自多个基类的？  
> (c) 将 Base1 的 dval 成员与 Derived 的 dval 成员求和后赋给 dval 的局部实例。  
> (d) 将 MI::dvec 的最后一个元素的值赋给 Base2::fval。  
> (e) 将从 Base1 继承的 cval 赋给从 Derived 继承的 sval 的第一个字符。  

(a) `double cval`、`int *MI::ival`、`int dval`、`vector<double> MI::devc`、`MI::print`、`string Derived::sval`、`double Base2::fval`。  
(b) 该位置没有。  
(c) `dval = Base1::dval + Derived::dval;`  
(d) `fval = dvec.back();`  
(e) `sval[0] = Base1::cval;`  

## 练习18.28
> 已知存在如下的继承体系，在 VMI 类的内部哪些继承而来的成员无须前缀限定符就能直接访问？哪些必须有限定符才能访问？说明你的原因。
```cpp
struct Base {
	void bar(int);
protected:
	int ival;
};
struct Derived1 : virtual public Base {
	void bar(char);
	void foo(char);
protected:
	char cval;
};
struct Derived2 : virtual public Base {
	void foo(int);
protected:
	int ival;
	char cval;
};
class VMI : public Derived1, public Derived2 { };
```
无须前缀限定符：`ival`（指的是`Derived2`中的）、`bar`（指的是`Derived1`中的），这两个名字在`Base`类和其中一个派生类中都有，由于是虚继承，且访问名字时只有一条派生路径，派生类的名字限于基类的名字，因此会选择派生类中的名字。  
需要前缀限定符：`cval`、`foo`，这两个名字在继承的两个派生类中都存在，访问时不确定是访问哪个派生类的变量，具有二义性，因此需要限定符。    


## 练习18.29

> 已知有如下所示的类继承关系：
```cpp
class Class { ... };
class Base : public Class { ... };
class D1 : virtual public Base { ... };
class D2 : virtual public Base { ... };
class MI : public D1, public D2 { ... };
class Final : public MI, public Class { ... };
```
> (a) 当作用于一个 Final 对象时，构造函数和析构函数的执行次序分别是什么？
> (b) 在一个 Final 对象中有几个 Base 部分？几个 Class 部分？
> (c) 下面的哪些赋值运算符将造成编译错误？
```cpp
Base *pb; Class *pc; MI *pmi; D2 *pd2;
(a) pb = new Class;   (b) pc = new Final;
(c) pmi = pb;         (d) pd2 = pmi;
```
(a) 
构造函数：  
开始的顺序是`Final()`、`Base()`、`Class()`、`MI()`、`D1()`、`D2()`、`Class()`。  
完成的顺序是`Class()`、`Base()`、`D1()`、`D2()`、`MI()`、`Class()`、`Final()`。  
析构函数：  
执行顺序是`~Final()`、`~Class()`、`~MI()`、`~D2()`、`~D1`、`~Base()`、`~Class()`。  
(b) 有一个`Base`部分，两个`Class`部分。  
(c)
- (a) 编译错误，不能用派生类的指针指向基类对象。  
- (b) 编译错误，`Class`是`Final`的二义基类，无法知道指向的是哪个部分的`Class`。（注：在Visual Sutio 2017中没有报告该错误，而是当做直接基类那个`Class`，测试见：[ex18_29.cpp](ex18_29.cpp)）  
- (c) 编译错误，不能用指向基类的指针为指向派生类的指针赋值。  

## [练习18.30](ex18_30.cpp)
> 在 Base 中定义一个默认构造函数、一个拷贝构造函数和一个接受 int 形参的构造函数。在每个派生类中分别定义这三种构造函数，每个构造函数应该使用它的形参初始化其 Base 部分。