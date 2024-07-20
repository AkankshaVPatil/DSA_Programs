//shared_ptr Implementation

#include<iostream>
using namespace std;

template<typename T>
class sharedptr
{
	T* res;
	int* counter;

	void incrementcounter()
	{
		if(counter)
			(*counter)++;
	}

	void decrementcounter()
	{
		if (counter)
		{
			(*counter)--;
			if (*counter == 0)
			{
				if (res != NULL)
				{
					delete res;
					delete counter;
					res = NULL;
					counter = NULL;
				}
			}
		}
	}
public:
	sharedptr(T* ptr = NULL) :res(ptr), counter(new int(1))
	{
		cout << "inside default/parametric constructor" << endl;
	}

	sharedptr(const sharedptr<T>& copy)
	{
		cout << "inside copy constructor" << endl;
		res = copy.res;
		counter = copy.counter;		
		incrementcounter();
	}

	sharedptr(sharedptr<T>&& mv)
	{
		cout << "inside move constructor" << endl;
		res = mv.res;
		counter = mv.counter;
		mv.res = NULL;
		mv.counter = NULL;
	}

	sharedptr& operator= (const sharedptr<T>& op)
	{
		cout << "inside assignment operator" << endl;
		if (this != &op)
		{
			decrementcounter();
			res = op.res;
			counter = op.counter;
			incrementcounter();
		}
		return *this;
	}

	sharedptr& operator= (sharedptr<T>&& mvop)
	{
		cout << "inside move assignment operator" << endl;
		if (this != &mvop)
		{
			decrementcounter();
			res = mvop.res;
			counter = mvop.counter;

			mvop.res = NULL;
			mvop.counter = NULL;
		}
		return *this;
	}

	~sharedptr()
	{
		decrementcounter();
	}
	T& operator*()
	{
		return *res;
	}

	T* operator->()
	{
		return res;
	}

	T& get()
	{
		return *res;
	}
		
	void resize(T *ptr = NULL)
	{
		decrementcounter();
		if (res != NULL)
		{			
			res = ptr;
			counter = new int(1);
		}
	}

	int getCounter()
	{
		return (*counter);
	}
};

int main()
{
	sharedptr<int> ptr1;//default constructor
	sharedptr<int> ptr2(new int(5));//parametric
	sharedptr<int> ptr3(ptr2);//copy
	sharedptr<int> ptr4;
	ptr4 = ptr2;//assignments

	sharedptr<int> ptr5(move(ptr3));//move
	sharedptr<int> ptr6;
	ptr6 = move(ptr4);//move assignment

	cout << *ptr5 << endl;
	//ptr2->fun();
	cout << "ptr val is :" << ptr5.get() << endl;
	cout << "ptr counter is :" << ptr5.getCounter() << endl;
	ptr5.resize();
	ptr6.resize(new int(10));
	cout << "ptr val is :" << ptr6.get() << endl;
	cout << "ptr counter is :" << ptr6.getCounter() << endl;
	return 0;
}
