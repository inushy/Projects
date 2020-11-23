//Anushka Verma
//06/09/2020
//Portfolio 1 - Lab 1
#include <iostream>
#include <string>

using namespace std;

string ch;
string Month;
string InputMonth;
string MonthNumber;
//string monthName;
string MonthInThreeLetter;

int getMonthNumber(string monthName)
{
  
    int result = 0;
    if(monthName == "January")
    {
        result = 1;
    }
    else if(monthName == "February")
    {
        result = 2;
    }
    else if(monthName == "March")
    {
        result = 3;
    }
    else if(monthName == "April")
    {
        result = 4;
    }
    else if(monthName == "May")
    {
        result = 5;
    }
    else if(monthName == "June")
    {
        result = 6;
    }
    else if(monthName == "July")
    {
        result = 7;
    }
    else if(monthName == "August")
    {
        result = 8;
    }
    else if(monthName == "September")
    {
        result = 9;
    }
    else if(monthName == "October")
    {
        result = 10;
    }
    else if(monthName == "November")
    {
        result = 11;
    }
    else if(monthName == "December")
    {
        result = 12;
    }
    return result;
}

string getMonthName(int monthName)
{
  
    string result;
  
    if(monthName == 1)
    {
        result = "January";
    }
    else if(monthName == 2)
    {
        result = "Feburary";
    }
    else if(monthName == 3)
    {
        result = "March";
    }
    else if(monthName == 4)
    {
        result = "April";
    }
    else if(monthName == 5)
    {
        result = "May";
    }
    else if(monthName == 6)
    {
        result = "June";
    }
    else if(monthName == 7)
    {
        result = "July";
    }
    else if(monthName == 8)
    {
        result = "August";
    }
    else if(monthName == 9)
    {
        result = "September";
    }
    else if(monthName == 10)
    {
        result = "October";
    }
    else if(monthName == 11)
    {
        result = "November";
    }
    else if(monthName == 12)
    {
        result = "Decemeber";
    }
    return result;
}

void set_month(string monthAr)
{
    Month = monthAr;
}

string get_month()
{
    return Month;
}

void inp()
{
    string monthName;
    cout << "\n\t\t**********************************************************************"<<endl;
    cout << "\n\t\t\t\t\t\t\t\tThe Ides Of March!! " << endl;
    cout << "\n\t\t**********************************************************************"<<endl;
    cout << "\n\n\t\tEnter your choice from the following options ? \n";
    cout << "\n\n\t\t1 : Months in digit ( i.e 1-Januray, 3-March ) \n";
    cout << "\n\n\t\t2 : Full Month's name ( i.e Januray, March, June etc. ) \n";
    cout << "\n\n\t\t3 : Months in 3 letter ( i.e JAN, JUN,NOV etc. ) \n";
    cout << "\n\n\t\t";
    getline (cin, ch);
    if(ch == "1")
    {
        cout << "\n\n\t\tPlease Enter A Month:";
        cout << "\n\n\t\t";
        getline (cin, MonthNumber);
        set_month(MonthNumber);
    }
    else if(ch == "2")
    {
        cout << "\n\n\t\tPlease Enter A Month:";
        cout << "\n\n\t\t";
        getline (cin, monthName);
        set_month(monthName);
    }
    else if(ch == "3")
    {
        cout << "\n\n\t\tPlease Enter A Month: ";
        cout << "\n\n\t\t";
        getline (cin, MonthInThreeLetter);
        set_month(MonthInThreeLetter);
    }
    else
    {
        cout << "\n\n\t\tSorry you have entered wrong choice!"<<endl<<endl;
    }
}

void out()
{
    string monthName;
    if(ch == "1")
    {
        cout << "\n\n\t\tYou Entered The Month: " << MonthNumber << endl ;
    }
    else if(ch == "2")
    {
        cout << "\n\n\t\tYou Entered The Month: " << monthName << endl ;
    }
    else if(ch == "3")
    {
        cout << "\n\n\t\tYou Entered The Month: " << MonthInThreeLetter << endl ;
    }
}

void bef()
{
    string monthName;
    if(ch == "1")
    {
        cout << "\n\n\t\tPlease Enter The Number Of Months For Which You Need To Identify The Before Month's Name: "<< endl;
        cout << "\n\n\t\t";
        getline (cin,InputMonth);
        int acMonth = stoi(MonthNumber);
        int result = acMonth - stoi(InputMonth);
        int output;
        if(result <= 0 )
        {
            output = 12 - (-(result));
        }
        else
        {
            output = acMonth - result;
        }
        cout << "\n\n\t\tCalculated before month is: " << output << endl;
    
    }
    else if(ch == "2")
    {
        int result = 0;
        int output = 0;
        cout << "\n\n\t\tPlease Enter The Number Of Months For Which You Need To Identify The Before Month's Name (i.e January , Augest etc.): "<< endl;
        cout << "\n\n\t\t";
        getline (cin,InputMonth);
        cout << "\n\n\t\t";
        int actualresult = getMonthNumber(monthName);
        result = actualresult - stoi(InputMonth);
        if(result <= 0 )
        {
            output = 12 - -(result);
            cout << getMonthName(output) << endl;
        }
        else
        {
            output = actualresult - result;
            cout << getMonthName(output) << endl;
        }
        cout <<endl <<endl;
    }
    else if(ch == "3")
    {
    }
}

void aft()
{
    if(ch == "1")
    {
        cout << "\n\n\t\tPlease Enter The Number Of Months For Which You Need To Identify The Future Month's Value: "<< endl;
        cout << "\n\n\t\t";
        getline (cin,InputMonth);
        int acMonth = stoi(MonthNumber);
        int result = acMonth + stoi(InputMonth);
        int output;
        if(result > 12 )
        {
            output = result - 12 ;
        }
        else
        {
            output = acMonth + result;
        }
        cout << "\n\n\t\tCalculated future month is: " << output << endl<<endl;
    }
    else if(ch == "2")
    {
    }
    else if(ch == "3")
    {
    }
}


int main()
{
inp();
out();
bef();
aft();

return 0;
}
