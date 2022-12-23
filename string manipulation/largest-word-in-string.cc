//  Write a C++ program to find the largest word in a given string.
// input : i love programming
// output : programming
// resource : https://www.w3resource.com/cpp-exercises/string/index.php

#include <iostream>
#include <string>
#include <vector>

using namespace std;



string largest_word(string& word);

int main()
{
    cout << "Please Enter a String \n";
    string word;
    getline(cin,word);

    largest_word(word);

    cout << "The largest word in the string is " << word << "\n";
    return 0;
}

string largest_word(string& word)
{
    vector<string> words;
    string temp;
    for(int i=0;i<word.length();i++)
    {
        if(word[i] == ' ')
        {
            words.push_back(temp);
            temp = "";
        }
        else
        {
            temp += word[i];
        }
    }
    words.push_back(temp);
    int max = 0;
    for(int i=0;i<words.size();i++)
    {
        if(words[i].length() > max)
        {
            max = words[i].length();
            word = words[i];
        }
    }
    return word;
}