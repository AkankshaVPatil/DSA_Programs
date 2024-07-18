//stack implementation using Linked List and shared smart pointer
#include<iostream>
using namespace std;

template<typename T>
class stack
{
	class LinkedList
	{
	public:
		T val;
		shared_ptr<LinkedList> next;
		LinkedList(T x)
		{
			val = x;
			next = NULL;
		}
	};

	shared_ptr<LinkedList> head;
public:
	stack()
	{
		head = NULL;
	}

	void push(T value)
	{
		//shared_ptr<LinkedList> newNode(new LinkedList(value));
		shared_ptr<LinkedList> newNode = make_shared<LinkedList>(value);
		newNode->next = head;
		head = newNode;
	}

	void pop()
	{
		if (head == NULL)
			cerr << "Stack underFlow" << endl;
		else
		{
			head = head->next;
		}
	}

	T top()
	{
		if (head == NULL)
		{
			cerr << "Stack underFlow" << endl;
			return -1;
		}
		else
			return head->val;
	}

	bool isEmpty()
	{
		return head == NULL;
	}
};

int main()
{
	stack<int> st;
	st.pop();
	cout << "peek = " << st.top() << endl;
	st.push(106);
	st.push(102);
	st.push(80);
	st.push(180);
	st.push(104);
	cout << "peek = " << st.top() << endl;
	st.pop();
	cout << "peek = " << st.top() << endl;

	return 0;
}
