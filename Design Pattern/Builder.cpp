//Construct complex objects step by step

#include<iostream>
using namespace std;

class Desktop
{
private:
	string monitor;
	string mouse;
	string keyboard;
	string ram;
	string processor;
	string CPU;
public:
	void setMonitor(string str)
	{
		monitor = str;
	}
	void setMouse(string str)
	{
		mouse = str;
	}
	void setKeyboard(string str)
	{
		keyboard = str;
	}
	void setRam(string str)
	{
		ram = str;
	}
	void setProcessor(string str)
	{
		processor = str;
	}
	void setCPU(string str)
	{
		CPU = str;
	}
	void getSpecs()
	{
		cout << "---------------------------------------------" << endl;
		cout << "Monitor is " << monitor << endl;
		cout << "Mouse is " << mouse << endl;
		cout << "KeyBoard is " << keyboard << endl;
		cout << "Ram is " << ram << endl;
		cout << "Processor is " << processor << endl;
		cout << "CPU is " << CPU << endl;
		cout << "---------------------------------------------" << endl;
	}
};

class DesktopBuilder
{
protected:
	Desktop* desktop;
public:
	DesktopBuilder() {
		desktop = new Desktop();
	}
	virtual void BuildMonitor() = 0;
	virtual void BuildMouse() = 0;
	virtual void BuildKeyboard() = 0;
	virtual void BuildRam() = 0;
	virtual void BuildProcessor() = 0;
	virtual void BuildCPU() = 0;

	Desktop* getDesktop()
	{
		return desktop;
	}
};

class HPDesktopBuilder:public DesktopBuilder
{
public:
	void BuildMonitor()
	{
		desktop->setMonitor("HP Monitor");
	}
	void BuildMouse()
	{
		desktop->setMouse("HP Mouse");
	}
	void BuildKeyboard()
	{
		desktop->setKeyboard("HP KeyBoard");
	}
	void BuildRam()
	{
		desktop->setRam("HP RAM");
	}
	void BuildProcessor()
	{
		desktop->setProcessor("HP Processor");
	}
	void BuildCPU()
	{
		desktop->setCPU("HP CPU");
	}
};
class DELLDesktopBuilder :public DesktopBuilder
{
public:
	void BuildMonitor()
	{
		desktop->setMonitor("DELL Monitor");
	}
	void BuildMouse()
	{
		desktop->setMouse("DELL Mouse");
	}
	void BuildKeyboard()
	{
		desktop->setKeyboard("DELL KeyBoard");
	}
	void BuildRam()
	{
		desktop->setRam("DELL RAM");
	}
	void BuildProcessor()
	{
		desktop->setProcessor("DELL Processor");
	}
	void BuildCPU()
	{
		desktop->setCPU("DELL CPU");
	}
};

class DesktopDirector
{
	DesktopBuilder* desktopBuilder;
public:
	DesktopDirector(DesktopBuilder* pDesktopBuilder) : desktopBuilder(pDesktopBuilder) {}

	Desktop* BuildDesktop()
	{
		desktopBuilder->BuildMonitor();
		desktopBuilder->BuildMouse();
		desktopBuilder->BuildKeyboard();
		desktopBuilder->BuildCPU();
		desktopBuilder->BuildRam();
		desktopBuilder->BuildProcessor();
		return desktopBuilder->getDesktop();
	}
};

int main()
{
	HPDesktopBuilder* pHPDesktopBuilder = new HPDesktopBuilder();
	DELLDesktopBuilder* pDELLDesktopBuilder = new DELLDesktopBuilder();

	DesktopDirector* pDesktopDirector1 = new DesktopDirector(pHPDesktopBuilder);
	DesktopDirector* pDesktopDirector2 = new DesktopDirector(pDELLDesktopBuilder);

	Desktop * pHPdesktop = pDesktopDirector1->BuildDesktop();
	Desktop* pDELLdesktop = pDesktopDirector2->BuildDesktop();

	pHPdesktop->getSpecs();
	pDELLdesktop->getSpecs();
	return 0;
}
