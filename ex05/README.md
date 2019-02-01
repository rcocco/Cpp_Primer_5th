## 练习5.1
> 什么是空语句？什么时候会用到空语句？

只有一个分号`;`的语句是空语句。  
在语法上需要一条语句，但逻辑上不需要时应该使用空语句。例如循环的全部工作在条件部分就可以完成时，循环体可以使用一条空语句。  


## 练习5.2
> 什么是块？什么时候会用到块？

用花括号括起来的语句和声明序列就是块。  
在语法上需要一条语句，但逻辑上需要多条语句时应该使用块。例如循环体语法上应该是一条语句，但经常需要执行多条语句，此时需要使用块。  

## 练习5.3

> 使用逗号运算符（参见 4.10 节，第 140 页）重写 1.4.1 节（第 10 页 ）的 while 循环，使它不再需要块，观察改写之后的代码可读性提高了还是降低了。
```cpp
int sum = 0, val = 1;
while (val <= 10)
	sum += val, ++val;
```
可读性降低了。  

## 练习5.4
> 说明下列例子的含义，如果存在问题，试着修改它。
```cpp
(a) while (string::iterator iter != s.end()) { /* ... */ }
(b) while (bool status = find(word)) { /* ... */ }
	if (!status) { /* ... */ }
```
(a) 非法，程序的本意是使用迭代器对`string`对象进行遍历，但它把变量的定义和关系判断混在了一起，应改为：  
```cpp
string::iterator iter = s.begin();
while (iter != s.end()) { /* ... */ }
```
(b) 非法，变量`status`定义在`while`循环内，它的作用域仅限于`while`循环。`if`语句位于`while`循环作用域之外，无法使用`status`变量，应改为：  
```cpp
bool status;
while (status = find(word)) { /* ... */ }
if (!status) { /* ... */ }
```

## [练习5.5](ex05_05.cpp)
> 写一段自己的程序，使用 if else 语句实现把数字成绩转换成字母成绩的要求。

## [练习5.6](ex05_06.cpp)
> 改写上一题的程序，使用条件运算符（参见 4.7 节，第 134 页）代替 if else 语句。

## 练习5.7
> 改写下列代码段中的错误。
```cpp
(a) if (ival1 != ival2) 
		ival1 = ival2
    else ival1 = ival2 = 0;
    
(b) if (ival < minval) 
		minval = ival;
    	occurs = 1;
    	
(c) if (int ival = get_value())
    	cout << "ival = " << ival << endl;
    if (!ival)
    	cout << "ival = 0\n";
    	
(d) if (ival = 0)
    	ival = get_value();
```

(a) 在第二行的`ival1 = ival2`后添加`;`号。  
```cpp
if (ival1 != ival2) 
	ival1 = ival2;
else ival1 = ival2 = 0;
```
(b) 将第二行和第三行放在语句块内。  
```cpp
if (ival < minval){
	minval = ival;
    occurs = 1;
}
```
(c) 将`ival`的定义放在`if`条件的前面。  
```cpp
int ival;
if (ival = get_value())
	cout << "ival = " << ival << endl;
if (!ival)
	cout << "ival = 0\n";
```
(d) 将`if`条件部分的赋值运算符改成相等性判断运算符。  
```cpp
if (ival == 0)
	ival = get_value();
```

## 练习5.8
> 什么是“悬垂else”？C++语言是如何处理 else 子句的？

悬垂 else 是指程序中的 if 分支多余 else 分支时，如何为 else 寻找与之匹配的 if 分支问题。  
C++规定，else 与离它最近的尚未匹配的 if 匹配。  

## [练习5.9](ex05_09.cpp)
> 编写一段程序，使用一系列 if 语句统计从 cin 读入的文本中有多少元音字母。

## [练习5.10](ex05_10.cpp)
> 我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到'a'和'A'都应该递增 aCnt 的值，以此类推。

## [练习5.11](ex05_11.cpp)
> 修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。

## [练习5.12](ex05_12.cpp)
> 修改统计元音字母的程序，使其能统计以下含又两个字符的字符序列的数量： ff、fl 和 fi。

## 练习5.13
> 下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。
```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

(a) 缺少`break`语句，在执行完一个分支后还会继续执行下一个分支，  与程序意图不符。  
```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': 
	    aCnt++;
	    break;
    case 'e': 
	    eCnt++;
	    break;
    default: 
	    iouCnt++;
	    break;
}
```
(b) 不允许跨过变量`ix`的初始化语句跳转到作用域内的另一个位置。  
```cpp
unsigned index = some_value();
int ix;
switch (index) {
    case 1:
        ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size()-1;
        ivec[ ix ] = index;
}
```
(c) `case`标签中只能有一个值，且其后应该使用`:`号而不能用`,`号。  
```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1: case 3: case 5: case 7: case 9:
        oddcnt++;
        break;
    case 2: case 4: case 6: case 8: case 10:
        evencnt++;
        break;
}
```
(d) `case`标签的值必须是整型常量表达式。  
```cpp
constexpr unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```

# [练习5.14](ex05_14.cpp)
> 编写一段程序，从标准输入中读取若干 string 对象并查找连续重复出现的单词。所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。例如：如果输入是：  
`how now now now brown cow cow`  
> 那么输出应该表明单词 now 连续出现了 3 次。  

## 练习5.15
> 说明下列循环的含义并改正其中的错误。
```cpp
(a) for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)
    	// . . .
(b) int ix;
    for (ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ }
```

(a) 循环的初始化语句定义了变量`ix`，只要`ix`不等于`sz`就执行循环体，然后执行`++ix`。  
错误在于循环的初始化语句定义的变量，其作用域仅限于循环内部。 `if`语句无法使用，应改为：   
```cpp
int ix;
for (ix = 0; ix != sz; ++ix) { /* ... */ }
if (ix != sz)
    // . . .
```
(b) 错误在于`for`循环缺少了初始化语句，语法上是错误的，在不需要初始化语句时也应该使用空语句。同时`ix`没有初始化，应改为：  
```cpp
int ix;
for (ix = 0; ix != sz; ++ix) { /* ... */ }
```
(c) 错误在于条件语句中不等运算符两侧运算对象`ix`和`sz`同时增长，只要`ix`初始不为`0`，循环条件将永远满足，无法结束。  
```cpp
for (int ix = 0; ix != sz; ++ix) { /*...*/ }
```

## [练习5.16](ex05_16)
> while 循环特别适用于那种条件保持不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for 循环更像是在按步骤迭代，它的索引值在某个范围内依次变化。根据每种循环的习惯各自编写一段程序，然后分别用另一种循环改写。如果只能使用一种循环，你倾向于哪种？为什么？

如果只能使用一种，倾向于`for`循环，因为它结构严谨，便于控制程序逻辑。  

## [练习5.17](ex05_17.cpp)
> 假设有两个包含整数的 vector 对象，编写一段程序，检验其中一个 vector 对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的 vector 对象，只需挑出长度较短的那个，把它的所有元素和另一个 vector 对象比较即可。例如，如果两个 vector 对象的元素分别是0、1、1、2 和 0、1、1、2、3、5、8，则程序的返回结果应该为真。

## 练习5.18
> 说明下列循环的含义并改正其中的错误。
```cpp
(a) do
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while (cin);
(b) do {
        // ...
    } while (int ival = get_response());
(c) do {
        int ival = get_response();
    } while (ival);
```
(a) 循环不断接受两个数字然后输出它们的和，由于`do while`循环的循环体语法上要求一条语句，这里多条语句需要使用花括号括起来形成语句块。  
```cpp
do {
    int v1, v2;
    cout << "Please enter two numbers to sum:" ;
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
} while (cin);
```
(b) 当`get_response`函数的返回值不为`0`时执行循环体，由于do while`循环不允许在条件部分定义变量，应改为：
```cpp
int ival;
do {
	// ...
} while (ival = get_response());
```
(c) 当`get_response`函数的返回值不为`0`时执行循环体，由于在循环体内定义的变量，作用域仅限于循环体内，条件部分无法使用该变量，应改为：  
```cpp
int ival;
do {
    ival = get_response();
} while (ival);
```

## [练习5.19](ex05_19.cpp)
> 编写一段程序，使用 do while 循环重复地执行下述任务：首先提示用户输入两个 string 对象，然后挑出较短的那个并输出它。

## [练习5.20](ex05_20.cpp)
> 编写一段程序，从标准输入中读取 string 对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。使用 while 循环一次读取一个单词，当一个单词连续出现两次时使用 break 语句终止循环。输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。

## [练习5.21](ex05_21.cpp)
> 修改 5.5.1 节（第 171 页）练习题的程序，使其找到的重复单词必须以大写字母开头。

## 练习5.22
> 本节的最后一个例子跳回到 begin，其实使用循环能更好的完成该任务，重写这段代码，注意不再使用 goto 语句。
```cpp
int sz;
do {
	sz = get_size();
} while (sz <= 0);
```

## [练习5.23](ex05_23.cpp)
> 编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。

## [练习5.24](ex05_24.cpp)
> 修改你的程序，使得当第二个数是 0 时抛出异常。先不要设定 catch 子句，运行程序并真的为除数输入0，看看会发生什么？

## [练习5.25](ex05_25.cpp)
> 修改上一题的程序，使用 try 语句块去捕获异常。catch 子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行 try 语句块的内容。