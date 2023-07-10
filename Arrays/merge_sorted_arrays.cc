/*

Given two integer arrays, each of which is sorted in increasing order, merge them into a single array in increasing order, and return it.

Input: X = [1, 3, 5, 7], Y = [2, 4, 6]
Output: [1, 2, 3, 4, 5, 6, 7]

Link : https://www.techiedelight.com/?problem=SortedMergeArrays

**************PLEASE TRY TO SOLVE THIS PROBLEM ON YOUR OWN BEFORE LOOKING AT THE SOLUTION***************


*/

#include <bits/stdc++.h>

using namespace std;


// Approach 1: Using two pointers
vector<int> mergeSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    /*
    My Approach
    1. Use two pointers to iterate over both arrays
    2. Compare the elements at the two pointers and add the smaller one to the result array
    3. Increment the pointer of the array whose element was added to the result array
    4. Repeat steps 2 and 3 until both pointers reach the end of their respective arrays
    5. Add the remaining elements of the array whose pointer has not reached the end to the result array
    Time complexity: O(n)
    Space complexity: O(n)
    */

    // edge cases
    if (nums1.size() == 0)
    {
        return nums2;
    }
    if (nums2.size() == 0)
    {
        return nums1;
    }
    vector<int> result;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
        }
        else
        {
            result.push_back(nums2[j]);
            j++;
        }
    }
    while (i < nums1.size())
    {
        result.push_back(nums1[i]);
        i++;
    }
    while (j < nums2.size())
    {
        result.push_back(nums2[j]);
        j++;
    }
    return result;
}


// Approach 2: Using STL
vector<int> mergeSortedArraysUsingSTL(vector<int> &nums1, vector<int> &nums2)
{
    /*
    My Approach
    1. Use the merge function from the STL
    Time complexity: O(n)
    Space complexity: O(n)
    */

    // edge cases
    if (nums1.size() == 0)
    {
        return nums2;
    }
    if (nums2.size() == 0)
    {
        return nums1;
    }


    vector<int> result;
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(result)); // back_inserter is used to insert elements at the end of the vector
    return result;
}


int main()
{
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {2, 4, 6};
    vector<int> result = mergeSortedArrays(nums1, nums2);
    for (int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    result = mergeSortedArraysUsingSTL(nums1, nums2);
    for (int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}