## 练习2.1
> 类型 int、long、long long 和 short 的区别是什么？无符号类型和带符号类型的区别是什么？float 和 double的区别是什么？

| 类型      |     含义 |   最小尺寸   |
| :-------- | :--------| :------ |
| short    |   短整型 |  16位  |
| int    |   整型 |  16位  |
| long    |   长整型 |  32位  |
| long long    |   长整型 |  64位  |
| float   |   单精度浮点数 |  6位有效数字  |
| double   |   双精度浮点数 |  10位有效数字  |

无符号类型可以表示正数或0。 n比特的无符号数可以表示`0`到`2^n - 1`之间的整数。
带符号类型可以表示正数、负数或0。在二进制补码表示法中，n比特带符号类型可以表示  
`-2^(n-1)`到`2^(n-1) - 1`之间的整数。  

## 练习2.2
> 计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

利率、本金和付款既有可能是整数，也有可能是实数，所以应该在浮点类型`float`、`double`和`long double`中选择。  
由于`long double`的计算代价相对较大，`double`和`float`的计算代价相差无几，且`double`的精度高于`float`，因此选择`double`。  

## 练习2.3
> 读程序写结果。
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;

int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

计算过程和结果，假定int类型占32位：
```
42u - 10u = 32u
10u - 42u = (-32 + 2^32) = 4294967264u
42 - 10 = 32
10 - 42 = -32
10 - 10u = 0u
10u - 10 = 0u
```

## [练习2.4](ex02_4.cpp)
> 编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

## 练习2.5
> 指出下述字面值的数据类型并说明每一组内几种字面值的区别：
> (a) 'a', L'a', "a", L"a"
> (b) 10, 10u, 10L, 10uL, 012, 0xC
> (c) 3.14, 3.14f, 3.14L
> (d) 10, 10u, 10., 10e-2  

|类型      |     含义 |   类型   |
|:-------- | :--------| :------ |
|`'a'`|字符型字面值|`char`  |
|`L'a'`|宽字符型字面值|`wchar_t`  |
|`"a"`|字符串字面值|`常量char的数组`  |
|`L"a"`|宽字符型字符串字面值|`常量wchar_t数组`  |

|类型      |     含义 |   类型   |
|:-------- | :--------| :------ |
|`10`|十进制带符号数|`int`|
|`10u`|十进制无符号数|`unsigned int`|
|`10L`|十进制长整型|`long`|
|`10uL`|十进制无符号长整型|`unsigned long`|
|`012`|八进制数|`int`|
|`0xC`|十六进制数|`int`|

|类型      |     含义 |   类型   |
|:-------- | :--------| :------ |
|`3.14`|双精度浮点数字面值|`double`|
|`3.14f`|单精度浮点数字面值|`float`|
|`3.14L`|扩展精度浮点数字面值|`long double`|

|类型      |     含义 |   类型   |
|:-------- | :--------| :------ |
|`10`|十进制带符号数|`int`|
|`10u`|十进制无符号数|`unsigned int`|
|`10.`|等价于10.0，双精度浮点数字面值|`double`|
|`10e-2`|科学计数法的双精度浮点数字面值|`double`|  

## 练习2.6
> 下面两组定义是否有区别，如果有，请叙述之：
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```
有区别。  
第一行定义了两个十进制数9和7。  
第二行定义了两个八进制数09和07，但数字9超过了八进制所能表示的范围，它是一个无效的八进制数字，无法被编译通过。  

## 练习2.7
> 下述字面值表示何种含义？它们各自的数据类型是什么？
> (a) "Who goes with F\145rgus?\012"
> (b) 3.14e1L
> (c) 1024f
> (d) 3.14L

(a)`\145`是转义字符，它表示字符`e`，`\012`是转义字符，它表示一个换行`\n`，因此该字符串输出的结果为Who goes with Fergus?和一个换行。它的数据类型是`常量char数组`。部分转义字符详见[ASCII表](http://www.asciitable.com/)。  
(b)它是用科学计数法表示的扩展精度浮点数31.4，它的数据类型是`long double`。  
(c)它试图表示单精度浮点数，但违反了浮点型字面值规则1：无小数点的整数其后必须跟一个指数才能表示浮点型字面值。因此是无效的，浮点型字面值的规则详见[浮点字面量](https://zh.cppreference.com/w/cpp/language/floating_literal) 。  
(d)它是扩展精度浮点数3.14，它的数据类型是`long double`。  

## [练习2.8](ex02_08.cpp)
> 请利用转义序列编写一段程序，要求先输出 2M，然后转到新一行。修改程序使其先输出 2，然后输出制表符，再输出 M，最后转到新一行。

## 练习2.9
> 解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。
> (a) std::cin >> int input_value;
> (b) int i = { 3.14 };
> (c) double salary = wage = 9999.99;
> (d) int i = 3.14;

(a) 定义是非法的，其目的是从标准输入`cin`向`input_value`中输入值，但输入运算符`>>`的右侧运算对象需要一个已经定义的变量，而不能是一条定义语句。改正如下：  
```cpp
int input_value;
std::cin >> input_value;
```
(b) 定义是非法的，其目的是使用浮点字面值`3.14`初始化整型变量`i`。由于使用列表初始化且初始值存在丢失风险（`3.14`的小数部分被截断），编译器将报错。  改正如下：  
```cpp
int i = 3.14;
```
(c)  定义是非法的，其目的是定义两个浮点型变量，并将它们初始化为`9999.99`，但同时定义多个变量需要使用`,`隔开，而不能用`=`号。改正如下：  
```cpp
double salary, wage;
salary = wage = 9999.99;
```
(d) 定义是合法的，其目的是使用浮点字面值`3.14`初始化整型变量`i`。`3.14`的小数部分将被截断，`i`的值为`3`。  

## 练习2.10
> 下列变量的初值分别是什么？
```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```
`global_str`是类类型，`string`类允许不经初始化就定义对象，因此它被默认初始化，值为空串。  
`global_int`是内置类型，它定义在任何函数体之外，被默认初始化，值为`0`。  
`local_int`是内置类型，它定义在函数`main`内，不被初始化，值是未定义的。  
`local_str`是类类型，`string`类允许不经初始化就定义对象，因此它被默认初始化，值为空串。  

## 练习2.11
> 指出下面的语句是声明还是定义：
> (a) extern int ix = 1024;
> (b) int iy;
> (c) extern int iz;

(a) 它是一个定义。尽管在变量名前添加了关键字`extern`，但它将变量显式初始化了，因此抵消了`extern`的作用。
(b) 它是一个定义。因为它没有添加关键字`extern`。
(c) 它是一个声明，因为它在变量名前添加了关键字`extern`，而且没有显式初始化。

## 练习2.12
> 请指出下面的名字中哪些是非法的？
> (a) int double = 3.14;
> (b) int _;
> (c) int catch-22;
> (d) int 1_or_2 = 1;
> (e) double Double = 3.14;

(a) 非法，double是C++关键字。  
(c) 非法，标识符中只能有字母、数字和下划线，不能有符号`-`。  
(d) 非法，标识符不能以数字开头。  

## 练习2.13
> 下面程序中 j 的值是多少？
```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```
`j`的值为100。  
内层作用域可以重新定义外层作用域中已有的名字，且重新定义的名字会覆盖外层作用域中的名字，`main`函数内重新定义的局部变量`i`覆盖了全局作用域中的变量`i`。  

## 练习2.14
> 下面的程序合法吗？如果合法，它将输出什么？
```cpp
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
```
合法，输出`100 45`。  
`for`语句块拥有块作用域，在`for`循环头定义的变量`i`覆盖了外层作用域中的同名变量，因此`sum`每次加的值都是`for`循环内重新定义的变量`i`，从`0`加到了`9`。最后的输出语句位于外层作用域中，因此输出的`i`是外层作用域中值为`100`的`i`。  

## 练习2.15
> 下面的哪个定义是不合法的？为什么？
> (a) int ival = 1.01;
> (b) int &rval1 = 1.01;
> (c) int &rval2 = ival;
> (d) int &rval3 ;

(b) 不合法，引用类型只能绑定在对象上，不能绑定在字面值或表达式结果上。  
(d) 不合法，引用类型必须被初始化。  


## 练习2.16
> 考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了什么样的操作？
> int i = 0, &r1 = i; double d = 0, &r2 = d;
> (a) r2 = 3.14159;
> (b) r2 = r1;
> (c) i = r2;
> (d) r1 = d;

(a) 合法，它将字面值`3.14159`赋给了`r2`，而`r2`是绑定到`d`上的引用，因此`d`的值现在为`3.14159`。  
(b) 合法，它将变量`r1`的值赋给了`r2`，`r1`是绑定到`i`上的引用，以引用`r1`作为初始值实际上是将引用所绑定的对象`i`作为初始值，同时`r2`是绑定到`d`上的引用，因此`d`的值现在为`0.0`。  
(c) 合法，它将变量`r2`的值赋给了`i`，`r2`是绑定到`d`上的引用，以引用`r2`作为初始值实际上是将引用所绑定的对象`d`作为初始值，因此`i`的值现在为`0`。  
(d) 合法，它将变量`d`的值赋给了`r1`，`r1`是绑定到`i`上的引用，因此`i`的值现在为`0`。  

## 练习2.17
> 执行下面的代码段将输出什么结果？
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
输出`10 10`。  
引用不是对象，他只是为已经存在的对象起了一个别名，因此`ri`实际上是`i`的别名。两条赋值语句首先将`i`的值赋值为`5`，接着又通过引用`ri`将`i`赋值为`10`。  

## [练习2.18](ex02_18.cpp)
> 编写代码分别改变指针的值以及指针所指对象的值。

## 练习2.19
> 说明指针和引用的主要区别。

1. 指针指向内存中的某个对象，引用绑定到内存中的某个对象，它们都实现了对其他对象的间接访问。  
2. 指针是对象，它有一块储存自己值（所指对象的地址）的内存空间，因此可以被改变并指向几个不同的对象；引用不是对象，它只是另一个已存在对象的别名，不能让引用重新绑定到另一个对象。  
3. 指针在定义时可以不显式初始化，由于指针是内置类型，在所有函数体之外定义的未初始化的指针将被默认初始化为空指针，而在块作用域定义的未初始化的指针将不被初始化，此时它的值是未定义的；引用在定义时必须显式初始化。  

## 练习2.20
> 请叙述下面这段代码的作用。
```cpp
int i = 42;
int *p1 = &i; 
*p1 = *p1 * *p1;
```
定义一个值为`42`的变量`i`。  
定义一个指向变量`i`的指针`p1`。  
解引用指针`p1`，得到`p1`所指对象的值，将这个值与它自己相乘，得到的结果赋给`p1`所指的对象。  

## 练习2.21
> 请解释下述定义。在这些定义中有非法的吗？如果有，为什么？
> int i = 0;
> (a) double* dp = &i ;
> (b) int *ip = i;
> (c) int *p = &i ;

(a) 非法，指针的类型要和它所指向对象的类型严格匹配。不能令一个指向`double`类型的指针`dp`指向`int`类型的变量`i`。  
(b) 非法，不能把`int`变量赋给指针，即便这个变量的值是`0`也不可以。  
(c) 合法。  


## 练习2.22
> 假设 p 是一个 int 型指针，请说明下述代码的含义。
```cpp
if (p) // ...
if (*p) // ...
```
第一行将指针`p`本身的值作为判断条件，任何非空指针对应的条件值都是`true`。
第二行将指针`p`所指的`int`类型对象的值作为判断条件，如果该`int`值非0，则对应的条件值是`true`。

## 练习2.23
> 给定指针 p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

不能，指针保存的值是它指向的对象的地址，如果地址是0，即空指针，我们可以知道该指针没有指向任何对象。如果该地址非0，我们不能确定该地址是一个合法对象的地址，还是一个合法对象的下一个位置，又或者是不存在任何内容的内存空间。

## 练习2.24
> 在下面这段代码中为什么 p 合法而 lp 非法？
```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```
`void*`是一种特殊的指针类型，它可以存放任意类型对象的地址，因此`p`是合法的。  
`long*`是指向`long`类型对象的指针，它只能存放`long`类型对象的地址，而`i`是一个`int`类型，不能严格匹配，因此`lp`是非法的。  

## 练习2.25
> 说明下列变量的类型和值。
> (a) int* ip, i, &r = i;
> (b) int i, *ip = 0;
> (c) int* ip, ip2;

(a) `ip`是一个指向`int`类型的指针，它没有显式初始化，因此值由定义的位置决定；`i`是一个`int`类型变量，它也没有显式初始化，值由定义的位置决定；`r`是一个引用，它绑定到对象`i`上，是变量`i`的一个别名，值由变量`i`决定。  
(b) `i`是一个`int`类型变量，它没有显式初始化，值由定义的位置决定；`ip`是一个指向`int`类型的指针，它用字面值`0`进行初始化，表示该指针是一个空指针。  
(c) `ip`是一个指向`int`类型的指针，它没有显式初始化，因此值由定义的位置决定；`ip2`是一个`int`类型变量，它也没有显式初始化，值由定义的位置决定。  

## 练习2.26
> 下面哪些句子是合法的？如果有不合法的句子，请说明为什么？
> (a) const int buf;
> (b) int cnt = 0;
> (c) const int sz = cnt;
> (d) ++cnt; ++sz; 

(a) 不合法，const对象必须初始化。
(b) 合法。
(c) 合法。
(d) `++cnt;`合法，`++sz;`不合法，不允许改变一个`const`对象。

## 练习2.27
> 下面的哪些初始化是合法的？请说明原因。
> (a) int i = -1, &r = 0;
> (b) int *const p2 = &i2 ;
> (c) const int i = -1, &r = 0;
> (d) const int *const p3 = &i2 ;
> (e) const int *p1 = &i2 ;
> (f) const int &const r2;
> (g) const int i2 = i, &r = i;

(a) `int i = -1`合法，`int &r = 0`非法，非常量引用不能绑定到字面值上。  
(b) 合法，`p2`是一个常量指针，它永远指向`i2`。  
(c) 合法，`i`是一个`int`型常量。基本类型前的`const`对定义语句中所有变量都起作用，`r`是一个常量引用，可以绑定到字面值上。  
(d) 合法，`p3`是一个指向`int`型常量的常量指针，它永远指向`i2`，且不能通过它更改`i2`的值。  
(e) 合法，`p1`是一个指向`int`常量的指针，不能通过它更改`i2`的值。  
(f) 非法，第一个`const`表示`r2`是一个常量引用，但第二个`const`是无效的，因为引用不是对象，没法让引用恒定不变。同时引用必须初始化。  
(g) 合法，`i2`是一个`int`型常量，可以用`i`初始化它。`r`是一个常量引用，它绑定到非常量`i`上，虽然不能通过引用`r`来修改`i`的值，但可以通过其他途径修改`i`的值。  

## 练习2.28
> 说明下面的这些定义是什么意思，挑出其中不合法的。
> (a) int i, *const cp;
> (b) int *p1, *const p2;
> (c) const int ic, &r = ic;
> (d) const int *const p3; 
> (e) const int *p; 

(a) `int i`定义了一个`int`型变量，是合法的。`int *const cp`定义了一个指向`int`类型的常量指针，由于`cp`是一个常量，必须进行初始化，因此是非法的。  
(b) `int *p1`定义了一个指向`int`类型的指针，是合法的。`int *const p2`定义了一个指向`int`类型的常量指针，由于`p2`是一个常量，必须进行初始化，因此是非法的。  
(c) `const int ic`定义了一个`int`型常量，常量必须初始化，因此是非法的。`const int &r = ic`定义了一个常量引用，绑定到对象`ic`上，是合法的。  
(d) 定义了一个指向`int`型常量的常量指针，由于`p3`是一个常量，必须进行初始化，因此是非法的。  
(e) 定义了一个指向`int`型常量的指针，是合法的。  

## 练习2.29
> 假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。
> (a) i = ic; 
> (b) p1 = p3; 
> (c) p1 = &ic ;
> (d) p3 = &ic ;
> (e) p2 = p1; 
> (f) ic = *p3; 

(a) 合法，赋值时右侧运算对象既可以是常量也可以是非常量。  
(b) 非法，不能把一个指向常量的指针`p3`赋给一个普通指针`p1`。  
(c) 非法，普通指针`p1`不能指向一个常量对象`i3`。  
(d) 非法，`p3`是一个常量指针，它的值不能改变，因此不能进行赋值操作。  
(e) 非法，`p2`是一个常量指针，它的值不能改变，因此不能进行赋值操作。  
(f) 非法，`ic`是一个常量，它的值不能改变，因此不能进行赋值操作。  

## 练习2.30
> 对于下面的这些语句，请说明对象被声明成了顶层 const 还是底层 const ？
```cpp
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```
`v2`是顶层const。  
`p2`是底层const，`p3`既是底层const又是顶层const，`r2`是底层const。  

## 练习2.31
> 假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层 const 和底层 const 在每个例子中有何体现。
```cpp
r1 = v2;
p1 = p2; p2 = p1;
p1 = p3; p2 = p3;
```
1. `r1 = v2`是合法的，`r1`是一个绑定到`v1`的普通引用，`v2`是一个常量（顶层const），把`v2`的值拷贝给`r1`不会改变常量`v2`的值，因此在拷贝时顶层const没有影响。  
2. `p1 = p2`是非法的，`p1`是指向`int`型的指针，`p2`是指向`int`型常量（底层const）的指针，令`p1`指向`p2`所指的对象，将有可能错误改变`p2`所指的常量的值，因此这种拷贝是禁止的。  
3. `p2 = p1`是合法的，`int *`可以转换成`const int *`，指向常量的指针`p2`可以指向一个非常量对象，它的底层const仅意味着不能通过`p2`改变它所指对象的值。  
4. `p1 = p3`是非法的，`p1`是指向`int`型的指针，`p3`是指向`int`型常量（底层const）的常量指针（顶层const），和2的理由相同，`p3`包含底层const，不能将它的值赋给不包含底层const的`p1`。  
5. `p2 = p3`是合法的，`p2`和`p3`都包含底层const，拷贝时右侧运算对象`p3`的顶层const没有影响。  

## 练习2.32
> 下面的代码是否合法？如果非法，请设法将其修改正确。
```cpp
int null = 0, *p = null;
```
非法，不能把`int`变量赋给指针，即便这个变量的值是`0`也不可以。  
代码的意图有两种可能，一种是希望指针`p`指向变量`null`，另一种是希望将指针`p`初始化为空指针，两种可能的修改如下：  
```cpp
int null = 0, *p = &null;
```
```cpp
int null = 0, *p = nullptr;
```

## 练习2.33
> 利用本节定义的变量，判断下列语句的运行结果。
```cpp
a=42; b=42; c=42;
d=42; e=42; g=42;
```
`a`、`b`和`c`都是`int`型变量，赋值是合法的。
`d`、`e`都是指针，赋值是非法的，因为只能将整型字面值`0`赋给指针。
`g`是一个`int`型常量引用，绑定到`ci`，赋值是非法的，因为不能通过常量引用改变所绑定对象的值。

## [练习2.34](ex02_34.cpp)

> 基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？如果不对，请反复研读本节的示例直到你明白错在何处为止。

## 练习2.35
> 判断下列定义推断出的类型是什么，然后编写程序进行验证。
```cpp
const int i = 42;
auto j = i; const auto &k = i; auto *p = &i; 
const auto j2 = i, &k2 = i;
```
`j`的类型是`int`。  
`k`的类型是`const int &`。  
`p`的类型是`const int *`。  
`j2`的类型是`const int`。  
`k2`的类型是`const int &`。  
在Visual Studio等集成开发环境中输入代码，然后将鼠标移到变量名上就能看到推断出的类型。

## 练习2.36
> 关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```
`a`、`b`、`c`都是`int`类型变量，`decltype(a) c`中`c`的类型就是`a`的类型。  
`d`是一个绑定到`a`的引用，`decltype((a))`中`(a)`是一个表达式，它的结果是一个引用类型，因此`d`是一个引用。  
程序结束时，`a`、`b`、`c`和`d`的值分别为`4`、`4`、`4`、`4`。  

## 练习2.37
> 赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果 i 是 int，则表达式 i=x 的类型是 int&。根据这一特点，请指出下面的代码中每一个变量的类型和值。
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```
`a`的类型是`int`，定义时值为`3`。  
`b`的类型是`int`，定义时值为`4`。  
`c`的类型是`int`，和`a`的类型一样，同时用`a`初始化，定义时值为`3`。  
`d`的类型是`int &`，它绑定到变量`a`，值和`a`的值相同。因为`decltype`并不会实际去计算表达式的值，所以这里的赋值操作并没有发生，所以`d`的值和`a`的值都为`3`。  

## 练习2.38
> 说明由 decltype 指定类型和由 auto 指定类型有何区别。请举出一个例子，decltype 指定的类型与 auto 指定的类型一样；再举一个例子，decltype 指定的类型与 auto 指定的类型不一样。

1. auto 类型说明符让编译器通过定义变量时`=`号右侧的初始值来推断类型，decltype 类型说明符让编译器通过`decltype()`内的表达式来推断类型，但不实际计算表达式的值。  
2. 编译器推断出来的 auto 类型有时候和初始值类型不完全一样，例如auto 一般会忽略顶层 const 保留底层 const，而 decltype 则会保留顶层 const。当引用作为初始值时，auto 会推断为引用所绑定对象的类型，而 decltype 会推断为一个引用。  
3. decltype 的结果类型与表达式形式密切相关，如果变量名不加括号，那么结果就是该变量的类型，而如果变量名加了括号，那么结果就是引用类型。  
```cpp
int a = 3, &b = a;
auto c = a;        // int c = a;
decltype(a) d = a; // int d = a;
auto e = b;        // int e = b;
decltype(b) f = b; // int &f = b;
```

## 练习2.39
> 编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关的信息，以后可能会有用。
```cpp
struct Foo { /* 此处为空  */ } // 注意：没有分号
int main()
{
    return 0;
}
```
提示：应输入"`;`"    

## [练习2.40](ex02_40.cpp)
> 根据自己的理解写出 Sales_data 类，最好与书中的例子有所区别。

## [练习2.41](ex02_41)
> 使用你自己的 Sale_data 类重写1.5.1节（第20页）、1.5.2节（第21页）和1.6节（第22页）的练习。眼下先把 Sales_data 类的定义和 main 函数放在一个文件里。

## [练习2.42](ex02_42)
> 根据你自己的理解重写一个Sales_data.h头文件，并以此为基础重做2.6.2节（第67页）的练习。

该练习的目的是学习使用头文件进行编译，重做练习时只需将2.6.2节的练习中定义的类替换为`include "Sales_data.h"`，之后尝试编译文件。  