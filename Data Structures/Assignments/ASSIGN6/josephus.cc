/*
	<Anushka Verma> (<Z1911937>)
	Assignment 06
	10/16/2020
	
	I certify that this is my own work and where appropriate an extension of the 
	starter code provided for the assignment.
*/

#include "josephus.h"

using namespace std;

void init_vals(list<string> &L, args &in) //It reads the input values N, M and K of the struct args
{
	L.resize(in.N);

	generate(L.begin(), L.end(), SEQ(in.N));
}
void print_list(const list<string> &L, const unsigned &cnt) //It prints out the contents of the list L
{
	cout << endl;

	int count = 0;

	if (cnt < 2)
	{
		cout << "Initial group of people" << endl;
		cout << "-----------------------" << endl;
	}
	else if (cnt < 14)
	{
		cout << "After eliminating " << cnt << "th person" << endl;
		cout << "----------------------------" << endl;
	}
	else
	{
		cout << "After eliminating " << cnt << "th person" << endl;
		cout << "-----------------------------" << endl;
	}

	for(auto const& i:L)
	{
		if (count % NO_ITEMS == 0 && count != 0)
		{
			cout << endl;
		}
		cout << i << " ";
		count++;
	}
	cout << endl;
}
int main()
{
	list<string>lis;  //initializing myList

	args jostruct;  //created a struct to hold the numbers N, M, K

	unsigned ct = 1;  //counts the number of passes

	cout << "Number of people? 41";
	jostruct.N = 41;
	cout << endl;
	cout << "Index for elimination? 3";
	jostruct.M = 3;
	cout << endl;
	cout << "Index for printing? 7";
	jostruct.K = 7;
	cout << endl;

	init_vals(lis, jostruct); //calling my init_vals function

	print_list(lis, ct); //calling my print_list function

	jostruct.M -= 1; //eliminating by M

	auto iIterator = jostruct.M % lis.size(); //iterator created to start the elimination process

	while(lis.size() > 1)
	{
		auto lIterator = lis.begin(); //created a new list iterator to access my list

		advance(lIterator, iIterator); //declared the advance function to locate the position of the M person in the list

		lis.erase(lIterator); //Gets rid of element in the list

		//helps with elimination process
		iIterator += jostruct.M;
		iIterator %= lis.size();

		if((ct %  jostruct.K == 0 && ct != 0) || lis.size() == 1) //displays the list
		{
			print_list(lis, ct);
		}

		ct++;
	}

	return 0;
}
