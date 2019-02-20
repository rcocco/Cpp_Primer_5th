9.6 节第 329 页：   
```diff
- queue 适配器要求 back、push_back、front 和 push_front。
+ queue 适配器要求 back、push_back、front 和 pop_front。
```
9.6 节第 330 页表 9.19：  
```diff
- queue 也可以用 list 或 vector 实现。
+ queue 也可以用 list 实现，但不能用 vector，因为其不支持 pop_front 操作。
```
```diff
- q.pop() 返回 queue 的首元素或 priority_queue 的最高优先级的元素，但不删除此元素
+ q.pop() 删除 queue 的首元素或 priority_queue 的最高优先级的元素，但不返回此元素
```
10.3.3 节第 352 页：
```diff
- 如果我们希望能改变一个被捕获的变量的值，就必须在参数列表首加上关键字 mutable。
+ 如果我们希望能改变一个被捕获的变量的值，就必须在紧跟着参数列表后面加上关键字 mutable。
```
11.2.2 节第 378 页：
```diff
- 小于等于
+ 小于
```
11.3.5 节第 389 页表 11.7 续：
```diff
- c.equal_range(k) 若 k 不存在，pair 的两个成员均等于 c.end()
+ c.equal_range(k) 若 k 不存在，pair 的两个成员均等于一个迭代器，该迭代器指向给定关键字的插入点，能保持容器中元素顺序的插入位置。
```
11.4 节第 394 页：
```diff
- 因此，使用无序容器通常更为简单（通常也会有更好的性能）。
+ 因此，使用有序容器通常更为简单（通常也会有更好的性能）。
```
12.1.3 节第 413 页表 12.3 续：
```diff
- shared_ptr<T> p(p2, d) 如表 12.2 所示，p 是 shared_ptr p2 的拷贝，唯一的区别是 p 将用可调用对象 d 来代替 delete
+ 不存在这个构造函数
```
12.2.1 节第 425 页：
```diff
- up.release(); // 自动用 delete[] 销毁指针
+ up.reset(); // 自动用 delete[] 销毁指针
```
16.2.5 节第 610 页：
```diff
- template <typename T> void f(T&&);        // 绑定到非 const 右值
- template <typename T> void f(const T&);   // 左值和 const 右值
- 与非模板函数一样，第一个版本将绑定到可修改的左值，而第二个版本将绑定到左值或 const 右值。
+ template <typename T> void f(T&&);        // 绑定到非 const 左值和非 const 右值
+ template <typename T> void f(const T&);   // 绑定到 const 左值和非 const 右值
+ 与非模板函数不一样，第一个版本将绑定到可修改的左值或右值，而第二个版本将绑定到不可修改的左值或右值。
```
16.3 节第 616 页：
```diff
- debug_rep(const string*&)
+ debug_rep(string * const &)
```
```diff
- 第二个版本的 debug_rep 的实例是此调用的精确匹配。第一个版本的实例需要进行普通指针到 const 指针的转换。正常函数匹配规则告诉我们应该选择第二个模板。
+ 两个版本都是此调用的精确匹配，但第二个版本更加特例化。模板的匹配规则告诉我们应该选择第二个模板。
```
```diff
- debug_rep(const string*&)，由第一个版本的 debug_rep 实例化而来，T 被绑定到 string*。
+ debug_rep(const string * const &)，由第一个版本的 debug_rep 实例化而来，T 被绑定到 const string*。
```