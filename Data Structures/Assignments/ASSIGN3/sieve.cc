/*
 	<Anushka Verma>(<Z1911937>)
	Assignment 03
	09/30/2020

	I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

#include <iostream>
#include <iomanip>
#include <set>

using namespace std;
using std::set;

int NO_ITEMS = 16;
int ITEM_W = 5;

typedef set<int>::iterator iter;

void sieve(set<int>& s, int n) //function for the sieve of eratosthenes
{
	for(int i = 2; i*i <= n; i++) //load the set of integers with 2,3,....,n
	{
		s.insert(i);
	}
	for(int m = 2; m * m <= n; m++)
	{
		for(int k = m; k <= n; k++)
		{
			s.erase(m * k);
		}
	}
  
}

void print_primes(const set<int>& s) //function to print only prime numbers
{
	int nl = 0;
	for(iter it = s.begin(); it != s.end(); it++)
	{
		nl++;
		cout << setw(ITEM_W) << *it << " ";
		if(nl == NO_ITEMS)
		{
			cout << endl;
			nl = 0;
		}
	}
	cout << endl;

}

int
main()
{
	std::set<int> s;
	int n;

	cout << "Upper limit for the set of primes: ";
	cin >> n; //input the amount of numbers you want to print
	cout << endl;

	for(int i =2; i < n; i++)
	{
		s.insert(i);
	}

	sieve(s, s.size()); //using sieve of eratosthenes to remove any non-prime numbers
	print_primes(s); //prints out the left out prime numbers
	
	
	return 0;
}
