// Find the memory address of a given variable using pointers.
// source : https://www.codesdope.com/practice/cpp-pointers/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please input a number : ";
    int num;
    cin >> num;

    int *pnum = &num;

    cout << "The memory address of the given number is " << pnum << "\n";
    return 0;
}
