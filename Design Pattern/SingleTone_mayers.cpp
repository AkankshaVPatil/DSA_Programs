//Meyers' Singleton
//The simplest and recommended way in C++11 and beyond is using the local static variable. 
//The C++11 standard guarantees that the initialization of local static variables is thread-safe.
//No need to use lock and public static veriable

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

class Logger
{
	Logger()
	{
		cout << "In Logger Constructor" << endl;
	}

	Logger(const Logger& copy);
	Logger& operator=(const Logger& op);

public:
	static Logger* getInstance()
	{
		static Logger* instance;
		return instance;
	}

	void log(string str)
	{
		cout << str << endl;
	}
};

void user1Log()
{
	Logger* user1 = Logger::getInstance();
	user1->log("user1 : log has created");
}

void user2Log()
{
	Logger* user2 = Logger::getInstance();
	user2->log("user2 : log has created");
}
int main()
{
	thread t1(user1Log);
	thread t2(user2Log);

	t1.join();
	t2.join();

	return 0;
}
