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
	Transport(string from_Location,string to_Location,int Capacity , float _Speed):From_Location(from_Location),To_Location(to_Location),capacity(Capacity),speed(_Speed)
	{passengers=0;}
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
	Taxi(string from_Location,string to_Location,float Speed,string DriverName):driverName(DriverName),Transport(from_Location,to_Location,4,Speed)
	{}
	void print()
	{
		cout<<"Taxi :"<<endl;
		cout<<"capacity:"<<capacity<<"\n passengers:"<<passengers;
		cout<<"\n speed"<<Speed();
		cout<<"\n from:"<<From();
		cout<<"\n to:"<<To();
		cout<<"\n Driver name: "<<driverName;
	}
};
class Bus:public Transport
{
	string driverName;
public:

	// type 1 means capacity =40
	// type 2 means capacity =50
	// type 3 means capacity =60
	// else capacity =75

	Bus(string from_Location,string to_Location,int type,string DriverName):driverName(DriverName),Transport(from_Location,to_Location,0,10)
	{
	    switch(type)
	    {
        case 1:
            capacity=40;
            break;
	    case 2:
	        capacity=50;
            break;
        case 3:
            capacity=60;
            break;
        default:
            capacity=75;

	    }


	}
	void print()
	{
		cout<<"Bus :"<<endl;
		cout<<"capacity:"<<capacity;
		cout<<"\n passengers:"<<passengers;
		cout<<"\n speed"<<Speed();
		cout<<"\n from:"<<From();
		cout<<"\n to:"<<To();
		cout<<"\n Driver name: "<<driverName;

	}
};
class Ship:public Transport
{
	public:
	// the ship is too large to consider its capacity so each new passenger
	// can book a ticket without the problem of capacity. the ship speed is 100 m/s
	// complete the constructor
	Ship(string from_Location,string to_Location):Transport(from_Location,to_Location,capacity ,100)
	{}
	// update the book function to ignore the capacity
	int book()
	{
	    passengers++;
	    return passengers;
     }
	// complete the function to print the ship informations
	void print()
	{
		cout<<"Ship :"<<endl;
		cout<<"capacity:"<<capacity;
		cout<<"\n passengers:"<<passengers;
		cout<<"\n speed"<<Speed();
		cout<<"\n from:"<<From();
		cout<<"\n to:"<<To();

	}
	// update the book function to ignore the capacity
	bool empty_spaces()
	{
	    return true;
	}
};
// complete a function that passes through the array t of length n and search for a Transport
// that moves from "from" string to "to" string with the highest speed and return its index
// this transport should have empty spaces to book.
// the function return -1 if found nothing
int findbest( Transport* t[],int n,string from,string to)
{
    float max=-2;
    int i=0;
    int ret_val;
    for(i=0;i<n;i++)
    {
        if((t[i]->Speed())>max && (t[i]->book())!= -1 &&(t[i]->From())==from && (t[i]->To())==to)
           {
             max=t[i]->Speed();
             ret_val =i;
           }

    }
    if(max==0)
    { ret_val=-1;}
    return ret_val;
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
	int c=findbest(t,7,"Assiut","Minia");
	cout<<c;
	return 0;
}

