// it is creating 2 objects by using singletone pattern
#include<iostream>
#include<mutex>
#include<vector>
using namespace std;

class SingleToneMultiObject
{
	int x;
	static int counter;
	static int max_limit;
	static mutex mtx;
	static vector<SingleToneMultiObject*>listOfObjects;

	SingleToneMultiObject() :x(2)
	{
		cout << "Instance has created" << endl;
	}

public:
	SingleToneMultiObject(const SingleToneMultiObject& copy) = delete;
	SingleToneMultiObject& operator=(const SingleToneMultiObject* op) = delete;
	~SingleToneMultiObject()
	{

	}
	static SingleToneMultiObject* getInstance()
	{
		if (counter < max_limit)
		{
			lock_guard<mutex> lock(mtx);
			if (counter < max_limit)
			{
				SingleToneMultiObject* instance = new SingleToneMultiObject();
				listOfObjects.push_back(instance);
				counter++;
			}
		}

		int randNum = rand();
		return listOfObjects[randNum % counter];
	}
};

int SingleToneMultiObject::counter = 0;
int SingleToneMultiObject::max_limit = 2;
vector<SingleToneMultiObject*>  SingleToneMultiObject::listOfObjects;
mutex SingleToneMultiObject::mtx;

int main()
{
	srand(time(0));
	SingleToneMultiObject* st = SingleToneMultiObject::getInstance();
	SingleToneMultiObject* st1 = SingleToneMultiObject::getInstance();
	SingleToneMultiObject* st2 = SingleToneMultiObject::getInstance();
	SingleToneMultiObject* st3 = SingleToneMultiObject::getInstance();
	SingleToneMultiObject* st4 = SingleToneMultiObject::getInstance();
	SingleToneMultiObject* st5 = SingleToneMultiObject::getInstance();

	cout << st << " " << st1 << " " << st2 << endl;
	cout << st3 << " " << st4 << " " << st5 << endl;
	return 0;
}
