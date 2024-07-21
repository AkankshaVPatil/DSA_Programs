//Abstract Factory is a creational design pattern that lets you produce families of related objects without specifying their concrete classes.

#include<iostream>
using namespace std;

class IButton
{
public:
	virtual void pressed() = 0;
};

class MacButton:public IButton
{
public:
	void pressed()
	{
		cout << "mac Button Pressed" << endl;
	}
};

class WinButton :public IButton
{
public:
	void pressed()
	{
		cout << "Win Button Pressed" << endl;
	}
};

class ITextbox
{
public:
	virtual void ShowText() = 0;
};

class MacTextbox :public ITextbox
{
public:
	void ShowText()
	{
		cout << "mac Textbox Pressed" << endl;
	}
};

class WinTextbox :public ITextbox
{
public:
	void ShowText()
	{
		cout << "Win Textbox Pressed" << endl;
	}
};

class IFactory
{
public:
	virtual IButton* createButton() = 0;
	virtual ITextbox* createTextBox() = 0;
};

class macFactory :public IFactory
{
public:
	IButton* createButton()
	{
		return new MacButton();
	}
	ITextbox* createTextBox()
	{
		return new MacTextbox();
	}
};

class winFactory :public IFactory
{
public:
	IButton* createButton()
	{
		return new WinButton();
	}
	ITextbox* createTextBox()
	{
		return new WinTextbox();
	}
};

class GUIAbstractFactory
{
public: 
	static IFactory* GetInstance(string osType)
	{
		if (osType == "MAC")
			return new macFactory();
		else if (osType == "WIN")
			return new winFactory();
		return new macFactory();
	}
};
int main()
{
	cout << "Enter OS:" << endl;
	string osType;
	cin >> osType;

	IFactory* piFactory = GUIAbstractFactory::GetInstance(osType);

	IButton* piButton = piFactory->createButton();
	piButton->pressed();

	ITextbox* piTextbox = piFactory->createTextBox();
	piTextbox->ShowText();

	return 0;
}
