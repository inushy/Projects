//Anushka Verma
//01/27/2020

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	double radius,area, circum, volume, surface;
	const double pi= 3.1415926;

	system ("clear");
	
	cout<<fixed<<setprecision(2);
	
	cout << "Enter the radius:";
	cin>>radius;

	cout <<endl;

	area= pi*radius*radius;
	circum= 2*pi*radius;
	volume= 4/3*pi*radius*radius*radius;
	surface= 4*pi*radius*radius;

	cout << "The Area is:" <<area;
	cout <<endl;
	cout << "The Circumference is:" <<circum;
	cout <<endl;
	cout << "The Volume is:" <<volume;
	cout <<endl;
	cout << "The Surface is:" <<surface;
	cout <<endl;

	return 0;

}


