/*

Given two strings, determine whether they are anagrams.

Any word that exactly reproduces the letters in another order is an anagram. In other words, X and Y are anagrams if by rearranging the letters of X, we can get Y using all the original letters of X exactly once.

Input: X = "silent", Y = "listen"
Output: true

Input: X = "incest", Y = "insect"
Output: true

Link : https://www.techiedelight.com/?problem=CheckAnagram

**************PLEASE TRY TO SOLVE THIS PROBLEM ON YOUR OWN BEFORE LOOKING AT THE SOLUTION***************

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

bool isAnagram(const string& str1, const string& str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

bool efficientIsAnagram(const string& str1, const string& str2)
{
    map<char, int> char_count;
    for (char ch : str1)
    {
        char_count[ch]++;
    }

    for (char ch : str2)
    {
        char_count[ch]--;
    }

    for (const auto& entry : char_count)
    {
        if (entry.second != 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    string str1 = "listen";
    string str2 = "silent";

    cout << "Using isAnagram: " << (isAnagram(str1, str2) ? "Yes" : "No") << endl;
    cout << "Using efficientIsAnagram: " << (efficientIsAnagram(str1, str2) ? "Yes" : "No") << endl;

    return 0;
}
