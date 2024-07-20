//SingleTone pattern - allowed to create only one instance
//its safe for multithreding, as it has used LOCK and double check instance
//testecase also shows multithread scenario by creating 2 thread

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

class Logger
{
	static Logger* instance;
	static mutex mtx;
	Logger()
	{
		cout << "In Logger Constructor" << endl;
	}

	Logger(const Logger& copy);
	Logger& operator=(const Logger& op);

public:
	static Logger* getInstance()
	{
		if (instance == NULL)
		{
			mtx.lock();
			if (instance == NULL)
				instance = new Logger();
			mtx.unlock();
		}
		return instance;
	}

	void log(string str)
	{
		cout << str << endl;
	}
};

Logger* Logger::instance = NULL;
mutex Logger::mtx;

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
