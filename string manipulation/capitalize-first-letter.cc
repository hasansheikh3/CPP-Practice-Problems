// Write a C++ program to capitalize the first letter of each word of a given string. 
// Words must be separated by only one space.
// input : i am learning cpp
// output : I Am Learning Cpp

#include <iostream>
#include <string>

using namespace std;

string capitalize_first_letter(string& word);

int main()
{
    cout << "Please Enter some words : ";
    string word;
    getline(cin,word);

    capitalize_first_letter(word);

    cout << "The changed string is  : " << word << "\n";
    return 0;
}

string capitalize_first_letter(string& word)
{
    word[0] = toupper(word[0]);      // Always capitalize the first letter
    for(int i=1;i<word.length();i++)
    {
        if(word[i] == ' ')
        {
            word[i+1] = toupper(word[i+1]);
        }
    }
    return word;
}