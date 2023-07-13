/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Link: https://leetcode.com/problems/3sum-closest/

***************************PLEASE SOLVE ON YOUR OWN BEFORE LOOKING AT THE SOLUTION BELOW***************************

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    // edge cases
    if (nums.empty())
    {
        return 0;
    }

    int n = nums.size();
    if (n <= 3)
    {
        if (n < 3)
        {
            return 0;
        }
        return nums[0] + nums[1] + nums[2];
    }

    // sort the array
    sort(nums.begin(), nums.end()); // O(nlogn)

    cout << "Sorted array: " << '\n';
    for (int i=0; i<n; i++)
    {
        cout << nums[i] << " ";
    }

    int closestSum = nums[0] + nums[1] + nums[2]; // initialize closestSum to the sum of the first three elements, this is our initial guess
    cout << "\nInitial guess: " << closestSum << '\n';

    for (int i = 0; i < n - 2; i++)  // loop throug n-2 elements, for example, if n = 5, we only need to loop through 0, 1, 2
    {
        cout << "i: " << i << '\n';
        int start = i + 1;  // start from the next element
        int end = n - 1;    // end at the last element
        cout << "start: " << start << '\n';
        cout << "end: " << end << '\n';

        while (start < end)
        {
            cout << "While loop: " << '\n';
            int sum = nums[i] + nums[start] + nums[end];
            cout << "sum: " << sum << '\n';
            if (abs(target - sum) < abs(target - closestSum))
            {
                cout << "abs(target - sum): " << abs(target - sum) << '\n';
                closestSum = sum;
                cout << "closestSum: " << closestSum << '\n';
            }

            if (sum > target)
            {
                cout << "sum > target" << '\n';
                cout << "sum: " << sum << '\n';
                cout << "target: " << target << '\n';
                end--;
            }
            else
            {
                cout << "sum <= target" << '\n';
                cout << "sum: " << sum << '\n';
                cout << "target: " << target << '\n';
                start++;
            }
        }
    }

    cout << "Final closestSum: " << closestSum << '\n';

    return closestSum;

}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, target);
    cout << "Result: " << result << '\n';
    return 0;
}