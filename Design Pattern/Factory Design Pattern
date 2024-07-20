//problem with factory method: if client want to create now truck type of vehical,
// in this client need to change code in his side. as client is tightly coupled.
// factory design Pattner has introduced.

#include<iostream>
using namespace std;

class vehicle
{
public:
	virtual void createVehicle() = 0;
};

class Car :public vehicle
{
public:
	void createVehicle() override
	{
		cout << "Car has created" << endl;
	}
};

class Bike :public vehicle
{
public:
	void createVehicle() override
	{
		cout << "Bike has created" << endl;
	}
};

class vehicleFactory
{
public:
	static vehicle* getVehicleInstance(const string& vehicletype)
	{
		vehicle* pvehicle = NULL;
		if (vehicletype == "car")
			pvehicle = new Car();
		else if (vehicletype == "bike")
			pvehicle = new Bike();

		pvehicle->createVehicle();

		return pvehicle;
	}
};
int main()
{
	string vehicletype = "";
	cout << "Create vehical of type:" << endl;
	cin >> vehicletype;

	//new code after adding factory class
	vehicle* pvehicle = vehicleFactory::getVehicleInstance(vehicletype);

	//OLD
	/*vehicle* pvehicle = NULL;
	if (vehicletype == "car")
		pvehicle = new Car();
	else if (vehicletype == "bike")
		pvehicle = new Bike();

	pvehicle->createVehicle();*/
	return 0;
}
