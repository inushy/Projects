//Anushka Verma
//02/23/2020
//Project 1
//Welcome to Versa Bank!  

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void menu();
int main()
{   int accountNumber,option;
    double mBalance, cBalance,transactionCode, deposits= 0, withdrawal= 0, tDeposits= 0, tWithdrawal= 0, tBalance=0, checkingScharge= 25.00;

    
    system("clear");
    cout <<fixed<<setprecision (2);
    cout << "\n\n\t\t***************************************************************************************************" << endl;
    cout << "\n\n\t\t\t\t\tWelcome to Versa Bank. Banking made easier!";
    cout << "\n\n\t\tTo make your online banking a better experience, please select an option from the menu below,and";
    cout << "\n\n\t\tfollow the instructions to find what you are looking for. Thank You for banking with Versa Bank!";
    cout << "\n\n\t\t***************************************************************************************************" << endl;
    menu ();
    cin >>option;
    
    while (option!=5)
    {
    	switch (option)
    	{
          case 1:
            	cout << "\n\n\t\t\t\tAccount Number: ";
            	cin >> accountNumber;
            	cout <<"\n\n\t\t\t\tAccount Type: Checking ";
		cout <<"\n\n\t\t\t\tTransaction Code: ";
		cin >> transactionCode;
		cout <<"\n\n\t\t\t\tMinimum Balance: $ ";
		cin >> mBalance;
            	cout << "\n\n\t\t\t\tCurrent Balance: $ ";
	        cin >> cBalance;
		cout << endl;
    		cout << "\n\n\t\t---------------------------------------------------------------------------------------------------" << endl;
            	menu ();
		cin >> option;
	        break;

          case 2:
	  	cout << "\n\n\t\t\t\tNumber of Deposits in this month: ";
                cin >> deposits;
		tDeposits += deposits;
	 	cout << "\n\n\t\t\t\tTotal Deposit in this month: "<<tDeposits;
		cout <<endl;
		cout << "\n\n\t\t---------------------------------------------------------------------------------------------------" << endl;
		menu();
		cin >> option;
	        break;

	  case 3:
		cout << "\n\n\t\t\t\tNumber of Withdrawals in this month: ";
                cin >> withdrawal;
		tWithdrawal += withdrawal;
		cout << "\n\n\t\t\t\tTotal Withdrawal in this month: "<<tWithdrawal;
		cout << endl;
		cout << "\n\n\t\t---------------------------------------------------------------------------------------------------" << endl;
		menu();
		cin >> option;
	        break;

	  case 4:
		if(cBalance < mBalance)
		{
			cout << "\n\n\t\t\t\tService Fee: $ "<< checkingScharge;
		}
		tBalance = tDeposits - tWithdrawal - checkingScharge;
		cout << "\n\n\t\t\t\tTotal Balance at the end of this month: $ "<<tBalance;
		cout << endl;
		cout << "\n\n\t\t***************************************************************************************************" << endl;
		menu();
		cin >> option;
                break;

	  default:
       	       cout << "\n\n\t\t\t\tNot An Option ";
	       cout <<endl;
	       menu();
	       cin >> option;
               break;
    	}
    }
    return 0;

}
void menu()
{
 cout << "\n\n\t\t1--Account Information\n";
 cout << "\n\n\t\t2--Deposit Information\n";
 cout << "\n\n\t\t3--Withdrawal Information\n";
 cout << "\n\n\t\t4--Balance Information\n";
 cout << "\n\n\t\t5--Exit\n";
 cout << "\n\n\t\tChoose Your Option ";
}
