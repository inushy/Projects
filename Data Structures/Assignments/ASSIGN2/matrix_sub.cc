/*
	<Anushka Verma> (<Z1911937>)
	Assignment 02
	09/21/2020
	
	I certify that this is my own work and where appropriate an extension of the 
	starter code provided for the assignment.
*/


// TA COMMENTS:
// -good structure and efficient code
// -consider adding more inline doc
// -nice job, keep up the good work.
// 
// 10/10 



//Creating A Source File!
//Add Your Header File
#include "matrix.h"

using namespace std;

//Add The Functions (open_files, read_data, print_data, and gen_data)

void open_files(ifstream &is1, ifstream &is2) //Opens two data files for reading and creates the input streams is1 and is2.
{
	is1.open(FILE1);
	if(!is1)
	{
		cerr << "Sorry The File Is Invalid!" <<endl;
		exit(1);
	}

	is2.open(FILE2);
	if(!is2)
	{
		cerr << "Sorry The File Is Invalid!" <<endl;
		exit(2);
	}
}

void read_data(ifstream &is, vector<vector<int>> &m) //Reads the values from the input stream (is) and stores them in matrix m (defined as a 2D vector of integers).
{
	if(is.is_open())
	{
		while(!is.eof())
		{
			for(unsigned int i=0; i < m.size(); i++)
			{
				for(unsigned int j=0; j < m[i].size(); j++)
				{
					is >> m[i][j];
				}
			}
		}
	}
}

void print_data(const vector<vector<int>> &m) //Prints the contents by allocating ITEM_W spaces for each integer (defined in header file)
{
	cout << m.size() << " x " << m[0].size();
	cout << "\n----------------------------------------------------------------------"<<endl;
	for(unsigned int i=0; i<m.size(); i++)
	{
		for(unsigned int j=0; j<m[i].size(); j++)
		{
			cout <<setw(ITEM_W)<<m[i][j];
		}
		cout<<endl;
	}
}

void gen_data(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C) //Multiplies matrices A and B and stores the output in matrix C.
{
	for(unsigned int i=0; i<C.size(); i++)
	{
		for(unsigned int j=0; j<A.size(); j++)
		{
			for(unsigned int k=0; k<B.size(); k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}
