#include <iostream>
#include <string>

using namespace std;

void count_num_alphabets(string& str);

int main()
{
    cout << "Enter a String : " << "\n";
    string str;
    getline(cin,str);

    count_num_alphabets(str); 
    return 0;
}

void count_num_alphabets(string& str)
{
    int num_of_alpabets = 0;
    int num_of_numbers = 0;

    for(int index=0; index<str.length(); index++)
    {
        
        if(str[index] >= '0' && str[index] <= '9')
        {
            num_of_numbers++;
        }
        else if((str[index] >= 'a' && str[index] <= 'z') || (str[index] >= 'A' && str[index] <= 'Z'))
        {
            num_of_alpabets++;
        }
    }

    cout << "Number of alphabets are : " << num_of_alpabets << " and num of integers are : " << num_of_numbers << "\n";
}