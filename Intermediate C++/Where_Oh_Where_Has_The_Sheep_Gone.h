//Anushka Verma
//Portfolio 2- Project1
//Header File
//07.02.2020
//Where, has the sheep gone?
#ifndef W_O_W_H_T_S_G_h
#define W_O_W_H_T_S_G_h
//#define Row 7
//#define Column 8
using namespace std;

class Arr2D
{
    char * arr2;
    size_t ROWS, COLS;
    void alloc(void) { arr2 = new(nothrow) char [ROWS*COLS]; return; }
public:
    Arr2D(void) : arr2(nullptr), ROWS(0), COLS(0) { }
    Arr2D(size_t R, size_t C) : arr2(nullptr), ROWS(R), COLS(C) { alloc(); }
        // copy constructor left to reader!!!
        // operator= left to reader!!!
    ~Arr2D(void) { delete [] arr2; }
    char & operator() (size_t r, size_t c) { return arr2[r*COLS+c]; }
        // *ALL* error checking left to reader!!!
};

/*bool gridsearch(char grid[Row][Column], int r, int c, string word);

void pattSearch(string word, char grid[Row][Column]);

int a[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int v[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool gridsearch(char grid[Row][Column], int r, int c, string word)
{
    bool value = false;

    if (grid[r][c] != word[0])
    {
        value = false;
    }
    int leng = static_cast<int>(word.length());
    for (int dir = 0; dir < 8; dir++)
    {
        int b;
        int rowdi = r + a[dir];
        int coldi = c + v[dir];
        for (b = 1; b < leng; b++)
        {
            if (rowdi >= Row || rowdi < 0 || coldi >= Column || coldi < 0)
            {
                break;
            }
            if (grid[rowdi][coldi] != word[b])
            {
                break;
            }
            rowdi += a[dir];
            coldi += v[dir];
        }
        if (b == leng)
        {
            value = true;
        }
    }
    return value;
}

void pattSearch(string word, char grid[Row][Column])
{
    for (int row = 0; row < Row; row++)
    {
        for (int col = 0; col < Column; col++)
        {
            //prints in a coordinate format
            if (gridsearch(grid, row, col, word))
            {
                cout << "\n\tYour word was found at " << row<<", ";
                cout <<col+1<< endl;
            }
        }
    }
}
*/
#endif /* W_O_W_H_T_S_G_h */
