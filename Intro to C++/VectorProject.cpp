//Anushka Verma
//Project 3
//Vector Project
//05/01/2020

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

class NumberData
{
	private:
		vector<int>list;
	public:
		NumberData();
		void setRList();
		void printRList();
		void maxRList();
		void minRList();
		void insList(int ele, long unsigned pos);
		void delList(long unsigned pos);
		bool seaList( int key, long unsigned int &position);
		void BubSort();
		void Unionl(NumberData list2, NumberData &Unionl);
		void Intersectionl(NumberData list2, NumberData &Intersectionl);
		void menu();

};
NumberData::NumberData():list()
{
}
void NumberData::setRList()
{
	int a;
	for(int i=0; i<10; i++)
	{
		a = 1+rand()%(20 -1 +1);
		list.push_back(a);
	}
}
void NumberData::printRList()
{
	for(unsigned int i=0; i<list.size();i++)
	{
		cout<<list[i];
		if(i<(list.size() -1))
		{
			cout<<", ";
		}
	}	
}
void NumberData::maxRList()
{
	int big = list[0];
	for(unsigned int i=0; i<list.size(); i++)
	{
		if(list[i] >big)
			big=list[i];
	}
	cout<<big;
}
void NumberData::minRList()
{
	int small = list[0];
	for(int i=0; i<10; i++)
	{
		if(list[i] <small)
			small=list[i];
	}
	cout<<small;
}
void NumberData::menu()
{
	cout<<"\n\n\t\t\t\t";
	cout<<"\n\n\t\t\t--------Pick Your Option------------------------------------------";
	cout<<"\n\n\t\t\t1.....Insert";
	cout<<"\n\n\t\t\t2.....Search";
	cout<<"\n\n\t\t\t3.....Delete";
	cout<<"\n\n\t\t\t4.....Sort";
	cout<<"\n\n\t\t\t5.....Union";
	cout<<"\n\n\t\t\t6.....Intersection";
	cout<<"\n\n\t\t\t7.....Your Lists";
	cout<<"\n\n\t\t\t8.....Exit!";
	cout<<"\n\n\t\t\t--------Thank You For Participating-------------------------------";

	cout<<endl<<endl;
}
void NumberData:: insList(int ele, long unsigned pos)
{
	while(pos >= list.size())
	{  
		cout<<"\n\n\t\t\t\tYour Option Is Invalid, Please Try Again!";
		
	cin>> pos;
	}
	long unsigned last = list.size() -1;
	list.push_back(list[last]);
	for(long unsigned i = last; i > pos; i--)
		list[i]=list[i-1];
	list[pos]=ele;

}
void NumberData:: delList(long unsigned pos)
{
	while(pos >= list.size())
	{  
		cout<<"\n\n\t\t\t\tYour Option Is Invalid, Please Try Again!";
	cin>> pos;
	}
	for (long unsigned int i = pos; i <list.size(); i++)
	       list[i] = list[i+1];
	list.pop_back();	
}
bool NumberData:: seaList(int key, long unsigned int &position)
{
	int temp = 0;
	for(long unsigned int i=0; i < list.size(); i++)
	{
		if(list[i] == key)
		{
			temp = 1;
			position = i+1;
			i = list.size();
		}
	}
	if(temp == 1)
		return true;
	else
		return false;

}
void NumberData:: BubSort()
{
	int temp;
	for(unsigned int i = 1; i < list.size(); i++)
	{
		for(unsigned int j = 0; j < list.size() - i; j++)
		{      if(list[j] > list[j+1])
		       {       temp = list[j];
			       list[j] = list[j+1];
			       list [j+1] = temp;
		       }
		}
	}
}
void NumberData:: Unionl(NumberData list2, NumberData &Unionl)
{

	for (unsigned int i=1; i < (list.size() + list2.list.size()); i++)
	{
		for (unsigned int j =0; j < list.size() -i; j++)
		{
			if(list[j] == list2.list[j])
			{
				Unionl.list.push_back(list[j]);
				list2.list[j]=list2.list[j+1];
			}
		}
	}
	Unionl.printRList();
}
void NumberData:: Intersectionl(NumberData list2, NumberData &Intersectionl)
{
         for (unsigned int i=1; i < (list.size() + list2.list.size()); i++)
        { 
                for (unsigned int j =0; j < list.size() -i; j++)
                {
                        if(list[j] == list2.list[j])
                        {
                                Intersectionl.list.push_back(list[j]);
                                list2.list[j]=list2.list[j+1];
                        }
                }
        }
        Intersectionl.printRList();
}
int main()
{
	NumberData b1, b2, b3;
	system("clear");
	srand(static_cast<unsigned>(time(0)));

	cout<<"\n\t\t\t******************************************************************\t\t";
	cout<<"\n\t\t\t\t\t\tProject 3\n\t\t";
	cout<<"\t------------------------------------------------------------------\n\t\t";
	cout<<"\n\t\t\tYour First List Is:\n\t\t\t";
	b1.setRList();
	cout<<"\n\n\t\t\t\t";
	b1.printRList();
	cout<<endl;
	cout<<"\n\n\t\t\tYour Max Value Is: ";
	b1.maxRList();
	cout<<"\n\n\t\t\tYour Min Value Is: ";
        b1.minRList();
	cout<<endl<<endl;

	cout<<"\t\t\t------------------------------------------------------------------\n\t\t";
        cout<<"\n\t\t\tYour Second List Is:\n\t\t\t";
        b2.setRList();
        cout<<"\n\n\t\t\t\t";
        b2.printRList();
	cout<<endl;
        cout<<"\n\n\t\t\tYour Max Value Is: ";
        b2.maxRList();
        cout<<"\n\n\t\t\tYour Min Value Is: ";
        b2.minRList();
	cout<<endl;
        cout<<"\n\t\t\t******************************************************************\n\n\t\t";
	cout<<endl<<endl;
	
	b1.menu();
	int K;
	cout<<"\n\n\t\t\t";
	cin>>K;
	do
	{
		switch(K)
		{
			case 1:
				int n;
				cout<<"\n\n\t\t\tTo Insert An ELement In Either List 1 or 2, Please Follow The Instructions Below";
				cout<<"\n\n\t\t\tPlease Enter 1 To View Your List 1 Or Enter 2 To View Your List 2: "<<endl;
			       	cout<<"\n\n\t\t\t";
				cin>> n;
				if(n == 1)
				{
					int num, pos;
					cout<<"\n\n\t\t\t";
					b1.printRList();
					cout<<"\n\n\t\t\t";
					cout<<"\n\t\t\tPlease Enter A Number And Position You Would Like To Insert In Your List: ";
					cout<<"\n\n\t\t\t";
					cin>>num;
					cout<<"\n\n\t\t\t";
					cin>>pos;
					
					b1.insList(num,pos);
					cout<<"\n\n\t\t\tYour New List Is: ";
        				
					cout<<endl;
					cout<<"\n\n\t\t\t";
        				b1.printRList();
					cout<<endl<<endl;
				}
				else
				{
					int num, pos;
					cout<<"\n\n\t\t\t";
					b2. printRList();
					cout<<"\n\n\t\t\t";
					cout<<"\n\t\t\t\tPlease Enter A Number And Position You Would Like To Insert In Your List: ";
                                        cout<<"\n\n\t\t\t";
					cin>>num;
					cout<<"\n\n\t\t\t";
					cin>>pos;
					
					b2.insList(num,pos);
					cout<<"\n\n\t\t\tYour New List Is: ";
                                        
					cout<<endl;
					cout<<"\n\n\t\t\t";
                                        b2.printRList();
					cout<<endl<<endl;
				}
				b1.menu();
				cout<<"\n\n\t\t\t";
				cin>>K;
				cout<<endl;
				break;
			case 2:
				int u, item;
				long unsigned int position;
				cout<<"\n\n\t\t\tTo Search An ELement In Either List 1 or 2, Please Follow The Instructions Below";
                                cout<<"\n\n\t\t\tPlease Enter 1 To View Your List 1 Or Enter 2 To View Your List 2:  "<<endl;
                                cout<<"\n\n\t\t\t";
				cin>> u;
                                if(u == 1)
				   {
					cout<<"\n\t\t\tPlease Enter A Number You Are Searching For From Your List: ";
					cout<<"\n\n\t\t\t";
					cin>>item;
					if(b1.seaList(item, position))
					{
						cout<<"\n\n\t\t\t"<<item<<" Is In The List.\n\n";
                				cout<<"\n\n\t\t\t"<<item<<" Is The ";
                				cout<<position<<" Element In The List.";
                				cout<<endl<<endl;
        				}		
        				else
                				cout<<"\n\n\t\t\t"<<item<<" Is Not In The List.\n\n";
				   }
				else
				   {
					cout<<"\n\t\t\tPlease Enter A Number You Are Searching For From Your List: ";
                                        cout<<"\n\n\t\t\t";
					cin>>item;
                                        if(b2.seaList(item, position))
                                        {
                                                cout<<"\n\n\t\t\t"<<item<<" Is In The List.\n\n";
                                                cout<<"\n\n\t\t\t"<<item<<" Is The ";
                                                cout<<position<<" Element In The List.";
                                                cout<<endl<<endl;
                                        }
                                        else
                                                cout<<"\n\n\t\t\t"<<item<<" Is Not In The List.\n\n";
				   }
				b1.menu();
				cout<<"\n\n\t\t\t";
				cin>>K;
				cout<<endl;
				break;
			case 3:
				int h, pos;
				cout<<"\n\n\t\t\tTo Delete An ELement In Either List 1 or 2, Please Follow The Instructions Below";
                                cout<<"\n\n\t\t\tPlease Enter 1 To View Your List 1 Or Enter 2 To View Your List 2: "<<endl;
                                cout<<"\n\n\t\t\t";
				cin>> h;
                                if(h == 1)
				   {
					cout<<"\n\n\t\t\tPlease Enter A Number You Would Like To Delete From Your List: ";
        				cout<<"\n\n\t\t\t";
					cin>>pos;
        				b1.delList(pos);
        				cout<<"\n\n\t\t\tYour New List Is: ";
        				cout<<endl;
					cout<<"\n\n\t\t\t";
        				b1.printRList();
        				cout<<endl<<endl;
				   }
				else
				{
					cout<<"\n\n\t\t\tPlease Enter A Number You Would Like To Delete From Your List: ";
                                        cout<<"\n\n\t\t\t";
					cin>>pos;
                                        b2.delList(pos);
                                        cout<<"\n\n\t\t\tYour New List Is: ";
                                        cout<<endl;
					cout<<"\n\n\t\t\t";
                                        b2.printRList();
                                        cout<<endl<<endl;
				}
				b1.menu();
				cout<<"\n\n\t\t\t";
                                cin>>K;
                                cout<<endl;
                                break;

			case 4:
				int s;
				cout<<"\n\n\t\t\tTo Sort An ELement In Either List 1 or 2, Please Follow The Instructions Below";
                                cout<<"\n\n\t\t\tPlease Enter 1 To View Your List 1 Or Enter 2 To View Your List 2: "<<endl;
                                cout<<"\n\n\t\t\t";
				cin>> s;
                                if(s == 1)
				{
					cout<<"\n\t\t\tYour List 1 Has Been Sorted. The New List Is:\n\t\t\t";
					b1.BubSort();
					cout<<"\n\n\t\t\t";
					b1.printRList();
					cout<<endl;
				}
				else
				{
					cout<<"\n\t\t\tYour List 2 Has Been Sorted. The New List Is:\n\t\t\t";
                                        b2.BubSort();
					cout<<"\n\n\t\t\t";
                                        b2.printRList();
                                        cout<<endl;
				}
				b1.menu();
				cout<<"\n\n\t\t\t";
				cin>>K;
				cout<<endl;
				break;
			case 5:
				cout<<"\n\n\t\t\tUnion Of The Two List Is:\n\t\t\t";
				b1.BubSort();
				b2.BubSort();
				b1.Unionl(b2, b3);
				b3.printRList();
				
				b1.menu();
                                cout<<"\n\n\t\t\t";
                                cin>>K;
                                cout<<endl;
                                break;
			case 6:
				cout<<"\n\t\t\tIntersection Of The Two List Is:\n\t\t\t";
				b1.BubSort();
                                b2.BubSort();
                                b1.Intersectionl(b2, b3);
                                b3.printRList();

                                b1.menu();
                                cout<<"\n\n\t\t\t";
                                cin>>K;
                                cout<<endl;
                                break;

			case 7:
				cout<<"\n\n\t\t";
				cout<<"\t----------------------------------------------------\n\t\t";
        			cout<<"\n\t\t\tYour First List Is:\n\t\t\t";
				b1.printRList();
				cout<<"\n\n\t\t";
                                cout<<"\t----------------------------------------------------\n\t\t";
                                cout<<"\n\t\t\tYour Second List Is:\n\t\t\t";
                                b2.printRList();
				cout<<"\n\n\t\t";

				b1.menu();
				cout<<"\n\n\t\t\t";
                                cin>>K;
                                cout<<endl;
                                break;
			case 8:
				break;
			default:
				cout<<"\n\n\t\t\tInvalid Option, Please Try Again!";
				b1.menu();
				cout<<"\n\n\t\t\t";
				cin>>K;
                                cout<<endl;
                                break;
		}
	} while (K!=8);
	cout<<endl<<endl;
	return 0;
}






