//Anushka Verma
//03/21/2020
//class assignment

#include <iostream>
#include <cstring>
using namespace std;

class PersonalInfo
{
	private: 
		string your_name;
		string your_address;
		int age;
		string your_phonenumber;

	public:
		PersonalInfo();
		void setYourName();
		void setYourAddress();
		void setYourAge();
		void setYourPhoneNumber();
		string getYourName();
		string getYourAddress();
		int getYourAge();
		string getYourPhoneNumber();
};

PersonalInfo::PersonalInfo():your_name(""),your_address(""),age(0),your_phonenumber("")
{
}

void PersonalInfo::setYourName()
{
	cout<<"\n\n\t\tPlease Enter Your Name: ";
	getline(cin, your_name);
}
	
void PersonalInfo::setYourAddress()
{
	cout<<"\n\n\t\tPlease Enter Your Address: ";
	getline(cin, your_address);
}

void PersonalInfo::setYourAge()
{
	cout<<"\n\n\t\tPlease Enter Your Age: ";
	cin>>age;
	cin.ignore();
}
	
void PersonalInfo::setYourPhoneNumber()
{
	cout<<"\n\n\t\tPlease Enter Your Phone Number: ";
	getline(cin, your_phonenumber);
}

string PersonalInfo::getYourName()
{
	return your_name;
}
	
string PersonalInfo::getYourAddress()
{
	return your_address;
}
	
int PersonalInfo::getYourAge()
{ 
	return age;
}

string PersonalInfo::getYourPhoneNumber()
{
	return your_phonenumber;
}

int main()
{
	PersonalInfo p1;
	p1.setYourName();
	p1.setYourAddress();
	p1.setYourAge();
	p1.setYourPhoneNumber();
	cout<<"\n\n\n\t\t\tYour Personal Information: "<<endl<<endl;
	cout<<"\n\n\t\tYour Name: "<<p1.getYourName()<<endl;
	cout<<"\n\n\t\tYour Address: "<<p1.getYourAddress()<<endl;
	cout<<"\n\n\t\tYour Age: "<<p1.getYourAge()<<endl;
	cout<<"\n\n\t\tYour Phone Number: "<<p1.getYourPhoneNumber()<<endl;

	cout<<"\n\n\n\t\t\tYour Friend's Information: "<<endl<<endl;

	PersonalInfo p2;
        p2.setYourName();
        p2.setYourAddress();
        p2.setYourAge();
        p2.setYourPhoneNumber();
        cout<<"\n\n\n\t\t\tYour Personal Information: "<<endl<<endl;
        cout<<"\n\n\t\tYour Name: "<<p2.getYourName()<<endl;
        cout<<"\n\n\t\tYour Address: "<<p2.getYourAddress()<<endl;
        cout<<"\n\n\t\tYour Age: "<<p2.getYourAge()<<endl;
        cout<<"\n\n\t\tYour Phone Number: "<<p2.getYourPhoneNumber()<<endl<<endl;

}
