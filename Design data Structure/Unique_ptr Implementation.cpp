//Unique_ptr Implementation.cpp
#include<iostream>
using namespace std;

template<typename T>
class uniquePtr
{
	T* res;

public:
	uniquePtr(T* x = NULL) :res(x)
	{
		cout << "ctor called" << endl;
	}

	uniquePtr(const uniquePtr<T>& copy) = delete;
	uniquePtr operator= (const uniquePtr<T>& op) = delete;

	uniquePtr(uniquePtr<T>&& mv)
	{
		res = mv.res;
		mv.res = NULL;
	}

	uniquePtr& operator=(uniquePtr<T>&& op)
	{
		if (res != NULL)
			delete res;
		res = op.res;
		op.res = NULL;
		return *this;
	}

	T& operator*()
	{
		return *res;
	}

	T& get()
	{
		return *res;
	}

	void resize(T* newRes)
	{
		if (res != NULL)
			delete res;
		res = newRes;
	}
};
int main()
{
	uniquePtr<int> ptr1(new int(5));//constructor call
	//uniquePtr<int> ptr2 = ptr1;//compilation error for copu constructor call
	//uniquePtr<int> ptr3;
	//ptr3 = ptr1;//compilation error for assignment operator

	uniquePtr<int> ptr4 = move(ptr1); // move constructor
	uniquePtr<int> ptr5;
	ptr5 = move(ptr4);// move assignment operator

	cout << *ptr5 << endl;
	ptr1.get();
	ptr1.resize(new int(10));
	return 0;
}
