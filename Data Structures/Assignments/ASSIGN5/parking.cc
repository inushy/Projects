/*
	<Anushka Verma> (<Z1911937>)
	Assignment 05
	10/12/2020
	
	I certify that this is my own work and where appropriate an extension of the 
	starter code provided for the assignment.
*/

#include <iostream>
#include <string>
#include <deque>
#include <stack>


using namespace std;
#define MAX_SIZE 10
typedef struct CAR
{
    int id;         // id starts at 1
    string lp;      // license plate of car
    int no_mv;      // number times the car has been moved
    
    CAR(int id, string lp) 
    {                                // Car object defined
        this->id = id;
        this->lp = lp;
        this->no_mv = 0;
    }
}CAR; 

//Prototype functions
void get_input_vals(const string& line, char& act, string& lp); //Extracts individual components from the input line line
void arrival(const CAR& car, deque<CAR>& D); //Prints a message stating that a car is arrived.
void departure(const string& license, deque<CAR>& D, stack<CAR>& S); //Prints a message stating that the car with the license plate number lp is departed.

void get_input_vals(const string &line, char &act, string &lp) //Extracts individual components from the input line line
{
	act = line[0];
	lp.append(line.substr(2, line.length() - 3));
	
}

void arrival(const CAR &car, deque<CAR> &D) //Prints a message stating that a car is arrived
{

	cout << "Car " << car.id << " with license plate \"" << car.lp << "\" has arrived." << endl;
	if(D.size() == MAX_SIZE)
	{

		cout << "    But the garage has full!" << endl;
	}
	else
	{
		D.push_back(car);
	}
	cout << endl;
}

void departure(const string &lp, deque<CAR> &D, stack<CAR> &S) //Prints a message stating that the car with the license plate number lp is departed
{
	bool carExists = false;
	while(!D.empty()) 
	{
		CAR car = D.front();
		D.pop_front();
		if(car.lp == lp)
		{
			//Let the user know that the car is departing
			cout << "Car " << car.id << " with license plate \"" << car.lp << "\" has departed," << endl;
			if(car.no_mv > 1)
			{
				//If the car's no_mv is greater than 1, we need to use plural number of time
				cout << "    car was moved " << car.no_mv << " times in the garage." << endl;
			}
			else
			{
				cout << "    car was moved " << car.no_mv << " time in the garage." << endl;
			}
			//If the number of moves is less than or equal to 1, we need to use singular number of times
			carExists = true;
			cout << endl;
			break;
		}
		else
		{
			S.push(car);
		}
	}
	if(!carExists)
	{
		cout<< "No car with license plate " << "\"" <<  lp << "\"" << " is in the garage.\n";
		exit(1);
	}
}

int main()
{
	deque<CAR> D;
	stack<CAR> S;
	
	string line;
	int id = 1;
	while(cin) 
	{
		getline(cin, line);
		char act;
		string lp;
		get_input_vals(line, act, lp);
		
		if(act == 'A')
		{
			CAR car(id++, lp);
			car.no_mv++;
			arrival(car, D);
		}
		else if(act == 'D')
		{
			departure(lp, D, S);
			while(!S.empty())
			{
				CAR car = S.top();
				car.no_mv++;
				D.push_front(car);
				S.pop();
			}
		}
		else
		{
			cout << "\'" << act << "\': invalid action!\n";
			cout << endl;
		}
	}
	return 0;
}
