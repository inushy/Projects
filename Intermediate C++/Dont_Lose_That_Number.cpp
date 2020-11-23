//Anushka Verma
//06/09/2020
//Portfolio 1 - Project 1

#include "Number.h"
#include <iostream>
#include <vector>
#include <climits>
#include <cctype>

using namespace std;

void Menu();
void printEditMenu(vector<RolodexEntry> & list);
void editContactSub(const short c, vector<RolodexEntry> & list);
void printSearchMenu(vector<RolodexEntry> & list);
void printList(vector<RolodexEntry> & list);
void eraseEntry(vector<RolodexEntry> & list, short index);


int main(void)
{
    bool isRunning = true;
    vector<RolodexEntry> list;
    do
    {
        char c;
        Menu();
        cout << "\n\n\t\t";
        cout << "\n\t\t\tYou chose: ";
        cin >> c;
        cin.ignore(INT_MAX, '\n');
        switch(c)
        {
        
            case '1':
            {
                    RolodexEntry newEntry;
                    newEntry.readIn();
                    list.push_back(newEntry);
                break;
            }
            case '2':
            {
                    printEditMenu(list);
                break;
            }
            case '3':
            {
                    printList(list);
                    cout << "\n\t\t\tSelect Contact to delete:";
                    cout << "\n\n\t\t";
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                    }
                    //short c;
                    cout << "\n\n\t\t";
                    cin >> c;
                    eraseEntry(list, c-1);
                break;
            }
            case '4':
            {
                    printSearchMenu(list);
                break;
            }
            case '5':
            {
                    printList(list);
                break;
            }
            case '6':
            {
                    isRunning = false;
                break;
            }
            default:
            {
                    cout << "\n\n\t\tInvalid selection.";
                break;
            }
        }
    }while(isRunning);

    return 0;
}
void Menu()
{
    cout << "\n\n\t\t\t\t";
    cout << "\n\n\t\t\t--------------------Your Main Menu------------------------";
    cout << "\n\n\t\t\t1....Add contact";
    cout << "\n\n\t\t\t2....Edit contact";
    cout << "\n\n\t\t\t3....Delete contact";
    cout << "\n\n\t\t\t4....Search contacts";
    cout << "\n\n\t\t\t5....Print all contacts";
    cout << "\n\n\t\t\t6....Exit";
    cout << "\n\n\t\t\t--------------Thank You For Participating-----------------";
    
    cout<<endl<<endl;
    return;
}
void printEditMenu(vector<RolodexEntry> & list)
{
    cout << "\n\n\t\t";
    printList(list);
    cout << "\n\t\t\tSelect Contact to edit:";
    cout << "\n\n\t\t";
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
    }
    short c;
    cin >> c;
    cin.ignore(INT_MAX, '\n');
    editContactSub(c, list);
    return;
}
void editContactSub(const short c, vector<RolodexEntry> & list)
{
    short index = c;
    if(index >= 0 && index < list.size())
    {
        RolodexEntry edited = list[static_cast<short>(c)-1];

        cout << "\n\n\t\t\t\t";
        cout << "\n\n\t\t\t--------Pick Your Option------------------------------------------";
        cout << "\n\n\t\t\t1....edit First name";
        cout << "\n\n\t\t\t2....edit Last name";
        cout << "\n\n\t\t\t3....edit Address";
        cout << "\n\n\t\t\t4....edit Phone number";
        cout << "\n\n\t\t\t5....edit Email\n";
        char cho;
        cin >> cho;
        cin.ignore(INT_MAX, '\n');

        switch(cho)
        {
            case '1':
            {
                    cout << "\n\n\t\tPlease Enter Your First Name: ";
                    string newName;
                    cout << "\n\n\t\t";
                    cin >> newName;
                    edited.setFName(newName);
                break;
            }
            case '2':
            {
                    cout << "\n\n\t\tPlease Enter Your Last Name: ";
                    string newName;
                    cout << "\n\n\t\t";
                    cin >> newName;
                    edited.setLName(newName);
                break;
            }
            case '3':
            {
                    cout << "\n\n\t\tPlease Enter Your Street Number And Street Name: ";
                    string newStreet;
                    cout.flush();
                    cout << "\n\n\t\t";
                    if (cin.peek() == '\n')
                    {
                        cin.ignore();
                    }
                    getline(cin, newStreet);
                    edited.setStreet(newStreet);

                    cout << "\n\n\t\tPlease Enter Your Town: ";
                    string newtown;
                    cout.flush();
                    cout << "\n\n\t\t";
                    if (cin.peek() == '\n')
                    {
                        cin.ignore();
                    }
                    getline(cin, newtown);
                    edited.setTown(newtown);

                    cout << "\n\n\t\tPlease Enter Your State: ";
                    string newstate;
                    cout.flush();
                    cout << "\n\n\t\t";
                    if (cin.peek() == '\n')
                    {
                        cin.ignore();
                    }
                    getline(cin, newstate);
                    edited.setState(newstate);

                    cout << "\n\n\t\tPlease Enter A Zipcode: ";
                    long newzip;
                    cout << "\n\n\t\t";
                    cin >> newzip;
                    if(newzip > 99999)
                    {
                        edited.setZip(newzip);
                        edited.setSZipLong();
                    }
                    else
                    {
                        edited.setSZip(newzip);
                    }
                break;
            }
            case '4':
            {
                    cout << "\n\n\t\tPlease Enter An Areacode: ";
                    short newarea;
                    cout << "\n\n\t\t";
                    cin >> newarea;
                    edited.setArea(newarea);

                    cout << "\n\n\t\tPlease Enter A New Exchange Number: ";
                    short newex;
                    cout << "\n\n\t\t";
                    cin >> newex;
                    edited.setExchange(newex);

                    cout << "\n\n\t\tEnter New Line: ";
                    short newLine;
                    cout << "\n\n\t\t";
                    cin >> newLine;
                    edited.setPLine(newLine);
                break;
            }
            case '5':
            {
                    cout << "\n\n\t\tEnter Add Your Email: ";
                    string newemail;
                    cout << "\n\n\t\t";
                    cin >> newemail;
                    edited.setEmail(newemail);
                break;
            }
        }
    }
    else
    {
        cout << "\n\n\t\tYou Choice Of Contact Does Not Exist!";
    }
    return;
}
void printSearchMenu(vector<RolodexEntry> & list)
{
    cout << "\n\n\t\t\t\t";
    cout << "\n\n\t\t\t--------Pick Your Option------------------------------------------";
    cout << "\n\n\t\t\t1....Search By Name";
    cout << "\n\n\t\t\t2....Search By Address";
    cout << "\n\n\t\t\t3....Search By Phone Number";
    cout << "\n\n\t\t\t4....Search By Email";
    cout << "\n\n\t\t\t5....Return To Main Menu";

     char c;
     cout << "\n\n\t\t";
     cin >> c;
     cin.ignore(INT_MAX, '\n');
     switch(c)
     {
            case '1':
            {
                    cout << "\n\n\t\tPlease Enter A Search Term: ";
                    string search;
                    cout.flush();
                    cout << "\n\n\t\t";
                    if (cin.peek() == '\n')
                    {
                        cin.ignore();
                    }
                    getline(cin, search);

                    for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
                    {
                        if(list[i].getFName().find(search) != string::npos ||
                           list[i].getLName().find(search) != string::npos)
                        {
                            list[i].printEntry();
                        }
                    }
                break;
            }
            case '2':
            {
                    cout << "\n\n\t\tPlease Enter A Search Term: ";
                    string search;
                    cout.flush();
                    cout << "\n\n\t\t";
                    if (cin.peek() == '\n')
                    {
                        cin.ignore();
                    }
                    getline(cin, search);

                    for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
                    {
                        if(list[i].getStreet().find(search) != string::npos ||
                           list[i].getTown().find(search) != string::npos ||
                           list[i].getState().find(search) != string::npos)
                        {
                            list[i].printEntry();
                        }
                    }
                break;
            }
            case '3':
            {
                    cout << "\n\n\t\tEnter The Last Four Digits Of Your Phone Number For Best Rsults\n\n\t\t";
                    cout << "\n\n\t\t";
                    short search;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                    }
                    cin >> search;

                    for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
                    {
                        if(list[i].getArea() == search || list[i].getExchange() == search ||
                           list[i].getPLine() == search)
                        {
                            list[i].printEntry();
                        }
                    }
                break;
            }
            case '4':
            {
                    cout << "\n\n\t\tEnter email: ";
                    string search;
                    cout.flush();
                    cout << "\n\n\t\t";
                    if (cin.peek() == '\n')
                    {
                        cin.ignore();
                    }
                    getline(cin, search);

                    for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
                    {
                        if(list[i].getEmail().find(search) != string::npos)
                        {
                            list[i].printEntry();
                        }
                    }
                break;
            }
            case '5':
            {
                break;
            }
         default:
         {
             cout << "\n\n\t\tInvalid seletion.";
            break;
         }
    }
}
void printList(vector<RolodexEntry> & list)
{
    cout << '\n';
    for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
    {
        cout << i+1 << ".";
        list[i].printEntry();
    }
    return;
}
void eraseEntry(vector<RolodexEntry> & list, short index)
{
    vector<RolodexEntry>::size_type pos = index-1;
    vector<RolodexEntry>::size_type k;

    if (pos < list.size() && pos >= 0)
    {
        for (k = pos+1; k != list.size(); k++)
        {
            list[k-1] = list[k];
        }
        list.pop_back();
    }
    else
    {
        cout << "\n\n\t\tOut of bounds.";
    }
    return;
}

void RolodexEntry::printEntry()
{
    cout << "\n\n\t\tName: " << firName << " " << lasName;
    cout << "\n\n\t\tAddress: " << street <<
                        "\n\n\t\t" << town << ", " <<
                        state << ' ';
                        if(zip != 0)
                        {
                            cout << zip;
                        }
                        else
                        {
                            cout << szip;
                        }
    cout << "\n\n\t\tPhone: (" << area << ')' << exchange << '-' << line << endl;
}
void RolodexEntry::readIn()
{
    cout << "\n\n\t\tEnter Your Contact's First Name: ";
    cout << "\n\n\t\t";
    cin >> firName;
    cout << "\n\n\t\tEnter Your Contacts's Last Name: ";
    cout << "\n\n\t\t";
    cin >> lasName;
    cin.ignore();
    cout << "\n\n\t\tEnter Your Contacts's Address (Include House Number and Street): ";
    cout.flush();
    cout << "\n\n\t\t";
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, street);

    cout << "\n\n\t\tEnter Your Contacts's Town: ";
    cout.flush();
    cout << "\n\n\t\t";
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, town);

    cout << "\n\n\t\tEnter Your Contacts's State: ";
    cout.flush();
    cout << "\n\n\t\t";
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, state);

    cout << "\n\n\t\tEnter Your Contacts's Zipcode: ";
    long tempZip;
    cout << "\n\n\t\t";
    cin >> tempZip;
    if(tempZip > 99999)
    {
        zip = tempZip;
        setSZipLong();
    }
    else
    {
        szip = tempZip;
    }
    cout << "\n\n\t\tEnter Your Contacts's Phone Number (Using Spaces): ";
    cout << "\n\n\t\t";
    cin >> area >> exchange >> line;
    cout << "\n\n\t\tEnter Your Contacts's Email: ";
    cout << "\n\n\t\t";
    cin >> email;
}
 
