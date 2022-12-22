// A C++ Program that Compares the two given strings using strcmp() function.

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int strCompare(char a[], char b[])
{
    int result = strcmp(a,b);
    return result;
}

int main()
{
    char a[] = "Hasan";
    char b[] = "Hasan";

    if(strCompare(a,b) == 0)
    {
        cout << "Both are Equal " << "\n";
    }
    else
    {
        cout << "Both are not equal " << "\n";
    }
    return 0;
}

// Output : Both are equal