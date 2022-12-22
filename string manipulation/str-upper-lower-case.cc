// Write a C++ Program that takes a string as an input and print lower and upper case of the input string

#include <iostream>

using namespace std;

string toUpperCase(string& str);

string toLowerCase(string& str);

int main()
{
    cout << "Please Enter a String " << "\n";
    string str;
    getline(cin,str);
    
    toUpperCase(str);
    cout << "String in Uppercase is : " << str << "\n"; 
    toLowerCase(str);
    cout << "String in Lower case is : "<< str << "\n";

    return 0;
}

string toUpperCase(string& str)
{
    for (int i=0; i<str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}

string toLowerCase(string& str)
{
    for (int i=0; i<str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

