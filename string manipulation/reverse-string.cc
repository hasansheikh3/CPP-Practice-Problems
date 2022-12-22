// A C++ Program that Reverse a given input string

#include <iostream>
#include <string>

using namespace std;

string reverseString(string& str);

int main()
{
    cout << "Please Insert a String : " << "\n";
    string str;
    getline(cin,str);

    cout << "The Reverse of the String is : " << reverseString(str) << "\n";
    

    return 0;
}

string reverseString(string& str)
{
    string temp;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        temp += str[i];
    }
    return temp;
}