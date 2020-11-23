//Anushka Verma
//Portfolio 2- Lab1
//06.29.2020
//Round 'em Up!
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double Aver( vector<int> &numbers)
{
    double sum = 0.0;
    for(int i = 0; static_cast<unsigned>(i) < numbers.size() - 1; i++)
    {
        sum = sum + numbers[i];
    }
    double avg = sum/static_cast<double>(numbers.size()-1);
  return avg;
}
    
double deviat(vector<int> &numbers, double avg)
{
    double devi = 0;
    double inver = 1.0/ static_cast<double>(numbers.size() - 2);
    for(int i = 0; static_cast<unsigned>(i) < numbers.size() - 1; i++)
    {
        devi = devi + pow((numbers[i] - avg), 2);
    }
  return sqrt(inver * devi);
}
void small_big( vector<int> &numbers)
{
    int smallest = numbers[0];
    int biggest = numbers[0];
    for(int i = 0; static_cast<unsigned>(i) < numbers.size(); i++)
    {
        if(numbers[i] < smallest)
        {
            smallest = numbers[i];
        }
        if(numbers[i] > biggest)
        {
            biggest = numbers[i];
        }
    }
        cout << setw(10);
        cout << "\n\n\tMinimum: " << biggest << endl;
        cout << setw(10);
        cout << "\n\n\tMaximum: " << smallest << endl;
}
int main()
{
    vector<int> numbers;
    ifstream inputFile;
    string filname;
    cout <<"\n\n\tWelcome To The Number Statistics Program!";
    cout <<"\n\n\t-------------------------------------------------------------"<<endl;
    cout <<"\n\n\tPlease Enter Your Data File Name: ";
    getline(cin, filname);
    inputFile.open(filname);
    while (!inputFile)
    {
        inputFile.close();
        inputFile.clear();
        cout <<"\n\n\tI'm Sorry, I Could Not Open The Requested File Name, '";
        cout << filname <<"'";
        cout <<"\n\n\tPlease Try Again: ";
        getline(cin, filname);
        inputFile.open(filname);
    }
    if (inputFile.good())
    {
        cout << "\n\n\tFile '"<< filname << "'Succesfully Opened!"<<endl;
        int currentnum = 0;
        cout << "\n\n\tReading Data From The File '";
        cout << filname <<"'...."<<endl;
        cout << "\n\n\t....Calculating...."<<endl;
        while (!inputFile.eof())
        {
            inputFile >> currentnum >>ws;
            numbers.push_back(currentnum);
        }
        inputFile.close();
        cout << "\n\n\tData Processed!"<<endl;
        cout << endl;
        cout << "\n\n\tFollowing Are The Statistics For The Data Provided:"<<endl;
        cout << setw(10);
        cout << "\n\n\tCount: " << numbers.size()-1<<endl;
        small_big(numbers);
        double avg = Aver(numbers);
        double dev = deviat(numbers, Aver(numbers));
        cout << setw(10);
        cout << "\n\n\tAverage: " << avg << endl;
        cout << setw(10);
        cout << "\n\n\tDeviation: " << dev << endl;
    }
    else
    {
        cout << "\n\n\tSorry An Error Occured. File Corrupted!";
    }
    cout <<"\n\n\t-------------------------------------------------------------"<<endl;
    cout <<"\n\n\tThank You Using The Program!" << endl;
    cout <<"\n\n\tHave A Rock n' Roll Day!" << endl;
    return 0;
}
