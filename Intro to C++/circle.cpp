//Anushka Verma
//01/24/2020

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{
	double circum, radius, diameter, area, x1, x2, y1, y2,pi;
	char A;

	system("clear");
	cout <<fixed<<setprecision (2);
	cout << "Enter two points";
	cin >>A>>x1>>A>>y1>>A;
	cout << "Enter two points";
	cin >>A>>x2>>A>>y2>>A;	
	
	pi=3.141592654;
	radius = sqrt (((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	diameter = radius *2;
	circum = radius *2*pi;
	area = pi *radius * radius;
	
	cout << "The Radius is:" <<radius;
	cout <<endl;
	cout << "The Diameter is:" <<diameter;
	cout << endl;
	cout << "The Circumference is:" <<circum;
	cout <<endl;
	cout << "The Area is:" <<area;
	cout <<endl;

	return 0;

}
