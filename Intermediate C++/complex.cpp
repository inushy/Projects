//Anushka Verma
//06/10/2020
//Portfolio 1 - Lab 3

#include <iostream>
using namespace std;

class complex
{
    public :
        int r, i;
};

int main()
{
    complex a, n, u;

    cout << "\n\n\t\t\t\tWelcome to the Complex Number Generator!"<<endl;
    cout << "\t-----------------------------------------------------------------";
    cout << "\n\n\tPlease Enter a And b Where a + bi Is The First Complex Number.";
    cout << "\n\n\ta = ";
    cin >> a.r;
    cout << "\n\tb = ";
    cin >> a.i;
    cout << "\n\n\tPlease Enter c And d Where c + di Is The Second Complex Number.";
    cout << "\n\n\tc = ";
    cin >> n.r;
    cout << "\n\td = ";
    cin >> n.i;

    u.r = a.r + n.r;
    u.i = a.i + n.i;

    if ( u.i >= 0 )
    {
        cout << "\n\n\tYour Sum Of Two Complex Numbers Are = " << u.r << " + " << u.i << "i";
    }
    else
    {
        cout << "\n\n\tYour Sum Of Two Complex Numbers Are = " << u.r << " " << u.i << "i";
    }
    cout << "\n\n\tPlease Enter a And b Where a - bi Is The First Complex Number.";
    cout << "\n\n\ta = ";
    cin >> a.r;
    cout << "\n\tb = ";
    cin >> a.i;
    cout << "\n\n\tPlease Enter c And d Where c - di Is The Second Complex Number.";
    cout << "\n\n\tc = ";
    cin >> n.r;
    cout << "\n\td = ";
    cin >> n.i;
    
    u.r = a.r - n.r;
    u.i = a.i - n.i;
    
    if ( u.i >= 0 )
    {
        cout << "\n\n\tYour Two Complex Numbers Are = " << u.r << " - " << u.i << "i";
    }
    else
    {
        cout << "\n\n\tYour Two Complex Numbers Are = " << u.r << " " << u.i << "i";
    }
    cout << "\n\n\tPlease Enter a And b Where a * bi Is The First Complex Number.";
    cout << "\n\n\ta = ";
    cin >> a.r;
    cout << "\n\tb = ";
    cin >> a.i;
    cout << "\n\n\tPlease Enter c And d Where c * di Is The Second Complex Number.";
    cout << "\n\n\tc = ";
    cin >> n.r;
    cout << "\n\td = ";
    cin >> n.i;
    
    u.r = a.r * n.r;
    u.i = a.i * n.i;
    
    if ( u.i >= 0 )
    {
        cout << "\n\n\tYour Two Complex Numbers Are = " << u.r << " * " << u.i << "i";
    }
    else
    {
        cout << "\n\n\tYour Two Complex Numbers Are = " << u.r << " " << u.i << "i";
    }
      
    cout << "\n\n\tPlease Enter a And b Where a / bi Is The First Complex Number.";
    cout << "\n\n\ta = ";
    cin >> a.r;
    cout << "\n\tb = ";
    cin >> a.i;
    cout << "\n\n\tPlease Enter c And d Where c / di Is The Second Complex Number.";
    cout << "\n\n\tc = ";
    cin >> n.r;
    cout << "\n\td = ";
    cin >> n.i;
    
    u.r = a.r / n.r;
    u.i = a.i / n.i;
    
    if ( u.i >= 0 )
    {
        cout << "\n\n\tYour Two Complex Numbers Are = " << u.r << " / " << u.i << "i";
    }
    else
    {
        cout << "\n\n\tYour Two Complex Numbers Are = " << u.r << " " << u.i << "i";
    }
    cout<<endl<<endl;
return 0;
}
