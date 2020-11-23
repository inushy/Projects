/* Anushka Verma
   Z1911937
   CSCI 340 Section-1

   I certify that this is my own work and where appropriate an extension 
   of the starter code provided for the assignment.
*/


// TA FEEDBACK:
// -output formating doesn't match match expected output
//    -just do what's required for the assignment
// -otherwise nice, consistent formatting and easy to read code
// -Keep up the Good work.


#include "rgi.h"

// Add needed constants

//The very first thing we need in our program is the, size or amount of items we have altogether
int VEC_SIZE = 200;

//The next thing we need to include in our program are the RNG'S
int LOW = 1;
int HIGH = 10000;
int SEED = 1;
//We are using (int) since we are dealing with integers in our program

//Constants used in our program for printing the output
int NO_ITEMS = 12; //will deal with the amount of colums
int ITEM_W = 5;  //will deal with the Set width or the spacing in the program

// Add code for genRndNums

void genRndNums(vector<int> &v) //The function used to generate random numbers
{
	srand(SEED); //given seed
	for(int i = 0; i < VEC_SIZE; i++) //A for loop created to randomly generate numbers from the VEC_SIZE
	{
		int randnumgen= rand() % HIGH + LOW; //The algorithm which would help randnumgen to work from the range of high and low
		v.push_back(randnumgen); //We use push_back when using vectors. This code initializes the vector used.
	}
}

// Add code for printVec

void printVec(const vector<int> &v)  //The function used to print the vector
{
	for(int i = 0; i <= VEC_SIZE; i+=12) //The for loop is created to print the items in the VEC_LIST
	{
		for(int j=i; i<VEC_SIZE && j <12+i; j++)
		{
			cout << setw(ITEM_W) << v[j]; //Helps space out between the items
		}
		cout << endl << endl;
		
	}
}

int main() 
{
// Declare vector v

	vector <int> v;

// Generate random numbers to fill vector v
	
	genRndNums(v);	//calling the function to generate random numbers

// Using STL sort sort v
	
	sort(v.begin(), v.end()); //sorts in ascending order

// Print vector of sorted random numbers

	printVec(v); //calling the function to print the random numbers 

    return 1;
}


