// This program change every letter with the next letter, for example abc becomes bcd.
// sample input : hasan
// expected output : ibtbo

#include <iostream>
#include <string>
#include <vector>

using namespace std;



string change_every_letter(string& word);

int main()
{
    cout << "Please Enter a Word \n";
    string word;
    getline(cin,word);

    change_every_letter(word);

    cout << "The changed word is " << word << "\n" ;
    
}

string change_every_letter(string& word)
{
    
    for(int i=0;i<word.length();i++)
    
     {
        
        word[i] = word[i] + 1;

    }
    return word;
}
