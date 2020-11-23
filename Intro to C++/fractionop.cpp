//Anushka Verma
//fractions
//03/03/2020
//Modification to Fraction Operations
//03/04/2020

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;
void menu();
void addition(int &x, int &y, int &bx, int &by);
void subtraction(int &x, int &y, int &bx, int &by);
void multiplication(int &x, int &y, int &bx, int &by);
void division (int &x, int &y, int &bx, int &by);
void reduction(int &x, int &y);
void GetUserInputs(int &x, int &y);
void GetComputerInputs(int &x, int &y);
int main()
{
	
	srand(static_cast<unsigned>(time(0)));	
	int a, v, f, p,option;
	char m;
	system ("clear");

        cout<<"\n\n\t\tIf You Would Like To Manually Input Fractions, The Press 1.  ";
        cout<<"\n\n\t\tIf You Would Like The Computer To Display A Random Fraction, Then Press 2. ";
	cin>>m;
	
	do
	{
	   menu();
	   cin>>option;
	   switch(option)
	   {
		case 1:
			if (m=='1')
                        {
                                cout<<"\n\n\t\tPlease Enter Two Fractions In The Form of (a/b): ";
                                GetUserInputs(a,v);
                                GetUserInputs(f,p);
                        }
                        else
                        {
                                GetComputerInputs(a,v);
                                GetComputerInputs(f,p);
                        }
			addition(a,v,f,p);
			break;

		case 2:
			if (m=='1')
                        {
                                cout<<"\n\n\t\tPlease Enter Two Fractions In The Form of (a/b): ";
                                GetUserInputs(a,v);
                                GetUserInputs(f,p);
                        }
                        else
                        {
                                GetComputerInputs(a,v);
                                GetComputerInputs(f,p);
                        }
                        subtraction(a,v,f,p);
			break;

		case 3:
			if (m=='1')
                        {
                                cout<<"\n\n\t\tPlease Enter Two Fractions In The Form of (a/b): ";
                                GetUserInputs(a,v);
                                GetUserInputs(f,p);
                        }
                        else
                        {
                                GetComputerInputs(a,v);
                                GetComputerInputs(f,p);
                        }
                        multiplication(a,v,f,p);
			break;

		case 4:
			if (m=='1')
			{
				cout<<"\n\n\t\tPlease Enter Two Fractions In The Form of (a/b): ";
				GetUserInputs(a,v);
				GetUserInputs(f,p);
			}
			else
			{
				GetComputerInputs(a,v);
				GetComputerInputs(f,p);
			}
                        division(a,v,f,p);
			break;

		case 5:
        		cout<<"\n\n\t\tIf You Would Like To Manually Input Fractions, The Press 1.  ";
        		cout<<"\n\n\t\tIf You Would Like The Computer To Display A Random Fraction, Then Press 2. ";
			cin>>m;
			break;

		case 6:
			break;

		default:
			cout<<"\n\n\t\tWrong input, please enter the correct option from the menu below.";
			break;
	   }
	} while(option !=6);
       return 0;
}


void menu()
{
	cout<<"\n\n\t\t1---Fraction Addition";
	cout<<"\n\n\t\t2---Fraction Subtraction";
	cout<<"\n\n\t\t3---Fraction Multiplication";
	cout<<"\n\n\t\t4---Fraction Division";
	cout<<"\n\n\t\t5---Switch User Input";
	cout<<"\n\n\t\t6---Exit";
	cout<<"\n\n\t\tChoose Your Option: ";
	cout<<endl;
}

void GetUserInputs(int &x, int &y)
{
	char w;
        cin>> x>> w>> y;
}

void GetComputerInputs(int &x, int &y)
{
        x= rand()%10;
        y= 1+rand()%9;
}

void addition(int &x, int &y, int &bx, int &by)
{
	int numerator, denominator;
	numerator= ((x*by) + (y*bx));
	denominator= (y*by);
	cout << "\n\n\t\t" << x << "/" <<y << "+" << bx << "/" << by<<"="<<numerator<<"/"<<denominator;
	cout<<"\n\n\t\tYour Reduced Fraction Is: ";
	reduction (numerator, denominator);
}

void subtraction(int &x, int &y, int &bx, int &by)
{
	int numerator, denominator;
	numerator= ((x*by)-(y*bx));
	denominator= (y * bx);
	cout << "\n\n\t\t"<<x << "/" << y << "-" << bx << "/" << by << "=" << numerator<<"/"<<denominator;
	reduction (numerator, denominator);
}
void multiplication(int &x, int &y, int &bx, int &by)
{
	int numerator, denominator;
        numerator= (x*bx);
        denominator= (y*by);
	cout << "\n\n\t\t"<<x << "/" << y << "*"<< bx << "/" << by <<"=" << numerator << "/" <<denominator;
        reduction (numerator, denominator);
}
	
void division(int &x, int &y, int &bx, int &by)
{
	int numerator, denominator;
        numerator= (x*by);
        denominator= (y*bx);
        cout << "\n\n\t\t"<<x << "/" << y << "/" << bx << "/" << by << "=" << numerator << "/" <<denominator;
        reduction (numerator, denominator);
}
void reduction(int &x, int &y)
{
        for (int i = y * x; i > 1; i--)

        {
             if ((y % i == 0) && (x % i == 0))

        {
             y /=i;

             x /= i;

        }


        }
        cout<<endl;
}

