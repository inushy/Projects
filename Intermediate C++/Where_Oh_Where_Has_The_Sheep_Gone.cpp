//Anushka Verma
//Portfolio 2- Project1
//07.02.2020
//Where, has the sheep gone?
#include <iostream>
#include <fstream>
#include "W_O_W_H_T_S_G.h"

int main()
{
    string let, word[10];
    int i=0, temp=0;
    ofstream myfile ("words.txt");
    if (myfile.is_open())
    {
        myfile << "apple\n";
        myfile << "pear\n";
        myfile << "banana\n";
        myfile << "grape\n";
        myfile << "orange\n";
        myfile.close();
    }
    ifstream file("words.txt");
    while(!file.eof())
    {
        file>>let>>ws;
        if(static_cast<unsigned>(temp)<let.length())
        {
            temp=static_cast<int>(let.length());
        }
        word[i++]= let;
    }
    i--;
    
    int size=temp+1;
    char grid[size][size];
    int gridx[size][size];
    for(int x=0; x<size; x++)
    {
        for(int y=0; y<size; y++)
        {
            grid[x][y] = '0';
        }
    }
    for(int k=0; k<i; k++)
    {
        int length = static_cast<int>(word[k].length());
        int j = rand()%3;
        while(j >= 0 || j <=3)
        {
            if(j == 0)
            {
                int h = rand()%size;
                int u = rand()%(size-length);
                for(int m=0; m<length; m++)
                {
                    if(grid[h][u] == '0')
                    {
                        grid[h][u++] = word[k][m];
                    }
                    else if(grid[h][u] == word[k][m])
                    {
                        gridx[h][u] = 1;
                        u++;
                    }
                    else
                    {
                        for(int n = m; n>=0;n--)
                        {
                            if(gridx[h][--u] == 0)
                            {
                                grid[h][u] = '0';
                            }
                        }
                        k--;
                        break;
                    }
                }
                break;
            }
            else if (j == 1)
            {
                int r = rand()%(size - length);
                int c = rand()%size;
                for(int m=0; m<length; m++)
                {
                    if(grid[r][c] == '0')
                    {
                        grid[r++][c] = word[k][m];
                    }
                    else if(grid[r][c] == word[k][m])
                    {
                        gridx[r][c] = 1;
                        r++;
                    }
                    else
                    {
                        for(int n = m; n>=0;n--)
                        {
                            if(gridx[--r][c] == 0)
                            {
                                grid[r][c] = '0';
                            }
                        }
                        k--;
                        break;
                    }
                }
                break;
            }
            else if (j == 2)
            {
                int r = rand()%(size - length);
                int c = rand()%(size - length);
                for(int m=0; m<length; m++)
                {
                    if(grid[r][c] == '0')
                    {
                        grid[r++][c++] = word[k][m];
                    }
                    else if(grid[r][c] == word[k][m])
                    {
                        gridx[r][c] = 1;
                        r++;
                        c++;
                    }
                    else
                    {
                        for(int n = m; n>=0;n--)
                        {
                            if(gridx[--r][--c] == 0)
                            {
                                grid[r][c] = '0';
                            }
                        }
                        k--;
                        break;
                    }
                }
                break;
            }
        }
    }
    for(int x=0; x<size; x++)
    {
        for(int y=0; y<size; y++)
        {
            if(grid[x][y] == '0')
            {
                int val = rand()%26;
                val+=97;
                grid[x][y] = val;
            }
        }
    }
    cout<<"\n\n\tWelcome To Your WordSearch Game!!!"<<endl;
    cout<<"\n\t********************************";
    cout<<"****************************"<<endl;
    cout<<"\n\tSearch The Puzzle For The Words";
    cout<<" Shown In The Word List Below"<<endl;
    cout<<"\n\t-------------------------------";
    cout<<"-----------------------------"<<endl;
    
    size_t ROWS = 0, COLS = 0;
    int** a = new int*[ROWS];
    for(int i = 0; i < ROWS; ++i)
    {
        a[i] = new int[COLS];
    }
    /*Arr2D ar(ROWS,COLS);
    
    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            cout << ar(r,c)<< "";
        }
    }*/

  /*  for(int x=0; x<size; x++)
    {
        cout<<"\n\t\t\t";
        for(int y=0; y <size; y++)
            cout << grid[x][y] << " ";
    }
    cout << endl;
    char grid1[Row][Column];
    for (int x=0 ; x < 10; x++)
    {
        for (int y=0 ; y < 10; y++)
        {
            grid1[x][y] = grid[x][y];
        }
    }*/
    string option;
    while (option != "Exit")
    {
        cout<<"\n\tYour Word List Are: apple, pear,";
        cout<<" orange, grape, and banana"<<endl;
        cout<<"\n\t\tTo Quit The Game, Please Type 'Exit'";
        cout<<"\n\t---------------------------------";
        cout<<"---------------------------"<<endl;
        cout<<"\n\tYou Picked: ";
        cin >> option;
        
        /*else
        {
            cout<<"\n\t********************************";
            cout<<"****************************"<<endl;
            cout<<"\n\tWe Hope You Enjoyed Playing As ";
            cout<<"Much As We Enjoyed Generating"<<endl;
            cout<<"\n\tThe Puzzle For You!";
            cout<<" Thank You For Playing With Us! "<<endl;
            cout<<"\n\tDo Visit Us Again!!"<<endl<<endl;
        }
        if(option != "Exit")
        {
            pattSearch(option, grid1);
            cout << endl;
            for(int x=0; x<size; x++)
            {
                cout<<"\n\t\t\t";
                for(int y=0; y <size; y++)
                {
                    cout << grid1[x][y] << " ";
                }
            }
            cout << endl <<endl;
        }
        else
        {
            cout<<"\n\t********************************";
            cout<<"****************************"<<endl;
            cout<<"\n\tWe Hope You Enjoyed Playing As ";
            cout<<"Much As We Enjoyed Generating"<<endl;
            cout<<"\n\tThe Puzzle For You!";
            cout<<" Thank You For Playing With Us! "<<endl;
            cout<<"\n\tDo Visit Us Again!!"<<endl<<endl;
        }
    }*/
    return 0;
}

}
