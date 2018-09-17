#include <iostream>
#include <string>
using namespace std;
class Transport
{
protected:
	int capacity;
	int passengers;
private:
	float  speed;
	string From_Location;
	string To_Location;
public:
	Transport(string from_Location,string to_Location,int Capacity , float _Speed):From_Location(from_Location),To_Location(to_Location),capacity(Capacity),speed(Speed)
	{}
	virtual bool empty_spaces()
	{  bool vacancy;
       if(passengers==capacity)
        vacancy=true;
       return vacancy;
	}
	string From() { return From_Location;}
	string To() { return To_Location;}
	virtual int book()
	{
	 int index;
     passengers++;
	 if(passengers>capacity)
        {index=-1;
        passengers=capacity;}
     else
        index=passengers;
     return passengers;
	}
	virtual void print()
	{
	    cout<<"capacity:"<<capacity<<"\n passengers:"<<passengers<<"\n speed"<<speed<<"\n from:"<<From_Location<<"\n to:"<<To_Location;
	}
	float time(float distance)
	{
       float t=distance/speed;
       return t;
	}
	float Speed()
	{
		return speed;
	}
};
class Taxi:public Transport
{
	string driverName;
public:
	// complete the constructor to initialize the Taxi informations
	Taxi(string from_Location,string to_Location,float Speed,string DriverName)
	{	}
	// complete the function to print the Taxi informations
	void print()
	{
		cout<<"Taxi :"<<endl;
	}
};
class Bus:public Transport
{
	string driverName;
public:
	// complete the constructor to initialize the Bus informations
	// type 1 means capacity =40
	// type 2 means capacity =50
	// type 3 means capacity =60
	// else capacity =75

	Bus(string from_Location,string to_Location,int type,string DriverName)
	{
	}
	// complete the function to print the Bus informations
	void print()
	{
		cout<<"Bus :"<<endl;
	}
};
class Ship:public Transport
{
	public:
	// the ship is too large to consider its capacity so each new passenger
	// can book a ticket without the problem of capacity. the ship speed is 100 m/s
	// complete the constructor
	Ship(string from_Location,string to_Location)
	{
	}
	// update the book function to ignore the capacity
	int book()
	{
	}
	// complete the function to print the ship informations
	void print()
	{
		cout<<"Ship :"<<endl;
	}
	// update the book function to ignore the capacity
	bool empty_spaces()
	{
	}
};
// complete a function that passes through the array t of length n and search for a Transport
// that moves from "from" string to "to" string with the highest speed and return its index
// this transport should have empty spaces to book.
// the function return -1 if found nothing
int findbest( Transport* t[],int n,string from,string to)
{
}
int main()
{
	Transport* t[7];
	t[0]= (Transport*) new Taxi("Assiut","Minia",20,"Hassneen");
	t[1]= (Transport*) new Taxi("Assiut","Minia",25,"Rageb");
	t[2]= (Transport*) new Ship("Egypt","Italy");
	t[3]= (Transport*) new Ship("Italy","Egypt");
	t[4]= (Transport*) new Bus("Assiut","Cairo",1,"ahmed");
	t[5]= (Transport*) new Bus("Cairo","Assiut",2,"mohamed");
	t[6]= (Transport*) new Bus("Cairo","Assiut",2,"mohamed");
}

