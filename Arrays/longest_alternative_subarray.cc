/*

Given an array containing positive and negative elements, find a subarray with alternating positive and negative elements, and in which the subarray is as long as possible.

Input : [1, -2, 6, 4, -3, 2, -4, -3]
Output: [4, -3, 2, -4]

Note that the longest alternating subarray might not be unique. In case the multiple alternating subarrays of maximum length exists, the solution can return any one of them.

Input : [1, -2, 6, 2, 4, -3, 2, 4, -3]
Output: [1, -2, 6] or [4, -3, 2]

Link : https://www.techiedelight.com/?problem=LongestAlternatingSubarray

**************PLEASE TRY TO SOLVE THIS PROBLEM ON YOUR OWN BEFORE LOOKING AT THE SOLUTION***************

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> LongestAlternativeSubArray(vector<int> &nums)
{

    /*
    My solution:
    1. Handle edge cases
    2. Iterate over the array and keep track of the start and end of the subarray
    3. If the product of the current element and the previous element is negative, 
    then the subarray is still alternating. So, update the end of the subarray.
    4. If the product of the current element and the previous element is positive, 
    then the subarray is no longer alternating. So, update the start and end of the subarray.
    5. If the length of the current subarray is greater than the length of the previous subarray, 
    then update the result.

    Time complexity: O(n)
    Space complexity: O(n)
    
    */
    if (nums.empty())
    {
        return {};
    }

    if (nums.size() == 1)
    {
        return nums;
    }

    vector<int> result;

    int max_len = 0;
    int start = 0;
    int end = 0;


    for (int i=1; i<nums.size(); i++)
    {
        if (nums[i] * nums[i-1] < 0)
        {
            end = i;
        }
        else
        {
            if (end - start + 1 > max_len)
            {
                max_len = end - start + 1;
                result = {nums.begin() + start, nums.begin() + end + 1};
            }
            start = i;
            end = i;

        }
    }

    if (end - start + 1 > max_len)
    {
        max_len = end - start + 1;
        result = {nums.begin() + start, nums.begin() + end + 1};
    }

    return result;
}

int main()
{
    vector<int> nums = {1, -2, 6, 4, -3, 2, -4, -3};
    vector<int> result = LongestAlternativeSubArray(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}