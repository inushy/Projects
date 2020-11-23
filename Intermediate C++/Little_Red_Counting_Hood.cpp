//Anushka Verma
//06/10/2020
//Portfolio 1 - Lab 2

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "Little_Red_Counting_Hood.h"

using namespace std;
bool answerIsCorrect(char answer);


Count::Count(int n)
{
   num = 0;
   if (n > 0 && n <= 9999)
   {
       max = n;
   }
   else
   {
       cout << "You've set counter to an unacceptable value." << endl;
       cout << "You're counter is set to a limit of 9999 by default." << endl;
       max = 9999;
   }
   above = false;
   return;
}


void Count::Inc1(int x)
{
   if (num + x > max)
   {
       above = true;
   }
   else
   {
       num = num + x;
   }
   return;
}

void Count::Inc10(int x)
{
   if (num + 10 * x > max)
   {
       above = true;
   }
   else
   {
       num = num + 10 * x;
   }
   return;
}

void Count::Inc100(int x)
{
   if (num + 100 * x > max)
   {
       above = true;
   }
   else
   {
       num = num + 100 * x;
   }
   return;
}

void Count::Inc1000(int x)
{
   if (num + 1000 * x >= max)
   {
       above = true;
   }
   else
   {
       num = num + 1000 * x;
   }
   return;
}


bool Count::overf()
{
   return above;
}


void Count::reset()
{
   above = false;
   num = 0;
   return;
}

void Count::setLim(int n)
{
   reset();
   if (n > 0 && n <= 9999)
   {
       max = n;
   }
   else
   {
       cout << "You've set counter to an unacceptable value." << endl;
       cout << "You're counter is set to a limit of 9999 by default.";
       max = 9999;
   }
}

int Count::getCount()
{
   return num;
}

int Count::getLim()
{
   return max;
}


int main()
{
   char answer;
   double p = 00.00;
   int n = 0;
   cout << "\n\n\n\t\tEnter the limit for the counter (1-9999): ";
   cin >> n;
   Count Count(n);
    p = Count.getCount()/100.00;
    cout << "\n\n\n\t\tCurrent value of counter is: " << Count.getCount()<< " " <<"The limit of the counter is: " << Count.getLim() << fixed << setprecision(2) << " $" << p <<endl;
   cout <<"\n\t\t--------------------------------------------------------------------";
   cout <<"\n\n\t\t";
   cout <<"Your Options Are: " << endl;
   cout <<"\n\t\t";
   cout << "a - for cents " << endl;
   cout <<"\n\t\t";
   cout << "v - for dimes " << endl;
   cout <<"\n\t\t";
   cout << "s - for dollars " << endl;
   cout <<"\n\t\t";
   cout << "h - for tens of dollars " << endl;
   cout <<"\n\t\t";
   cout << "u - for overflow " << endl;
   cout <<"\n\t\t";
   cout << "n - for reset " << endl;
   cout <<"\n\t\t";
   cout << "k - to set counter" << endl;
   cout <<"\n\t\t";
   cout << "e - to quit:" << endl;
   cout <<"\n\t\tYou chose: ";
   cin >> answer;

   while (answerIsCorrect(answer))
   {
       if (answer == 'a')
       {
           int o;
	       cout <<"\n\t\t";
           cout << "Enter(1 - 9) to increment : ";
           cin >> o;
           while (o <= 0)
           {
           cout <<"\n\t\t";
               cout << "Enter(1 - 9) to increment(you entered an unacceptable number) : ";
               cin >> o;
           }
           Count.Inc1(o);
           if (Count.overf())
           {
               
	       cout <<"\n\t\t";
               cout << "You've gone beyond " << Count.getLim() << " which is the limit of the counter by " << (Count.getCount() + o) - Count.getLim()
		    << " Your Counter is being reset to 0." << endl;
	       Count.reset();
           }
       }
       else if (answer == 'v')
       {
           int o;
	       cout <<"\n\t\t";
           cout << "Enter(1 - 9) to increment : ";
           cin >> o;
           while (o <= 0)
           {
	       cout <<"\n\t\t";
               cout << "Enter(1 - 9) to increment (you entered an unacceptable number) : ";
               cin >> o;
           }
           Count.Inc10(o);
           if (Count.overf())
           {
	       cout <<"\n\t\t";
               cout << "You've gone beyond " << Count.getLim() << " which is the limit of the counter by " << (Count.getCount() + 10 * o) - Count.getLim()
                   << " Your Counter is being reset to 0." << endl;
	       Count.reset();
           }
       }

       else if (answer == 's')
       {
           int o;
	       cout <<"\n\t\t";
           cout << "Enter(1 - 9) to increment : ";
           cin >> o;
           while (o <= 0)
           {
               cout << "Enter(1 - 9) to increment(you entered an unacceptable number) : ";
               cin >> o;
           }
           Count.Inc100(o);
           if (Count.overf())
           {
               cout <<"\n\t\t";
               cout << "You've gone beyond " << Count.getLim() << " which is the limit of the counter by " << (Count.getCount() + 100 * o) - Count.getLim()
                   << " Your Counter is being reset to 0." << endl;
	       Count.reset();
           }
       }

       else if (answer == 'h')
       {
           int o;
	       cout <<"\n\t\t";
           cout << "Enter(1 - 9) to increment : ";
           cin >> o;
           while (o <= 0)
           {
	       cout <<"\n\t\t";
               cout << "Enter(1 - 9) to increment(you entered an unacceptable number) : ";
               cin >> o;
           }
           Count.Inc1000(o);
           if (Count.overf())
           {
               cout << "You've gone beyond " << Count.getLim() << " which is the limit of the counter by " << (Count.getCount()+ 1000 * o) - Count.getLim()
                   << " Your Counter is being reset to 0." << endl;
	       Count.reset();
           }
       }

       else if (answer == 'k')
       {
	       cout <<"\n\t\t";
           cout << "Enter a limit for the counter (1-9999): ";
           int limit;
           cin >> limit;
           Count.setLim(limit);
       }

       else if (answer == 'n')
       {
	       cout <<"\n\t\t";
           Count.reset();
       }

       else if (answer=='u')
       {
           int o;
           o = Count.getLim() - Count.getCount() + 1;
           Count.Inc1(o);
           if (Count.overf())
           {
               cout<<"\n\t\t";
               cout << "Overflow successfully completed "<<endl;
               Count.reset();
           }
       }
       else if (answer == 'e')
       {
           cout<<"\n\t\t--------------------------------------------------------------------";
           cout <<"\n\n\t\t\t\tThank You For Participating!"<<endl<<endl;
           exit(1);
       }
       p = Count.getCount()/100.00;
          cout << "\n\n\n\t\tCurrent value of counter is: " << Count.getCount()<< " " <<"The limit of the counter is: " << Count.getLim() << " $" << p <<endl;
       cout <<"\n\t\t--------------------------------------------------------------------";
       cout <<"\n\n\t\t";
       cout <<"Your Options Are: " << endl;
       cout <<"\n\t\t";
       cout << "a - for cents " << endl;
       cout <<"\n\t\t";
       cout << "v - for dimes " << endl;
       cout <<"\n\t\t";
       cout << "s - for dollars " << endl;
       cout <<"\n\t\t";
       cout << "h - for tens of dollars " << endl;
       cout <<"\n\t\t";
       cout << "u - for overflow " << endl;
       cout <<"\n\t\t";
       cout << "n - for reset " << endl;
       cout <<"\n\t\t";
       cout << "k - to set counter" << endl;
       cout <<"\n\t\t";
       cout << "e - to quit:" << endl;
       cout <<"\n\t\tYou chose: ";
       cin >> answer;
       cout << endl;
   }

}
bool answerIsCorrect(char answer)
{
   if (answer == 'a') return true;
   if (answer == 'v') return true;
   if (answer == 's') return true;
   if (answer == 'h') return true;
   if (answer == 'u') return true;
   if (answer == 'n') return true;
   if (answer == 'k') return true;
   if (answer == 'e') return true;


   cout << "answer = " << answer << endl;
   return false;
}


