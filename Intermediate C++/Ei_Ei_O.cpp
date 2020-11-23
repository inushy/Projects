//Anushka Verma
//Portfolio 2- Lab3
//07.01.2020
//RandomFile(Ei-Ei-O)!
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Ei_Ei_O.h"
using namespace std;

void decimal(ofstream &file);
void whole(ofstream &file);
void character(ofstream &file);
void makeFile(char choice);
void Menu();

void makeFile(char choice)
{
    string filname;
    cout<< "\n\n\tPlease Enter The Name Of The File To";
    cout<< " Store Random";
    cout<< " Values(\"xxxx.txt\"): ";
    cout<<endl;
    cout<< "\n\n\t";
    cin >> filname;
    ofstream file;
    file.open(filname);
    while(file.is_open())
    {
        if(file.is_open())
        {
            cout << "\n\n\tFile Was Succesfully Opened!";
            cout<<endl;
            if(choice == '1' || choice == 'w' || choice == 'W')
            {
                whole(file);
            }
            else if (choice == '2'|| choice == 'd' || choice == 'D')
            {
                decimal(file);
            }
            else if (choice == '3'|| choice == 'c' || choice == 'C')
            {
                character(file);
            }
            cout << "\n\n\tData Is Succesfully Written!";
            cout<<endl;
            file.close();
        }
        else
        {
            cout <<"\n\n\tSorry The File Did Not Successfully Open";
            cout<<endl;
        }
    }
}

void whole(ofstream &file)
{
    int count;
    long min, max;
    cout<< "\n\n\tPlease Enter The Minimum Value";
    cout<< endl;
    cout<< "\n\n\t";
    cin >> min;
    cout<< "\n\n\tPlease Enter The Maximum Value";
    cout<< endl;
    cout<< "\n\n\t";
    cin >> max;
    cout<< "\n\n\tPlease Enter How Many Numbers To Generate";
    cout<< endl;
    cout<< "\n\n\t";
    cin >> count;
    if(min > max)
    {
        long mid;
        mid = max;
        max = min;
        min = mid;
    }
    
    for( int i = 0; i <= count; i++)
    {
        long value = rand_range(min, max);
        file << value << endl;
    }
    
}

void decimal(ofstream &file)
{
    double min, max;
    int count;
    cout<< "\n\n\tPlease Enter The Minimum Value";
    cout<< endl;
    cout<< "\n\n\t";
    cin >> min;
    cout<< "\n\n\tPlease Enter The Maximum Value";
    cout<< endl;
    cout<< "\n\n\t";
    cin >> max;
    cout<< "\n\n\tPlease Enter How Many Number To Generate";
    cout<< endl;
    cout<< "\n\n\t";
    cin >> count;
    if(min > max)
    {
        double mid;
        mid = max;
        max = min;
        min = mid;
    }
    for( int i = 0; i <= count; i++)
    {
        double value = rand_range(min, max);
        file << value << endl;
    }
}

void character(ofstream &file)
{
    char min, max;
    int count;
    cout<< "\n\n\tPlease Enter The Minimum Value";
    cout<< endl;
    cout<< "\n\n\t";
    cin >> min;
    cout<< "\n\n\tPlease Enter The Maximum Value";
    cout<< endl;
    cout<< "\n\n\t";
    cin >> max;
    cout<< "\n\n\tPlease Enter How Many Number To Generate";
    cout<< endl;
    cout<< "\n\n\t";
    cin >> count;
    if(min > max)
    {
        char mid;
        mid = max;
        max = min;
        min = mid;
    }
    
    for( int i = 0; i <= count; i++)
    {
        char value = rand_range(min, max) ;
        file << value << endl;
    }
}

int main()
{
    char choice;
    bool continueLoop = true;
    cout << "\n\tWelcome To The Random File Generator";
    cout<<endl;
    cout << "\n\t----------------------------------------------------";
    cout<<endl;
    do
    {
        Menu();
        cin >> choice;
        switch(choice)
        {
            case '1':
            case 'w':
            case 'W':
                    makeFile(choice);
                break;
            case '2':
            case 'd':
            case 'D':
                    makeFile(choice);
                break;
            case '3':
            case 'c':
            case 'C':
                    makeFile(choice);
                break;
            case '4':
            case 'q':
            case 'Q':
                continueLoop = false;
                break;
            default:
                cout << "\n\n\tWrong Input, Please Try Again!";
                cout<<endl;
                break;
        }
    }while(continueLoop);
    cout << "\n\t----------------------------------------------------";
    cout<<endl;
    cout << "\n\tThankyou For Using The Program!";
    cout<<endl;
    cout << "\n\tPlease Visit Us Again Soon"<<endl<<endl;
   return 0;
}
void Menu()
{
    cout << "\n\n\t1 - Create Random Whole Number Data File";
    cout<< endl;
    cout << "\n\n\t2 - Create Random Decimal Number Data File";
    cout<< endl;
    cout << "\n\n\t3 - Create Random Character Data File";
    cout<< endl;
    cout << "\n\n\t4 - Quit Program";
    cout<<endl;
    cout << "\n\n\tPlease Pick Your Desired Option: ";
}
