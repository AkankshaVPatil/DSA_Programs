//stack Implementation using dynamic array
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

	void resize(int cap)
	{
		cap = max(cap, 2);
		T* newArray = new T[cap];
		for (int i = 0; i < capacity; i++)
			newArray[i] = arr[i];
		delete []arr;
		capacity = cap;
		arr = newArray;
	}
public:
	stack(int size)
	{
		top = -1;
		capacity = size	;
		arr = new T[size];
	}
  ~stack()
  {
    delete []arr;
  }
	void push(T val)
	{	
		arr[++top] = val;
		if (capacity == top + 1)
			resize(capacity * 2);
	}

	void pop()
	{
		if (top == -1)
			throw underflow_error("stack underflow");
		
		top--;
		if (top > 0 && top == capacity / 4)
			resize(capacity / 2);
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
