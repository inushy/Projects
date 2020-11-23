//Solving Quadratic Equation
//Anushka Verma
//02/04/2020
//Updated on 02/05/2020
 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{  
    double A, B, C, D, q, x1, x2;
    char end = 'y';	
    system ("clear");
    cout << fixed << setprecision (2);
    while (end == 'y')
    {	    
    cout << "Enter A, B, C Values:\n";
    cin >> A >> B >> C;

    cout << "Formula:\n";
    cout << A << "x^2 +" << B << "x+" << C << "=" << '0';
    cout <<endl;

    D = ((B*B) - (4*A*C));
    if (A <= 1.0 && B<= 1.0)
    {
	    cout << "The Equality is x^2 + x (" << C <<") = 0" <<endl;
    }
    else if (A <= 1.0 && B >=1.0)
    {
	    cout << "The Equality is x^2 + (" << B << ") x + (" << C << ") = 0" <<endl;
    }
    else if (A >= 1.0 && B <= 1.0)
    {
	    cout << "The Equality is (" << A << ")^2 + x + (" << C << ")= 0" <<endl;
    }

    else
    { 
	    cout << "The Equality is (" << A << ")^2 + (" << B << ")x + (" << C << ") = 0" <<endl;
    }

    if (D < 0) 
    {
	    cout<< "No real number solutions"<< endl;
    }
    
    else if (abs (D) <0.01)
    {
	    cout<< "The Solution is:" <<- (B/(2.0*A));
    } 
    else
    {
	    q =sqrt (D);
	    x1 = (-B + q)/(2.0*A);
	    x2 = (-B - q)/(2.0*A);

	    cout << "You have 2 solutions:" << x1 << "," << x2 << endl;
    }
	cout << "would you like to continue y or n?" << endl;
	cin >> end;
    }
    return 0;
}

