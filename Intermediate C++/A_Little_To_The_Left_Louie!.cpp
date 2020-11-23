//Anushka Verma
//Portfolio 2- Lab2
//06.29.2020
//A Little To The Left Louie!
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void Menu();
void output_Table(int Max, char op);
void output_file(int Max, char op);
void createOutput(int Max, char op, string printMethod);
int AssignedValue(int i, int j, char op);
int MaxNum(int size, char op);
int Size(string choice);

int Size(string choice)
{
    int size = 0;
    while (size <= 0 || size >=21 )
    {
        cout << "\n\n\tWhat Should The Size Of The "<< choice << " Table Be? ";
        cin >> size;
        if(size <= 0)
        {
            cout <<"\n\n\tI'm Sorry, But, "<< size << " Is Just Dumb..."<<endl;
        }
        else if (size >= 21)
        {
            cout <<"\n\n\tI'm Sorry, But " << size;
            cout <<" Is Too Large Of A "<< choice;
            cout <<" Table To Print On The Screen"<<endl;
        }
        else
        {
            cout << "\n\n\tThank You! ...Calculating..."<<endl;
        }
    }
    return size;
}

void createOutput(int Max, char op, string printMethod)
{
    cout << "\n\n\tWould You Like To Print The Table On Screen";
    cout << " Or On A File? " <<endl;
    cout << "\n\n\t";
    cin >> printMethod;
    cout << endl;
    if (printMethod == "screen")
    {
        output_Table(Max, op);
    }
    else
    {
        output_file(Max, op);
    }
}

void output_Table(int Max, char op )
{
        int max = MaxNum(Max, op);
        cout << setw(max) << "\t   " <<op << "|";
        for(int i = 1; i<= Max; i++)
        {
            cout << setw(max) << i;
        }
        cout << endl;
        cout << "\t  ";
        for(int i = 0; i < max; i++)
        {
            cout << "-";
        }
        cout << "+";
        for(int i = 0; i < Max* max; i++)
        {
            cout << "-";
        }
        cout << endl;
        for(int i = 1; i <= Max; i++)
        {
            cout << "\t  ";
            cout << setw(max) << i << "|";
            for(int j = 1; j <= Max; j++)
            {
            cout << setw(max) << AssignedValue(i, j, op);
            }
        cout << endl;
        }
    cout << endl;
}

void output_file(int Max, char op)
{
    string filename;
    ofstream file;
    cout << "\n\n\tPlease Enter A File Name And Please Add";
    cout <<" '.txt' Next To It";
    cout << "\n\n\t";
    cin>>filename;
    file.open(filename);
    if(file.is_open())
    {
        int max = MaxNum(Max, op);
        file << setw(max) <<op << "|";
        for(int i = 1; i<= Max; i++)
        {
            file << setw(max) << i;
        }
        file << endl;
        cout << "\t   ";
        for(int i = 0; i < max; i++)
        {
            file << "-";
        }
        file << "+";
        for(int i = 0; i < Max* max; i++)
        {
            file << "-";
        }
        file << endl;
        for(int i = 1; i <= Max; i++)
        {
            file << setw(max) << i << "|";
            for(int j = 1; j <= Max; j++)
            {
                file << setw(max) << AssignedValue(i, j, op);
            }
            file << endl;
         }
            file << endl;
            file.close();
            cout <<"\n\n\tFinished writing to the file "<< filename <<endl;
        }
        else
        {
            cout << "\n\n\tFile could not be opened"<<endl;
        }
}

int AssignedValue(int i, int j, char op)
{
    int value;
    if(op == '+')
    {
        value = i + j;
    }
    else if (op == '-')
    {
        value = i - j;
    }
    else if (op == '*')
    {
        value = i*j;
    }
    else if (op == '/')
    {
        value = j/i;
    }
    else
    {
        value = i % j;
    }
    return value;
}

int MaxNum(int size, char op)
{
    int max = 0;
    for(int i = 1; i<= size; i++)
    {
        for(int j = 1; j<= size; j++)
        {
            int value = AssignedValue(i, j, op);
            int total = 0;
            if(value <= 0)
            {
                ++total;
            }
            while(value != 0)
            {
                value = value/10;
                total++;
            }
                int n = total;
                if(n > max)
                {
                    max = n;
                }
         }
    }
    return max + 1;
}
int main()
{
    char choice;
    char sign = ' ';
    string table, print;
    int size = 0;
    bool continueLoop = true;
    cout << "\n\n\t\tWelcome To The Math Table Program!"<<endl;
    cout << "\n\t------------------------------------------------"<<endl;
    do
    {
        Menu();
        cin >> choice;
        switch(choice)
        {
            case '1':
            case 'a':
            case 'A':
                        table = "Addition";
                        sign = '+';
                        size = Size(table);
                        createOutput(size, sign, print);
                    break;
            case '2':
            case 'm':
            case 'M':
                        table = "Multiplication";
                        sign = '*';
                        size = Size(table);
                        createOutput(size, sign, print);
                    break;
            case '3':
            case 's':
            case 'S':
                        table = "Subtraction";
                        sign = '-';
                        size = Size(table);
                        createOutput(size, sign, print);
                    break;
            case '4':
            case 'd':
            case 'D':
                        table = "Division";
                        sign = '/';
                        size = Size(table);
                        createOutput(size, sign, print);
                    break;
            case '5':
            case 'r':
            case 'R':
                        table = "Remainder";
                        sign = '%';
                        size = Size(table);
                        createOutput(size, sign, print);
                    break;
            case '6':
            case 'q':
            case 'Q':
                        continueLoop = false;
                    break;
            default:
                        cout << "\n\n\t\tWrong Input, Please Try Again!"<<endl;
                    break;
            }
        }while(continueLoop);
        cout << "\n\n\t\tThank You For Using This Program."<<endl;
        cout << "\n\n\t\tHope To See You Again Soon!"<<endl;
        cout << "\n\t------------------------------------------------"<<endl;
        return 0;
}
void Menu()
{
    cout << "\n\n\tYour Menu: " << endl;
    cout << "\n\n\t1--Addition table" << endl;
    cout << "\n\n\t2--Multiplication table" << endl;
    cout << "\n\n\t3--Subtraction table" << endl;
    cout << "\n\n\t4--Division table" << endl;
    cout << "\n\n\t5--Remainder table" << endl;
    cout << "\n\n\t6--Quit" << endl;
    cout << "\n\n\tYour Choice:  ";
}
