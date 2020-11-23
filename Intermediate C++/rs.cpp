//
//  irs.cpp
//  Misc
//
//  Created by Anushka Verma on 6/16/20.
//  Copyright © 2020 Anushka Verma. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
const size_t MAX_STRING = 10;

//void shuffle(char strings[][MAX_STRING], size_t num_strings);
void display(const char lines[][MAX_STRING], size_t num_lines,
             char separ = '\n');
bool PromptCont();

int main()
{
    const size_t BusN_MAX = MAX_STRING;
    typedef char NameT[BusN_MAX];

    const size_t MAX_NAMES = 10;
    NameT Business_name[MAX_NAMES];
    size_t num_names = 0;

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "\n\n\t\t\t\tWelcome To The Business Sorting Program!";
    cout << "\n\n\t\t-----------------------------------------------------"<<endl;
    char arr[5][20], tol[20];
    int uu, qq;


    for(uu=0; uu<5; uu++)
    {
        cout << "\n\n\t\tPlease Enter Your Business Name: \n";
        cout.flush();
        cout <<"\n\n\t\t";
        while (num_names != MAX_NAMES &&
               cin.peek() != '\n')
        cin >> arr[uu];
    {
        cin >> setw(BusN_MAX) >> Business_name[num_names++];
    }
        
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(uu=1; uu<5; uu++)
    {
        for(qq=1; qq<5; qq++)
        {
            if(strcmp(arr[qq-1], arr[qq])>0)
            {
                strcpy(tol, arr[qq-1]);
                strcpy(arr[qq-1], arr[qq]);
                strcpy(arr[qq], tol);
            }
        }
    }
        for(uu=0; uu<5; uu++)
        {

    if (num_names > 0)
       {
           cout <<"\n\n\t\tYour Business Name is: ";
           cout <<"\n\n\t\t";
           cout<<arr[uu]<<"\n";
           display(Business_name, num_names,' ');
           cout <<endl<<endl;
       }


    return 0;
}


/*inline void swap(char a[], char b[])
{
    char c[MAX_STRING];

    strncpy(c, b, MAX_STRING-1);  // protect c since we know its size
    c[MAX_STRING-1] = '\0';

    strcpy(b, a);                 // can't protect these -- we'll
    strcpy(a, c);                 //    learn how later...
    return;
}

void display(const char lines[][MAX_STRING], size_t num_lines,
             char separ)
{
    if (num_lines > 0)
    {
        for (size_t l = 0; l+1 != num_lines; ++l)  // isn't l just a horrible
        {                                          //    variable name?!
            cout << lines[l] << separ;
        }
        cout << lines[num_lines-1];
    }
    return;
}

bool PromptCont ()
    {
    std::string prompt = "";

    cout << "\n\n\t\tAnother Business? ";

    cin >> prompt;

    cin.ignore ();
        if (prompt == "No")
        {
            cout<<"\n\n\t\t-----------------------------------------------------";
            cout<<"\n\n\t\t\t\t Thank You For Using The BS Program!"<<endl;
            cout<<"\n\n\t\t\t\t\t\tHave A Wonderful Day!"<<endl<<endl;
        }
    return (prompt == "Yes");
    }

//int main()
//{

    //cout << "Welcome to Business Sorting Program";
//char arr[5][20], tol[20];

//int uu, qq;

//for(uu=0; uu<5; uu++)

//{

//cout << "Enter a businessman (name) : ";

//cin >> arr[uu];

//}

//*for(uu=1; uu<5; uu++)

{

for(qq=1; qq<5; qq++)

{

if(strcmp(arr[qq-1], arr[qq])>0)

{

strcpy(tol, arr[qq-1]);

strcpy(arr[qq-1], arr[qq]);

strcpy(arr[qq], tol);

}

}

}

for(uu=0; uu<5; uu++)

{*/

   // cout << "Businessman (Names) are : \n";

    //cout<<arr[uu]<<"\n";

//}

return 0;

}
}
