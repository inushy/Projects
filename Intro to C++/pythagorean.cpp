//Anushka Verma
//02/24/2020
//Pythagorean Theorem

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void pythagorean (double x, double y);
int main()
{
	double a,b;
        system ("clear");
	cout << fixed << setprecision(2);
	cout << "Enter values for x and y";
	cin >> a >> b; 

	cout << "your c value is:";
        pythagorean(a,b);

	return 0;
}
void pythagorean (double x, double y)
{

      	double z;
	z = sqrt(pow (x , 2) + pow (y , 2));
	

	cout << z;
	cout <<endl;
}

