//Anushka Verma
//MathGame
//Project 2
//03/28/2020

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
void menu();

class grade_1_4
{  private:
        int x;
   public:
        void get_num();
        int addition_num(grade_1_4 ob);
        int subtraction_num(grade_1_4 ob);
        int multiplication_num(grade_1_4 ob);
        int division_num(grade_1_4 ob);
        void print_num();
};
class grade_5_6
{  private:
	int numerator=0;
        int denominator=1;
   public:
	grade_5_6();
	void addition(int &x, int &y, int &bx, int &by);
	void subtraction(int &x, int &y, int &bx, int &by);
	void multiplication(int &x, int &y, int &bx, int &by);
	void division (int &x, int &y, int &bx, int &by);
        //void reduction(int &x, int &y);
	void GetComputerInputs(int &x, int &y);
};
grade_5_6::grade_5_6() :numerator(0), denominator(1)
{
}
int grade_1_4 :: addition_num(grade_1_4 ob)
{ return x + ob.x;
}
int grade_1_4 :: subtraction_num(grade_1_4 ob)
{ return x - ob.x;
}
int grade_1_4 :: multiplication_num(grade_1_4 ob)
{ return x * ob.x;
}
int grade_1_4 :: division_num(grade_1_4 ob)
{ return x / ob.x;
}

void grade_1_4 :: get_num()
{
        x = rand()%10;
}
void grade_1_4 :: print_num()
{
        cout << x;
}

void GetComputerInputs(int &x, int &y)
{
        x= 1+rand()%9;
        y= 1+rand()%9;
}
/*void reduction(int &x, int &y)
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
}*/
void addition(int &x, int &y, int &bx, int &by)
{
        int numerator, denominator;
        numerator= ((x*by) + (y*bx));
        denominator= (y*by);
        cout << "\n\n\t\t" << x << "/" <<y << "+" << bx << "/" << by<<"="<<numerator<<"/"<<denominator;
       // cout<<"\n\n\t\tYour Reduced Fraction Is: ";
   //     reduction (numerator, denominator);
}
void subtraction(int &x, int &y, int &bx, int &by)
{
        int numerator, denominator;
        numerator= ((x*by)-(y*bx));
        denominator= (y * bx);
        cout << "\n\n\t\t"<<x << "/" << y << "-" << bx << "/" << by << "=" << numerator<<"/"<<denominator;
     //   reduction (numerator, denominator);
}
void multiplication(int &x, int &y, int &bx, int &by)
{
        int numerator, denominator;
        numerator= (x*bx);
        denominator= (y*by);
        cout << "\n\n\t\t"<<x << "/" << y << "*"<< bx << "/" << by <<"=" << numerator << "/" <<denominator;
        //reduction (numerator, denominator);
}
void division(int &x, int &y, int &bx, int &by)
{
        int numerator, denominator;
	numerator= (x*by);
        denominator= (y*bx);
        cout << "\n\n\t\t"<<x << "/" << y << "/" << bx << "/" << by << "=" << numerator << "/" <<denominator;
       // reduction (numerator, denominator);
}
int main()
{  srand(static_cast<unsigned>(time(NULL)));
   int answer;
   grade_1_4 ob1, ob2, ob3, ob4, ob5, ob6, ob7, ob8;

   ob1.get_num();
   ob2.get_num();
   ob3.get_num();
   ob4.get_num();
   ob5.get_num();
   ob6.get_num();
   ob7.get_num();
   ob8.get_num();

  // int a, v, f, p,option;
  // char op;
   int option;


   system("clear");
   cout<<fixed<<setprecision (2);

   menu();
   cin>>option;
   do
        {
          // cin>>option;
           switch(option)
           {
                case 1:
			ob1.print_num();
   			cout << "+" ;
   			ob2.print_num();
        		cout << " = " <<endl;
   			cin >> answer;
   		     if(answer == ob1.addition_num(ob2))
        	     {
		     	     cout << "Fantastic!" <<endl;
		     }
		     else
        	     {	
			cout << "The Correct Answer Is "<<ob1.addition_num(ob2)<<endl;
   		     }
			ob3.print_num();
   			cout << "-";
   			ob4.print_num();
       			cout << " = " <<endl;
   			cin >> answer;
   		     if(answer == ob3.subtraction_num(ob4))
        	     {
		     	     cout << "Fabulous!"<<endl;
		     }
		     else
        	     {
		     	     cout << "The Correct Answer Is "<<ob3.subtraction_num(ob4)<<endl;
		     }
		     
		     menu();
		     cin >> option;
		     break;
	        
		case 2:
		   	ob5.print_num();
   			cout << "*";
   			ob6.print_num();
        		cout << " = " <<endl;
   			cin >> answer;
   		     if(answer == ob5.multiplication_num(ob6))
        	     {
		     	     cout << "Amazing!" <<endl;
		     }
		     else
        	     {
		     	     cout <<"The Correct Answer Is "<<ob5.multiplication_num(ob6)<<endl;
		     }
	    	     	ob7.print_num();
   		     	cout << "/";
   		     	ob8.print_num();
        	     	cout << " = " <<endl;
  		     	cin >> answer;
   		     if(answer == ob7.division_num(ob8))
        	     {
		     	     cout << "Great Job!" <<endl;
		     }
		     else
        	     {
		     	     cout <<"The Correct Answer Is "<<ob7.division_num(ob8)<<endl;
   		     }
		     
		     menu();
		     cin >> option;
		     break;
		
		case 3:
			int a, v, f, p;
   			char op;		     
			cin>>op;

		     if (op== '+' )	     
		     {	 
			     GetComputerInputs(a,v);
                             GetComputerInputs(f,p);
		     }
		     addition(a,v,f,p);
		     break;
		     menu();

	             if (op== '-' )
		     {	  

			     GetComputerInputs(a,v);
                             GetComputerInputs(f,p);
		     }
		     subtraction(a,v,f,p);
		     break;

		     if (op== '*' )
		     {	  

			  GetComputerInputs(a,v);
                          GetComputerInputs(f,p);
		     }
                     multiplication(a,v,f,p);
		     break;

		     if (op== '/' )
		     {	  

			  GetComputerInputs(a,v);
                          GetComputerInputs(f,p);
		     }
                     division(a,v,f,p);  
		     break;
		 
		case 4:
		     break;

		default:
		     	 cout<<"\n\n\t\tWrong input, please enter the correct option from the menu below.";
			 cout<<endl;
			 menu();
			 cin>>option;
		      break;
           }
	} while(option!=4);
   return 0;
}

void menu()
{
	cout<<"\n\n\t\t1---Grade 1-2";
        cout<<"\n\n\t\t2---Grade 3-4";
        cout<<"\n\n\t\t3---Grade 5-6";
        cout<<"\n\n\t\t4---Exit";
        cout<<"\n\n\t\tChoose Your Option: ";
        cout<<endl;
}

