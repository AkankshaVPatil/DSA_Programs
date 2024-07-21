//define subcription mechanism to notify multiple objects about any event
#include<iostream>
#include<list>
using namespace std;

class Isubscriber
{
public:
	virtual void Notify(string notification) = 0;
};

class user :public Isubscriber
{
	int id;
public:
	user(int idx) :id(idx) {}
	void Notify(string notif)override
	{
		cout << id << " : " << notif << endl;
	}
};

class Group
{
	list<Isubscriber*>users;
public:
	void subscribe(Isubscriber* user)
	{
		users.push_back(user);
	}
	void unsubscribe(Isubscriber* user)
	{
		users.remove(user);
	}
	void Notify(string notif)
	{
		for (auto user : users)
			user->Notify(notif);
	}
};
int main()
{
	Group* group = new Group();

	user* user1 = new user(1);
	user* user2 = new user(2);
	user* user3 = new user(3);

	group->subscribe(user1);
	group->subscribe(user2);
	group->subscribe(user3);

	group->Notify("Hi");

	group->unsubscribe(user2);
	group->Notify("Hello");

	return 0;
}
