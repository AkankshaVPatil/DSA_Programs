//Chain of Responsibility is behavioral design pattern 
//that allows passing request along the chain of potential handlers 
//until one of them handles request.

#include<iostream>
#include<vector>
using namespace std;	

class handler
{
public:
	virtual handler* setNext(handler* _nextHandler) = 0;
	virtual string handleRequest(string req) = 0;
};

class AbstractHandler : public handler
{
	handler* nexthandler;

public:
	AbstractHandler() :nexthandler(NULL) {}

	handler* setNext(handler* iphandler) override
	{
		this->nexthandler = iphandler;
		return iphandler;
	}

	string handleRequest(string req) override
	{
		if (nexthandler != NULL)
			return nexthandler->handleRequest(req);
		return "";
	}
};

class MonkeyHandler :public AbstractHandler
{
public:
	string handleRequest(string req) override
	{
		if (req == "banana")
			return "Monkey : I'll eat it";
		else
			return AbstractHandler::handleRequest(req);
	}
};

class SquirrelHandler :public AbstractHandler
{
public:
	string handleRequest(string req) override
	{
		if (req == "nut")
			return "Squirrel : I'll eat it";
		else
			return AbstractHandler::handleRequest(req);
	}
};

class DogHandler :public AbstractHandler
{
public:
	string handleRequest(string req) override
	{
		if (req == "meatball")
			return "Dog : I'll eat it";
		else
			return AbstractHandler::handleRequest(req);
	}
};

void ClientCode(handler& _handler)
{
	vector<string> foods = { "meatball", "nut", "banana", "coffee" };
	for (auto food : foods)
	{
		cout << "Client: who is going to eat " << food << "?" << endl;
		string response = _handler.handleRequest(food);
		if (response != "")
			cout << response << endl;
		else
			cout << "food is untouched" << endl;
	}
}
/**
 * The other part of the client code constructs the actual chain.
 */
int main() {
	MonkeyHandler* monkey = new MonkeyHandler;
	SquirrelHandler* squirrel = new SquirrelHandler;
	DogHandler* dog = new DogHandler;
	monkey->setNext(squirrel)->setNext(dog);

	/**
	 * The client should be able to send a request to any handler, not just the
	 * first one in the chain.
	 */
	std::cout << "Chain: Monkey > Squirrel > Dog\n\n";
	ClientCode(*monkey);
	std::cout << "\n";
	std::cout << "Subchain: Squirrel > Dog\n\n";
	ClientCode(*squirrel);

	delete monkey;
	delete squirrel;
	delete dog;

	return 0;
}
