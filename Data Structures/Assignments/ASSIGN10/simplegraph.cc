/*
	<Anushka Verma> (<Z1911937>)
	Assignment 10
	11/30/2020
	
	I certify that this is my own work and where appropriate an extension of the 
	starter code provided for the assignment.
*/

#include "simplegraph.h"

#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int n;
vector <bool> visit;
vector <pair <int, int> > edgelist; //Helps The Vector Pair To Hold The Visited Vertices
list <int>::iterator adj_it;
list <int> fill_list;


Graph::Graph(const char* filename):size(n) //Constructor for the Graph class
{
	ifstream in(filename); //Reads data from the file
	if (!in)
	{
		cout << " Sorry, Failed To Open File! " << endl;
		exit(EXIT_FAILURE);
	}
	
	string fill; //Creates A Temporary Fill-In 
	in >> size; //Helps Assign Vertices
	getline (in, fill); //Gets Vertices from the file
 
	for (int i = 0; i < size; i++)
	{
		char label;
		in >> label;
		labels.push_back(label); //Helps Input Labels Within The Array
	}
	char li;
	int fill_int;
	for (int k = 0; k < size; k++)
	{
		in >> li; //Reads The First Char
		for (int j =0; j <size; j++)
		{
			in >> fill_int; //Reads Numbers
			fill_list.push_back(fill_int);
		}
		adj_list.push_back(fill_list); //Pushes My Temporary List To The Actual List
		fill_list.erase(fill_list.begin(), fill_list.end()); //Helps Make Sure The List Is Empty So That We Can Input Data From The File
	}
	
	in.close();
}
Graph::~Graph() //deconstructor
{
	labels.clear();
	adj_list.clear();
}

int Graph::Getsize() const
{
	return size;
}

void Graph::Depthfirst(int v) //This Private Function Is Used To Traverse A Graph In The
{
	if (!visit[v])
	{
		fill_list.push_back(v);
	}
	visit[v] = true;

	list<int>::const_iterator it;
	int i = 0;
	for (it = adj_list[v].begin(); it != adj_list[v].end(); i++, it++)
	{
		if ( !visit[i] && *it == 1)
		{
			edgelist.push_back(make_pair(v, i));
			Depthfirst(i);
		}
	}
}

void Graph::Traverse() //This Public Function Is Used To Traverse A Graph And Invokes The Above Depthfirst Method
{
	visit = *new vector<bool>(size, false); //Creates A 2D Array
	int i;
	for (i = 0; i < size; i++)
	{
		if (!visit[i])
		{
			Depthfirst(i);
		}
	}

	cout << "------- traverse of graph ------" << endl;

	list<int>::const_iterator it;
	for (it = fill_list.begin(); it != fill_list.end(); it++)
	{
		cout << labels[*it] << " ";
	}
	cout << endl;

	for(unsigned i = 0; i < edgelist.size(); i++)
	{
		cout << "(" << labels[edgelist[i].first] << ", ";
		cout << labels[edgelist[i].second] << ") ";
	}
	cout << endl;
	cout << "--------- end of traverse -------" << endl << endl;
}

void Graph::Print() const //This Function Prints The Adjacency List For The Graph
{
	cout << endl;
	cout << "Number of vertices in the graph: " << size << endl << endl;
	cout << "-------- graph -------";
	for (size_t i = 0; i < adj_list.size(); i++) 
	{
		cout << "\n" << labels[i] << ":";
		for (size_t j = 0; j < adj_list[i].size(); j++) 
		{
			auto p = adj_list[i].begin();
			advance(p, j);
			if ( * p == 1) 
			{
				cout << " " << labels[j] << ",";
			}
		}
	}
	cout << endl;
	cout << "------- end of graph ------\n\n";
}

int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "args: input-file-name\n";
    return 1;
  }

  Graph g(argv[1]);

  g.Print();

  g.Traverse();

  return 0;
}
