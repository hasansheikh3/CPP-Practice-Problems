
/*

Given an integer array, find the maximum sum among all its subarrays.

Input : [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: The maximum sum subarray is [4, -1, 2, 1]

Input : [-7, -3, -2, -4]
Output: -2
Explanation: The maximum sum subarray is [-2]

Input : [-2, 2, -1, 2, 1, 6, -10, 6, 4, -8]
Output: 10
Explanation: The maximum sum subarray is [2, -1, 2, 1, 6] or [6, 4] or [2, -1, 2, 1, 6, -10, 6, 4]

Link : https://www.techiedelight.com/?problem=MaximumSumSubarray

 **************PLEASE TRY TO SOLVE THIS PROBLEM ON YOUR OWN BEFORE LOOKING AT THE SOLUTION***************

*/

#include <bits/stdc++.h>

using namespace std;


int MaximumSumSubArrayUsingNestedLoops(vector<int> &nums)
{
    /*
    My Approach
    1. Use nested loops to iterate over all subarrays
    2. Keep track of the maximum sum
    Time complexity: O(n^2)

    Brain teaser: Can you do better than O(n^2) Time complexity?

    */
    int max_sum = INT_MIN;
    int sum = 0;
    for (int i=0; i<nums.size(); i++)
    {
        sum = 0;
        for (int j=i; j<nums.size(); j++)
        {
            sum += nums[j];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

int max(int a, int b)
{
    return ( a > b ) ? a : b;
}

int MaximumSumSubArray(vector<int> &nums)
{
    /*
    1. Declare two Variables, current_sum and max_sum.
    2. Track the current sub_array sum using current_sum and max sub_array sum using max_sum.
    3. If current_sum is greater than max_sum, update the max_sum.
    4. If current_sum is negative, set it to zero, since negative will reduce the max_sum.
    5. Iterate through a for loop and repeat steps from 2-4.
    6. This approach is called Kadane's Algorithm.
    Time Complexity : O(n)
    */

    int max_sum = nums[0];
    int curr_sum = nums[0];

    for (int i=1; i<nums.size(); i++)
    {
        curr_sum+=nums[i];
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
        max_sum = max(max_sum,curr_sum);
    }

    return max_sum;
    
}

// TODO : Implement Divide and Conquer approach (I did not understand this approach, will upload the solution once I understand it)

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = MaximumSumSubArray(nums);
    cout << "Result : " << result << endl;
    return 0;
}