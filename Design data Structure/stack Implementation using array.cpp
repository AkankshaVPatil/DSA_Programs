//stack Implementation using array

#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

template<typename T>
class stack
{
	T* arr;
	int top;
	int capacity;

public:
	stack(int size)
	{
		top = -1;
		capacity = size	;
		arr = new T[size];
	}

	void push(T val)
	{
		if (capacity == top + 1)
			throw overflow_error("stacl overflow");
		arr[++top] = val;
	}

	void pop()
	{
		if (top == -1)
			throw underflow_error("stack underflow");
		
		top--;
	}

	T peek()
	{
		if (top == -1)
			throw underflow_error("stack underflow");
		
		return arr[top];
	}

	bool isFull()
	{
		return top + 1 == capacity;
	}

	bool isEmpty()
	{
		return top == -1;
	}
	int size()
	{
		return top + 1;
	}
};

int main()
{
	try
	{
		stack<int> intStack(5);
		intStack.push(1);
		intStack.push(2);
		intStack.push(3);

		std::cout << "Top element is: " << intStack.peek() << std::endl;
		std::cout << "Stack size is: " << intStack.size() << std::endl;

		intStack.pop();
		std::cout << "Top element after pop is: " << intStack.peek() << std::endl;

		stack<string> stringStack(3);
		stringStack.push("Hello");
		stringStack.push("World");

		std::cout << "Top string is: " << stringStack.peek() << std::endl;
		std::cout << "String stack size is: " << stringStack.size() << std::endl;
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}
