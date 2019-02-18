#include <iostream>
#include <string>
/*
 * see https://stackoverflow.com/questions/21598635/how-is-a-template-instantiated
 */
template <typename T> class Stack {
	// compiler will find T not has "ThisDoesntExist"
	// only when instantiation
	typedef typename T::ThisDoesntExist StaticAssert;
};
void f1(Stack<char>); // No instantiation, compiles
class Exercise {
public:
	Exercise(Stack<double> r);
	Stack<double> &rsd; // No instantiation, compiles (references don't need instantiation, are similar to pointers in this)
	//Stack<int>    si; // Instantiation! Doesn't compile!!
};
int main() {
	Stack<char> *sc; // No Instantiation, this compiles successfully since a pointer doesn't need instantiation
	//f1(*sc); // Instantiation of Stack<char>! Doesn't compile!!
	//int iObj = sizeof(Stack<std::string>); // Instantiation of Stack<std::string>, doesn't compile!!
	return 0;
}