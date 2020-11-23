//Anushka Verma
//Employee Pay
//Vector Assignment
//04/15/2020

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;


class EmployeeData
{
	private:
		vector<string>employName;
		vector<int>hours;
		vector<double>employpayRate,employwages;
	public:
		EmployeeData();
		void set_Name();
		void set_Ho();
		void set_Pa();
		void set_Wa();
		void Tab();
};
EmployeeData::EmployeeData():employName(), hours(), employpayRate(), employwages()
{
}
void EmployeeData::set_Name()
{       
	cout<<"\n\n\t\t\tEnter 3 Names: ";
	cout<<endl;
	string v;

	cout<<"\n\n\t\t\t";
	getline(cin, v);
	employName.push_back(v);

	cout<<"\n\n\t\t\t";
	getline(cin, v);
        employName.push_back(v);

	cout<<"\n\n\t\t\t";
	getline(cin, v);
        employName.push_back(v);
        cout<<endl;
}

void EmployeeData::set_Ho()
{
	int b;
	
	for(int i=0; i <3; i++)
	{
		b = 1 + rand() % (40 - 1 + 1);
		hours.push_back(b);
	}
}

void EmployeeData::set_Pa()
{
	double b;
	
	for (int i = 0; i <3; i++)
	{
		b = rand() / (RAND_MAX -1.0) * (30-12)+12;
		employpayRate.push_back(b);
	}
}

void EmployeeData::set_Wa()
{
	double e, c, a;

	for (int i = 0; i <3; i++)
	{
		e = employpayRate[i];
		c = hours[i];
		a = (e*c);
		employwages.push_back(a);
	}
}

void EmployeeData::Tab()
{
	cout<<"\n\n\n\t\t\tEmployee"<<"\tHours Worked"<<"\t\tRate"<<"\t\tWages";
	cout<<"\n\n\n\t\t\t==============================================================\n\t";
	cout<<"\n\n\n\t\t\t"<<employName[0]<<"\t\t"<<hours[0]<<"\t\t"<<employpayRate[0]<<"\t\t"<<"$"<<employwages[0];
	cout<<"\n\n\n\t\t\t"<<employName[1]<<"\t\t"<<hours[1]<<"\t\t"<<employpayRate[1]<<"\t\t"<<"$"<<employwages[1];
	cout<<"\n\n\n\t\t\t"<<employName[2]<<"\t\t"<<hours[2]<<"\t\t"<<employpayRate[2]<<"\t\t"<<"$"<<employwages[2];

	cout<<endl;
}
int main()
{
	system ("clear");
	cout<<fixed<<setprecision(2);
	EmployeeData S;

	S.set_Name();
	S.set_Ho();
	S.set_Pa();
	S.set_Wa();
	
	S. Tab();


	cout<<endl;
	return 0;
}


