/*
	<Anushka Verma> (<Z1911937>)
	Database
    Assignment 10
	03/22/2021
*/

#include <iostream>
#include <iomanip>
#include <mysql.h>
#include <string>

using namespace std;

#define SERVER   "courses"
#define USER     "z1911937"
#define PASS     "1997Apr20"
#define DATABASE "henrybooks"

void Book_List(MYSQL *Link);     //This function prints the list of the books comign from the database henrybooks, along with their author, book code and price 
void Author_Search(MYSQL *Link); //This function prints the report of all the books by the author the user searched
void Title_Search(MYSQL *Link);  //This function prints the report of all the books by the Title the user searched
void menu();                     //This function prints our menu

void Book_List(MYSQL *Link)      //This function prints the list of the books comign from the database henrybooks, along with their author, book code and price 
{
    if(Link)
    {
        MYSQL_RES *use_firstanswer; //Sets the pointer for the result
        MYSQL_ROW firstrow;         //Sets the rows an object

        //Runs the SQL Query
        mysql_query(Link,"SELECT b.BookCode, b.Title, CONCAT_WS(', ', AuthorLast, AuthorFirst) as AuthorName, b.Price FROM Book b, Author a, Wrote w WHERE w.AuthorNum = a.AuthorNum AND b.BookCode = w.BookCode ORDER BY w.Sequence");
        
        use_firstanswer = mysql_store_result(Link); //Stores all the results from the SQL statement above
        unsigned column = mysql_num_fields(use_firstanswer);  //Initializes the integer to run a loop to display the books
        cout << endl << setw(1) << left << "BookCode" << " ";
        cout << setw(5) << left << "Title" << " ";
        cout << setw(43) << right << "Author" << " ";
        cout << setw(42) << right << "Price" << " " << endl;
        cout << setw(1) << left << "========" << " ";
        cout << setw(1) << left << "==========================================" << " ";
        cout << setw(1) << left << "================================" << " ";
        cout << setw(1) << left << "================" << " " << endl;
        while((firstrow = mysql_fetch_row(use_firstanswer)) != NULL) //Helps to fetch a new row
        {
            cout << setw(8) << right << firstrow[0] << " ";
            cout << setw(42) << left << firstrow[1] << " ";
            cout << setw(30) << left << firstrow[2] << " ";
            cout << setw(18) << right << string("$") + string(firstrow[3]);
            cout << endl << endl << endl;
        }
        mysql_free_result(use_firstanswer);
    }
    else //If connection error --> Then print error message
    {
        cout << "Sorry Connection Failure! Please Try Again!" << endl << endl;
    }
}

void Author_Search(MYSQL *Link) //This function prints the report of all the books by the author the user searched
{
    cin.clear();
    string userInputAuthor; //Initialized variable to use further
    cout << endl;

    //Prompts the User to input the Author they are searching
    cout << endl << "Please Enter The Author You Are Looking For: ";
    cin >> userInputAuthor;
    cout << endl;
    cin.clear();

    //Runs the SQL Query
    string query = string("SELECT DISTINCT BookCode, Title, CONCAT_WS(', ', AuthorLast, AuthorFirst) as AuthorName, Price FROM Book JOIN Wrote USING (BookCode) JOIN Author USING (AuthorNum) WHERE AuthorFirst = '")+userInputAuthor+string("' OR AuthorLast = '")+userInputAuthor+string("'; ");
    int sets_answer = mysql_query(Link,query.c_str());  //Set's the answers to fetch rows one at a time

    MYSQL_RES *use_secondanswer = mysql_store_result(Link);
    if(use_secondanswer == NULL) //If an error occurs --> Then print error message
    {
        cout << "Sorry But An Error Occured With The Query! Please Try Again!" << endl << endl;
    }
    else //Otherwise, Prints the output
    {
        MYSQL_ROW secondrow;
        unsigned column = mysql_num_fields(use_secondanswer);
        cout << setw(1) << left << "BookCode" << " ";
        cout << setw(5) << left << "Title" << " ";
        cout << setw(43) << right << "Author" << " ";
        cout << setw(22) << right << "Price" << " " << endl;
        cout << setw(1) << left << "========" << " ";
        cout << setw(1) << left << "==========================================" << " ";
        cout << setw(1) << left << "=================" << " ";
        cout << setw(1) << left << "===========" << " " << endl;
        while(secondrow = mysql_fetch_row(use_secondanswer))    //Prints the non-indednted output
        {
            cout << setw(8)  << right << secondrow[0] << " ";
            cout << setw(45) << left << secondrow[1] << " ";
            cout << setw(18) << left << secondrow[2] << " ";
            cout << setw(7) << right << string("$") + string(secondrow[3]) << " ";
            cout << endl << endl << endl;

            //Runs the SQL Query2
            string query2 = string("SELECT Inventory.OnHand, Branch.BranchName, Branch.BranchLocation FROM Inventory LEFT JOIN Branch ON Branch.BranchNum = Inventory.BranchNum WHERE Inventory.BookCode = ")+string(secondrow[0])+string("; ");
            int sets_answer2 = mysql_query(Link,query2.c_str());    //Set's the answers to fetch rows one at a time

            MYSQL_RES *use_thirdanswer = mysql_store_result(Link);
            MYSQL_ROW thirdrow;
            unsigned column = mysql_num_fields(use_thirdanswer);
            while(thirdrow = mysql_fetch_row(use_thirdanswer))  //Prints the indented query of the output
            {
                cout << setw(11) << right  << "- " << thirdrow[0] << " available at ";
                cout << left << thirdrow[1] << " " ;
                cout << "("<< thirdrow[2]  << ")" << " ";
                cout << endl << endl << endl;
            }
        }
    }
    mysql_free_result(use_secondanswer); //Clears up the memory from the query
}

void Title_Search(MYSQL *Link)  //This function prints the report of all the books by the Title the user searched
{
    cin.clear();
    string userInputTitle; //Initialized variable to use further
    cout << endl;

    //Prompts the User to input the Author they are searching
    cout << endl << "Please Enter The Title You Are Looking For: ";
    cin.ignore(1, '\n');   // Clears the entry by ignoring the number that was typed before a new value was entered
    getline(cin, userInputTitle);  // Helps to collect User data (including the spaces between words) which we can use later
    cout << endl;
    cin.clear();

    //Runs the SQL Query
    string query = string("SELECT DISTINCT BookCode, Title,CONCAT_WS(', ', AuthorLast, AuthorFirst) as AuthorName, Price FROM Author JOIN Wrote USING (AuthorNum) JOIN Book USING (BookCode) WHERE Title = '")+userInputTitle+string("'; ");
    int sets_answer = mysql_query(Link,query.c_str());  //Set's the answers to fetch rows one at a time

    MYSQL_RES *use_secondanswer = mysql_store_result(Link);
    if(use_secondanswer == NULL) //If an error occurs --> Then print error message
    {
        cout << "Sorry But An Error Occured With The Query! Please Try Again!" << endl << endl;
    }
    else //Otherwise, Prints the output
    {
        MYSQL_ROW secondrow;
        unsigned column = mysql_num_fields(use_secondanswer);
        cout << setw(1) << left << "BookCode" << " ";
        cout << setw(5) << left << "Title" << " ";
        cout << setw(43) << right << "Author" << " ";
        cout << setw(22) << right << "Price" << " " << endl;
        cout << setw(1) << left << "========" << " ";
        cout << setw(1) << left << "==========================================" << " ";
        cout << setw(1) << left << "=================" << " ";
        cout << setw(1) << left << "===========" << " " << endl;
        while(secondrow = mysql_fetch_row(use_secondanswer))    //Prints the non-indednted output
        {
            cout << setw(8)  << right << secondrow[0] << " ";
            cout << setw(45) << left << secondrow[1] << " ";
            cout << setw(18) << left << secondrow[2] << " ";
            cout << setw(7) << right << string("$") + string(secondrow[3]) << " ";
            cout << endl << endl << endl;

            //Runs the SQL Query2
            string query2 = string("SELECT Inventory.OnHand, Branch.BranchName, Branch.BranchLocation FROM Inventory LEFT JOIN Branch ON Branch.BranchNum = Inventory.BranchNum WHERE Inventory.BookCode = ")+string(secondrow[0])+string("; ");
            int sets_answer2 = mysql_query(Link,query2.c_str());    //Set's the answers to fetch rows one at a time
            
            MYSQL_RES *use_thirdanswer = mysql_store_result(Link);
            MYSQL_ROW thirdrow;
            unsigned column = mysql_num_fields(use_thirdanswer);
            while(thirdrow = mysql_fetch_row(use_thirdanswer))  //Prints the indented query of the output
            {
                cout << setw(11) << right  << "- " << thirdrow[0] << " available at ";
                cout << left << thirdrow[1] << " " ;
                cout << "("<< thirdrow[2]  << ")" << " ";
                cout << endl << endl << endl;
            }
            mysql_free_result(use_thirdanswer); //Clears up the memory from the query
        }
    }
    mysql_free_result(use_secondanswer); //Clears up the memory from the query
}

int main()
{
    int option;

    cout << endl;
    cout << "\tWelcome To Henry's Book Barn" << endl;
    cout << "--------------------------------------------" << endl;
    menu();
    cin >> option;

    if(cin.fail()) //In case cin fails
    {
        cin.clear();
        cin.ignore(10000, '\n');
    }

    int sql = mysql_library_init(0, NULL, NULL); //Initializes the Library
    MYSQL *Link; //Links to the MariaDB Server

    Link = mysql_init(NULL); //Initializes the Link object
    if(mysql_real_connect(Link, SERVER, USER, PASS, DATABASE, 0 , NULL ,0) == NULL )  //If Link, estabilished to MariaDB failed..
    {
        cout << "Sorry Connection Failure! Please Try Again!" << endl << endl;   //Then display Error Message
    }

    while (option != 4)
    {
        switch (option)
        {
            case 1:
                 Book_List(Link);
                 menu();
                 cin >> option;
                 cout << endl << endl;
                 break;
            
            case 2:
                 cin.clear();
                 Author_Search(Link);
                 menu();
                 cin >> option;
                 cout << endl << endl;
                 break;

            case 3:
                 cin.clear();
                 Title_Search(Link);
                 menu();
                 cin >> option;
                 cout << endl << endl;
                 break;
            
            case 4:
                 cout << endl;
                 cout << "--------------------------------------------";
                 cout << "Thanks For Visiting Us! " << endl;
                 menu();
                 cout << endl;
                 break;

            default:
                 cout << endl;
                 cout << "Invalid Option, Please Try Again!" << endl;
                 exit(0); 
                 break;
        }
    }
    return 0;
}

void menu()    //This function prints our menu
{
    cout << "============================================" << endl;
    cout << "\t\tMenu Barn" << endl;
    cout << "============================================" << endl;
    cout << "\t\t1.Book List" << endl;
    cout << "\t\t2.Search Author" << endl;
    cout << "\t\t3.Search Title" << endl;
    cout << "\t\t4.Exit" << endl;
    cout << "============================================" << endl;
    cout << "You Picked Option: ";
}