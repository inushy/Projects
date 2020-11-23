/*   Anushka Verma
     Z1911937
     CSCI 340 Section - 1
     
     I certify that this is my own work and where appropriate an extension
     of the starter code provided for the assignment.
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int NO_ITEMS = 3; //words per line and the words are left aligned
int ITEM_W = 16;  //allocates certain number of spaces for an output value

void get_words(map<string, int>& m);
void print_words(const map<string, int>& m);
void clean_entry(const string& str, string& cleans);

void get_words(map<string, int>& m) //it gets a word from the input stream and removes its punctuation marks
{
    string s, clean; //store characters in s
    while(cin)
    {
        cin >> s;
        clean_entry(s, clean);
        if(clean.size() != 0)
        {
            m[clean]++;
        }
    }
}
void print_words(const map<string, int>& m) //it prints the final list of words and their frequencies, it also prints the number of nonempty words and the number of distinct words in the input stream
{
    int i = 0, iptstreamwords = 0; //Counts how many values have been printed per line
    for(auto const& pair: m) //for loop used to talk about each pair in the map
    {
        if(pair.second == 0) //Skips it if the pair is 0
        {
            continue;
        }
        if((i % NO_ITEMS) == 0 && i != 0) //Goes to a new line if the number of values printed are 3
        {
            cout << endl;
        }
        cout << setw(ITEM_W) << left << pair.first << " : " << setw(2) << pair.second << "\t";
        i++;
	iptstreamwords += pair.second;
    }
    cout << endl << endl;
    cout << "no of words in input stream  : " << iptstreamwords <<endl;
    cout << "no of words in output stream : " << m.size();
    cout << endl << endl;
}
void clean_entry(const string& str, string& cleans) //it cleans a word from its punctuation marks, the first argument is the original word in the input stream and the second argument contains the same word after cleaning
{
    string::const_iterator st = find_if(str.begin(), str.end(),
        [](char a)->bool{
            return isalnum(a) > 0;
        });

    string::const_iterator en = find_if(st, str.end(), [](char b)->bool {
            return isalnum(b) == 0;
            });

    cleans = str.substr(st - str.begin(), en - st);

    for_each(cleans.begin(), cleans.end(), [](char &c) {
            c = tolower(c);
            });
}
int main()
{
    // Map it out!
    map<string, int> m;
    // Gather words
    get_words(m);
    // Print words method
    print_words(m);
    return 0;
}
