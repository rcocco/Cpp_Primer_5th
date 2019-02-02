## [练习7.1](ex07_01)
> 使用 2.6.1 节定义的 Sales_data 类为1.6节（第 21 页）的交易处理程序编写一个新版本。

## [练习7.2](ex07_02)
> 曾在 2.6.2 节的练习（第 67 页）中编写了一个 Sales_data 类，请向这个类添加 combine 函数和 isbn 成员。

## [练习7.3](ex07_03)
> 修改7.1.1节（第 229 页）的交易处理程序，令其使用这些成员。

## [练习7.4](ex07_04/Person.h)
> 编写一个名为 Person 的类，使其表示人员的姓名和住址。使用 string 对象存放这些元素，接下来的练习将不断充实这个类的其他特征。

## [练习7.5](ex07_05/Person.h)
> 在你的 Person 类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是 const 的呢？解释原因。

应该是`const`的，因为在函数只返回姓名和住址值，不会进行修改。同时定义为常量成员函数还能使常量对象、常量对象的引用或指针正常调用该函数。  

## [练习7.6](ex07_06)
> 对于函数 add、read 和 print，定义你自己的版本。

## [练习7.7](ex07_07)
> 使用这些新函数重写 7.1.2 节（第 233 页）练习中的交易处理程序。

## 练习7.8
> 为什么 read 函数将其 Sales_data 参数定义成普通的引用，而 print 函数将其参数定义成常量引用？

因为 read 函数需要将输入值写入`Sales_data`对象，而 print 函数只需要读取对象并输出。  

## [练习7.9](ex07_09)
> 对于 7.1.2 节（第 233 页）练习中代码，添加读取和打印 Person 对象的操作。

## 练习7.10
> 在下面这条 if 语句中，条件部分的作用是什么？
```cpp
if (read(read(cin, data1), data2))
```
条件部分从输入流读取数据到`data1`和`data2`，然后检查输入流是否有效。  
`read`函数返回参数中的输入流`cin`，因此它可以用作外层`read`函数的参数。外层`read`的返回值仍然是`cin`，它又被用作`if`的条件。

## [练习7.11](ex07_11)
> 在你的 Sales_data 类中添加构造函数，然后编写一段程序令其用到每个构造函数。

## [练习7.12](ex07_12/Sales_data.h)
> 把只接受一个 istream 作为参数的构造函数定义移到类的内部。

## [练习7.13](ex07_13)
> 使用 istream 构造函数重写第 229 页的程序。

## 练习7.14
> 编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。
```cpp
Sales_data(const std::string &s):
	bookNo(s),units_sold(0),revenue(0.0) { }
```

## [练习7.15](ex07_15)
> 为你的 Person 类添加正确的构造函数。

## 练习7.16
> 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在 public 说明符之后？什么样的成员应该定义在private 说明符之后？

类定义中的访问说明符出现位置和次数没有限定。每个访问说明符指定接下来的成员的访问级别，有效范围直到出现下一个访问说明符或者到达类尾为止。  
类的接口应该定义在`public`说明符之后，一般包括构造函数和作为接口部分的成员函数 。  
类的实现应该定义在`private`说明符之后，一般包括数据成员和作为实现部分的成员函数。  

## 练习7.17
> 使用class 和 struct 时有区别吗？如果有，是什么？

`class`和`struct`的唯一区别是默认的访问级别不同。  
`class`的默认访问级别是`private`，因此定义在第一个访问说明符之前的成员都是`private`的。  
`struct`的默认访问级别是`public`，因此定义在第一个访问说明符之前的成员都是`public`的。  

## 练习7.18
> 封装是何含义？它有什么用处？

封装指保护类的成员不被随意访问的能力，通过将类的实现细节设为`private`，就能完成类的封装。  
封装分离了类的实现与接口，从而隐藏了类的实现细节。这提供了两个重要的优点：  
一是被封装的类的具体实现细节可以随时改变，只要接口不变用户代码就无须改变；二是确保用户代码不会无意间破坏封装对象的状态；  

## 练习7.19
> 在你的 Person 类中，你将把哪些成员声明成 public 的？哪些声明成 private 的？解释你这样做的原因。

类的接口部分，包括构造函数、`getName()`和`getAddress()`应该设为`public`，用户代码需要使用这些函数来操作`Person`对象。  
类的实现部分，包括数据成员`name`和`address`应该设为`private`，用户代码不需要直接访问这些成员以免无意间破坏对象的状态。  

## 练习7.20
> 友元在什么时候有用？请分别举出使用友元的利弊。

当其他类或者函数需要访问类的非公有成员时，可以把它声明成该类的友元。  
友元的优点在于友元可以像类的成员一样访问类的所有数据和函数，缺点在于如果使用不恰当，将有可能破坏类的封装性。  

## [练习7.21](ex07_21)
> 修改你的 Sales_data 类使其隐藏实现的细节。你之前编写的关于 Sales_data 操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其正常工作。

## [练习7.22](ex07_22/Person.h)
> 修改你的 Person 类使其隐藏实现的细节。

## [练习7.23](ex07_23/Screen.h)
> 编写你自己的 Screen 类。

## [练习7.24](ex07_24/Screen.h)
> 给你的 Screen 类添加三个构造函数：一个默认构造函数；另一个构造函数接受宽和高的值，然后将 contents 初始化成给定数量的空白；第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。

## 练习7.25
> Screen 能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能，为什么？

能。`Screen`类的成员只有内置类型和定义了拷贝和赋值运算符的`string`类型，因此可以依赖于拷贝和赋值操作的默认版本。  

## [练习7.26](ex07_26)
> 将 Sales_data::avg_price 定义成内联函数。

## [练习7.27](ex07_27)
> 给你自己的 Screen 类添加 move、set 和 display 函数，通过执行下面的代码检验你的类是否正确。
```cpp
Screen myScreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

## 练习7.28
> 如果 move、set 和 display 函数的返回类型不是 Screen& 而是 Screen，则在上一个练习中将会发生什么情况？

只有`move(4, 0)`改变了`myScreen`，而从`.set('#')`开始每次都是在返回的临时副本上面调用函数，因此第一次输出了`myScreen`的临时副本，第二次输出的是`move(4, 0)`之后没有`set('#')`过的`myScreen`。  

## [练习7.29](ex07_29)

> 修改你的 Screen 类，令 move、set 和 display 函数返回 Screen 并检查程序的运行结果，在上一个练习中你的推测正确吗？

输出结果为：  
```cpp
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

## 练习7.30
> 通过 this 指针使用成员的做法虽然合法，但是有点多余。讨论显式地使用指针访问成员的优缺点。

优点是明确指出了访问的是对象的成员，同时可以在成员函数中使用与数据成员相同名字的形参。  
缺点是显得多余，代码不够简洁。  


## 练习7.31
> 定义一对类 X 和Y，其中 X 包含一个指向 Y 的指针，而 Y 包含一个类型为 X 的对象。

可以定义指向不完全类型的指针或引用，但不能创建不完全类型的对象，为了使`Y`类能创建一个`X`类型的对象，`X`的定义必须在`Y`之前，又因为`X`类需要定义指向`Y`的指针，因此`X`的定义之前必须有`Y`的前向声明。
```cpp
class Y;
class X {
	Y *p = nullptr;
};
class Y {
	X e;
};
```

## 练习7.32 [单一头文件](ex07_32/single_file/Window_mgr_Screen.h) | [多个头文件](ex07_32/multiple_file)
> 定义你自己的 Screen 和 Window_mgr，其中 clear 是 Window_mgr 的成员，是 Screen 的友元。

**类中声明与使用其他类所需的条件**：  
1. `Screen`类的友元声明`Window_mgr::clear`需要`Window_mgr`类已定义，并且`Window_mgr`类具有成员函数`clear`的声明。  
2. `Window_mgr`类中的类型别名`ScreenIndex`需要`Screen`类已声明。  
3. `Window_mgr`类中的成员`screens`的初始化需要用到`Screen`类的构造函数，要求`Screen`类已定义且具有构造函数的声明。  
4. `Window_mgr`类中的成员函数`clear`定义需要用到`Screen`类的`contents`等成员，要求`Screen`类已定义，且具有数据成员`contents`、`height`和`width`。  

为了满足条件1，`Window_mgr`的定义需要在`Screen`的定义之前。  
为了满足条件2，`Screen`的声明需要在`Window_mgr`的定义之前。  
为了满足条件3，`Screen`的定义需要在`Window_mgr`的定义之前。  
为了满足条件4，`Screen`的定义需要在`Window_mgr`的`clear`成员函数定义之前。
显然，条件3与条件1冲突，两个类此时都要求对方类定义在自己之前，因此我们不能采用类内初始化的方式初始化`screens`。为此我们改用默认构造函数来初始化`screens`。  
修改后的条件3为：  
`Window_mgr`类中的默认构造函数需要用到`Screen`类的构造函数，要求`Screens`类已定义且具有构造函数的声明。  
为了满足修改后的条件3，`Screen`的定义需要再`Window_mgr`的构造函数定义之前。  
  
由此得到了声明与定义的组织顺序：  
1. 声明`Screen`但不定义。  
2. 定义`Window_mgr`，声明默认构造函数与`clear`函数但不定义。  
3. 定义`Screen`。  
4. 定义`Window_mgr`的默认构造函数与`clear`函数。   

## 练习7.33

> 如果我们给 Screen 添加一个如下所示的 size 成员将发生什么情况？如果出现了问题，请尝试修改它。
```cpp
pos Screen::size() const
{
	return height * width;
}
```
编译失败。因为在类外定义的函数，只有遇到了类名才进入类的作用域，而返回类型位于类名之前，编译器不知道`pos`类型是什么。需要使用作用域运算符注明`pos`是`Screen`类内定义的：
```cpp
Screen::pos Screen::size() const
{
	return height * width;
}
```

## 练习7.34
> 如果我们把第256页 Screen 类的 pos 的 typedef 放在类的最后一行会发生什么情况？

编译失败。所有以`pos`为参数类型或者返回类型的函数声明都无法通过。它们不知道`pos`是什么类型，而在函数体内使用`pos`类型的则可以编译通过，因为类会先编译所有成员声明再编译函数体。  

## 练习7.35
> 解释下面代码的含义，说明其中的 Type 和 initVal 分别使用了哪个定义。如果代码存在错误，尝试修改它。
```cpp
typedef string Type;
Type initVal(); 
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal(); 
private:
    int val;
};
Type Exercise::setVal(Type parm) { 
    val = parm + initVal();     
    return val;
}
```
在类中重新定义外层作用域已有的类型别名是一种**错误行为**，编译器不为此负责。  
在`Visual Studio 2017`中，编译器会将其解析为以下形式，由于这是一种**错误行为**，不能保证所有编译器都会这样处理。  
```cpp
typedef string Type;
string initVal(); 
class Exercise {
public:
    typedef double Type;
    double setVal(double);
    double initVal(); 
private:
    int val;
};
string Exercise::setVal(double parm) { 
    val = parm + initVal(); 
    return val;
}
```

## 练习7.36
> 下面的初始值是错误的，请找出问题所在并尝试修改它。
```cpp
struct X {
	X (int i, int j): base(i), rem(base % j) { }
	int rem, base;
};
```
类的数据成员的初始化顺序是与它们在类定义中的出现顺序一致的，与初始值列表中的顺序无关。  
上述代码先初始化`rem`再初始化`base`，而在初始化`rem`时，`base`的值是未定义的。  
修改时可以调整定义`rem`和`base`的顺序，但更好的办法是用构造函数的参数作为成员的初始值，尽可能避免使用同一个对象的其他成员。这样的好处是不必考虑成员的初始化顺序。  
```cpp
struct X {
	X (int i, int j): base(i), rem(i % j) { }
	int rem, base;
};
```

## 练习7.37
> 使用本节提供的 Sales_data 类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有的数据成员的值。
```cpp
Sales_data first_item(cin);
int main() {
	Sales_data next;
	Sales_data last("9-999-99999-9"); 
}
```
第一行使用了`Sales_data(std::istream &is)`，该对象数据成员的值取决于从输入流中读取的输入。  
第三行使用了`Sales_data(std::string s = "")`，该对象数据成员`bookNo`的值为空串，其他两个成员使用类内初始值初始化为`0`。  
第四行使用了`Sales_data(std::string s = "")`，该对象数据成员`bookNo`的值为`"9-999-99999-9"`，其他两个成员使用类内初始值初始化为`0`。    

## 练习7.38
> 有些情况下我们希望提供 cin 作为接受 istream& 参数的构造函数的默认实参，请声明这样的构造函数。
```cpp
Sales_data(std::istream &is = std::cin);
```

## 练习7.39
> 如果接受 string 的构造函数和接受 istream& 的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？

不合法。这两个构造函数都使用了默认实参，也就都定义了默认构造函数。当调用默认构造函数`Sales_data()` 时，编译器无法判断哪个函数优于另一个，从而出现了二义性错误。  

## [练习7.40](ex07_40)
> 从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
```cpp
(a) Book     (b) Data    (c) Employee
(d) Vehicle  (e) Object  (f) Tree
```
以`Book`为例，它有三个构造函数，默认构造函数、参数是全体数据成员的构造函数，和以输入流为参数的构造函数。  
默认构造函数对所有数据成员默认初始化。  
如果用户能够提供书籍的一个信息，他也应该能提供其他所有信息，因此有参数是全体数据成员的构造函数，以及从输入流读取数据的构造函数。  

## [练习7.41](ex07_41)
> 使用委托构造函数重新编写你的 Sales_data 类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建 Sales_data 对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

## [练习7.42](ex07_42/Book.h)
> 对于你在练习 7.40（参与 7.5.1 节，第 261 页）中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。

## 练习7.43

> 假定有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。定义类 C，C 有一个 NoDefault 类型的成员，定义C 的默认构造函数。
```cpp
class NoDefault {
public:
	NoDefault(int v) { }
};
class C {
public:
	C():nodef(0) { }
private:
	NoDefault nodef;
};
```

## 练习7.44

> 下面这条声明合法吗？如果不，为什么？
```cpp
vector<NoDefault> vec(10);
```
不合法。该语句的含义是创建一个包含`10`个`Nodefault`对象的`vector`并执行默认初始化，由于`NoDefault`没有默认构造函数，默认初始化无法进行。  

## 练习7.45
> 如果在上一个练习中定义的 vector 的元素类型是 C，则声明合法吗？为什么？

合法。因为 `C` 有默认构造函数。

## 练习7.46
> 下面哪些论断是不正确的？为什么？  
> (a) 一个类必须至少提供一个构造函数。    
> (b) 默认构造函数是参数列表为空的构造函数。  
> (c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。  
> (d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。  

(a) 不正确。如果类不提供任何构造函数，编译器会自动实现一个合成的默认构造函数。  
(b) 不正确。如果构造函数为每个形参都提供了默认实参，它也是默认构造函数。  
(c) 不正确。如果一个类没有默认构造函数，也就是说定义了其他构造函数但没有定义默认构造函数，那么当编译器需要隐式地使用默认构造函数时，该类将无法使用。因此一般情况下不论有没有有意义的默认值，都应该提供默认构造函数。  
(d) 不正确。只有当类没有定义任何构造函数的时，编译器才会生成合成的默认构造函数。同时合成的默认构造函数会对类类型成员执行各自的默认构造函数。  

## 练习7.47
> 说明接受一个 string 参数的 Sales_data 构造函数是否应该是 explicit 的，并解释这样做的优缺点。

`explicit`决定了是否允许从`string`到`Sales_data`的隐式转换，这依赖于我们对用户使用该转换的看法。在此例中，这种转换可能是对的。但`string`对象可能表示了一个不存在的 ISBN 编号。  
设置为`explicit`的优点是可以避免因为隐式转换而带来的意想不到的错误，缺点是当用户确实需要这样的类型转换时，不得不采用繁琐的方式实现。  

## 练习7.48
> 假定 Sales_data 的构造函数不是 explicit 的，则下述定义将执行什么样的操作？
```cpp
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```
第一行创建了一个`string`对象，第二行和第三行都是调用`Sale_data`接受一个`const string &`参数的构造函数来创建对象。在第三行中，字面值`9-999-99999-9`被`string`类的非`explicit`构造函数转换为了`string`。所以不论`Sale_data`的构造函数是否是`explicit`的，`item1`和`item2`都能正确创建。  

## 练习7.49
> 对于 combine 函数的三种不同声明，当我们调用 i.combine(s) 时分别发生什么情况？其中 i 是一个 Sales_data，而 s 是一个 string 对象。
```cpp
(a) Sales_data &combine(Sales_data);
(b) Sales_data &combine(Sales_data&); 
(c) Sales_data &combine(const Sales_data&) const;
```
(a) 是合法的，`s`被隐式转换成了一个`Sales_data`临时对象并传递给了函数。  
(b) 是非法的，`s`被隐式转换成了一个`Sales_data`临时对象，但函数形参是一个普通引用，无法绑定到一个临时对象上。  
(c) 是非法的，`s`被隐式转换成了一个`Sales_data`临时对象，可以绑定到常量引用形参上，但是`const`成员函数无法改变对象的值，而`combine`内会改变对象的值。  

## 练习7.50
> 确定在你的 Person 类中是否有一些构造函数应该是 explicit 的。
```cpp
explicit Person(std::istream&);
```
接受一个输入流的构造函数应该是`explicit`的，否则当需要`Person`的地方，传入的却可以是一个输入流，这种隐式转换是令人费解的。  

## 练习7.51
> vector 将其单参数的构造函数定义成 explicit 的，而 string 则不是，你觉得原因何在？

`vector`接受的单参数是`int`类型，这个参数的原意是指定`vector`的容量。用户在本来需要`vector`的地方提供一个`int`，编译器自动生成了一个将`int`作为容量的`vector`，这个过程显得比较牵强，因此定义成`explicit`更合理。  
`string`接受的单参数是`const char*`类型，这个参数的原意是C风格字符串常量，任何`string`和C风格字符串常量都可以用对方的形式重写，二者可以看作是等价的，所以编译器自动将`const char*`转换为`string`是符合逻辑的，也便于用户使用，因此不需要指定为`explicit`。  

## 练习7.52

> 使用2.6.1节的 Sales_data 类，解释下面的初始化过程。如果存在问题，尝试修改它。
```cpp
	Sales_data item = {"987-0590353403", 25, 15.99};
```
该代码的目的是对`item`执行聚合类的初始化操作，用花括号内的值初始化`item`的数据成员。  
问题在于`Sales_data`类不是一个聚合类，因为它提供了类内初始值，去掉后修改如下：  
```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

## [练习7.53](ex07_53/main.cpp)
> 定义你自己的 Debug。

## 练习7.54
> Debug 中以 set_ 开头的成员应该被声明成 constexpr 吗？如果不，为什么？

不能。因为`constexpr`函数拥有的唯一可执行语句必须是返回语句。  

## 练习7.55
> 7.5.5节的 Data 类是字面值常量类吗？请解释原因。

不是。字面值常量类要求所有数据成员都必须是字面值类型，而`string`不是字面值类型。  

## 练习7.56
> 什么是类的静态成员？它有何优点？静态成员与普通成员有何区别？

静态成员是指声明语句之前带有`static`关键字的类成员，静态成员不是任意单独对象的组成部分，而是由类的全体对象共享。  
静态成员的优点是直接与类关联，只存储一份，所有对象都共享，修改之后所有此前已经存在的对象也会使用新值。尽管全局对象也能做到，但与全局对象相比，静态成员的优势是作用域位于类范围内，不会与其他类成员或全局作用域的名字冲突。同时还可以是类的私有成员，与类的关系比全局对象更明确。  
普通成员是某个具体对象的组成部分，每个对象的成员都与其他对象的成员无关。静态成员不从属于任何具体对象，由该类的所有对象共享。另外，静态成员可以作为默认实参，而普通成员不可以。  

## [练习7.57](ex07_57)
> 编写你自己的 Account 类。

## 练习7.58
> 下面的静态数据成员的声明和定义有错误吗？请解释原因。
```cpp
//example.h
class Example {
public:
	static double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec(vecSize);
};
//example.c
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```
只有静态整型常量`static const int`或`static constexpr`数据成员可以在类内初始化。  
`rate`是一个`double`类型，要想在类内初始化必须声明成`constexpr`的。  
`vec`是一个`vector<double>`类型，它不是字面值常量，无法声明成`constexpr`的，因此它只能在类外初始化。应改为：  
```cpp
//example.h
class Example {
public:
	static constexpr double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec;
};
//example.c
#include "example.h"
double Example::rate;
vector<double> Example::vec(vecSize);
```