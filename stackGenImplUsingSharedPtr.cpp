#include<iostream>
using namespace std;

template<typename T>
class Stack
{

	class Node
	{
	public:
		T val;
		shared_ptr<Node> next;
		
		Node(const T& data)
		{
			val = data;
			next = NULL;
		}
	};

	shared_ptr<Node> head;
	int sz;
public:

	Stack()
	{
		head = NULL;
		sz = -1;
	}

	void push(const T &data)
	{
		auto newNode = make_shared<Node>(data);
		newNode->next = head;
		head = newNode;
		sz++;
	}

	void pop()
	{
		if (sz < 0)
		{
			cout << "stack underflow" << endl;
			return;
		}

		head = head->next;
		sz--;
	}

	T peek()
	{
		if (sz < 0)
		{
			cout << "stack underflow" << endl;
			return -1;
		}

		return head->val;
	}

	bool isEmpty()
	{
		return sz == -1;
	}

	int getsize()
	{
		return sz;
	}
};


//int main()
//{
//	Stack<int>st;
//	st.pop();
//	cout << "peek = " << st.peek() << endl;
//	cout << "size =" << st.getsize() << endl;
//	cout << "capacity = " << st.getsize() << endl;
//	st.push(106);
//	st.push(102);
//	st.push(80);
//	st.push(180);
//	cout << "capacity = " << st.getsize() << endl;
//	st.push(104);
//	cout << "capacity = " << st.getsize() << endl;
//	st.push(1065);
//	cout << "capacity = " << st.getsize() << endl;
//	st.push(1020);
//	cout << "peek = " << st.peek() << endl;
//	cout << "size =" << st.getsize() << endl;
//	cout << "capacity = " << st.getsize() << endl;
//	st.pop();
//	st.pop();
//	cout << "peek = " << st.peek() << endl;
//	cout << "size =" << st.getsize() << endl;
//
//	return 0;
//}