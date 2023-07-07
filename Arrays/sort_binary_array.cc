/*

Given a binary array, in-place sort it in linear time and constant space. The output should contain all zeroes, followed by all ones.

Input : [1, 0, 1, 0, 1, 0, 0, 1]
Output: [0, 0, 0, 0, 1, 1, 1, 1]

Input : [1, 1]
Output: [1, 1]

link : https://www.techiedelight.com/?problem=SortBinaryArray

**************PLEASE TRY TO SOLVE THIS PROBLEM ON YOUR OWN BEFORE LOOKING AT THE SOLUTION***************
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sort_binary_array(vector<int> &v)
{

    /*
    1. Declare three variables, low, mid and high
    2. While mid is less than or equal to high, switch on the value of v[mid]
    3. Swap values of v[low] and v[mid] if v[mid] is 0, increment low and mid
    4. Increment mid if v[mid] is 1
    Time Complexity : O(n)
    Space Complexity : O(1)

    Brain Teaser : Why do we need to check mid <= high and not low <= high ??    
    */
    int low = 0;  // low index
    int high = v.size() - 1;  // high index, size() returns the number of elements in the vector and since the index starts at 0, we need to subtract 1
    int mid = 0;

    while (mid <= high) // while mid index is less than or equal to high index, means mid reaches high, we need to check mid and not low because we are not sure if the low index is 0 or 1
    {
        switch (v[mid])
        {
            case 0:
                swap(v[low++], v[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(v[mid], v[high--]);
                break;
        }
    }
}

// time complexity is O(n)


void alternate_sort_binary_array(vector<int> &v)
{
    int zeros = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            zeros++;
        }
    }


    for (int i = 0; i < zeros; i++)
    {
        v[i] = 0;
    }

    for (int i = zeros; i < v.size(); i++)
    {
        v[i] = 1;
    }
}

// time complexity is O(n)


int main()
{
    vector<int> v = {0,1,0,1,0,0,1,1,1,0};
    sort_binary_array(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}