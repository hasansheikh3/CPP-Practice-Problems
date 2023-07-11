/*

Given a sorted integer array and a target, determine if the target exists in the array in logarithmic time. If target exists in the array, the procedure should return the index of it.

Input: nums[] = [2, 3, 5, 7, 9], target = 7
Output: 3
Explanation: Element found at 4th (index 3) position

• If there are duplicate elements in the array, the procedure may return any index whose element is equal to the target.

Input: nums[] = [1, 2, 3, 4, 4, 5, 6, 7], target = 4
Output: 3 (or 4)
Explanation: Element found at the 4th (index 3) or 5th (index 4) position.

• If the target is not located, the procedure should return -1.

Input: nums[] = [1, 4, 5, 8, 9], target = 2
Output: -1

*/

#include <iostream>
#include <vector>

using namespace std;

int findIndex(vector<int> &nums, int target)
{
    /*
    My solution:
    1. This is a simple Binary Search problem.

    Time complexity: O(logn)
    Space complexity: O(1)
    
    */
    // edge cases
    if (nums.empty())
    {
        return -1;
    }

    if (nums.size() == 1)
    {
        return nums[0] == target ? 0 : -1;
    }
    int start=0;
    int end=nums.size() - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 4, 5, 6, 7};
    vector<int> nums = {1, 3, 5, 8, 9};
    int target = 4;
    cout << "Index of " << target << " is " << findIndex(nums, target) << endl;
    return 0;
}