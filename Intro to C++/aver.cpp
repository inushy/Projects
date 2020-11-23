//Average Max Loop
//Anushka Verma
//02/10/2020

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{  int i, max, count= 0;
   double average, sum= 0;

   system ("clear");
   cout << fixed << setprecision(2);

   cout << "Enter the student's score (-1) to stop" <<endl;
   cin >>i;
   max= i;

   while (i!= -1)
   { sum = sum + i;
     count++;
     if(i > max)
	     max=i;
     cin >>i;

   }
   if (count!= -1)
   { average = sum/count;
     cout <<"\nThe Average is:"<<average<<endl; 
     cout <<"The Largest Number is:"<<max<<endl;
   }
   else
	   cout<<"No Number Entered"<<endl;
   return 0;
}	
