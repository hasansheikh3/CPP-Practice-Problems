/*

Given an integer array of size `n`, return the element which appears more than `n/2` times. Assume that the input always contain the majority element.

Input : [2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2]
Output: 2

Input : [1, 3, 1, 1]
Output: 1

Link : https://www.techiedelight.com/?problem=MajorityElement

 **************PLEASE TRY TO SOLVE THIS PROBLEM ON YOUR OWN BEFORE LOOKING AT THE SOLUTION***************

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int majorityElement(vector<int>&nums)
{
    /*
    1. Create a map to store the count of each element
    2. Declare a variable max_count to store the maximum count of an element, and max_element to store the element with the maximum count
    3. Iterate over the vector and update the count of each element in the map
    4. Return the element with the highest count
    Time complexity: O(n)
    Space complexity: O(n)

    Brain teaser: What if the input is sorted? Can you do better than O(n) Time complexity?
    Brain teaser: Can you do it in O(1) space? Hint: Boyer-Moore Majority Vote algorithm
    */

    // edge case
    if (nums.size() == 0)
    {
        return -1;
    }

    if (nums.size() == 1)
    {
        return nums[0];
    }

    map<int,int> seen;
    int max_count = 0;
    int max_element = 0;

    for (int i=0; i<nums.size();i++)
    {
        if (seen.find(nums[i])==seen.end())
        {
            seen[nums[i]] = 1;
        }
        else
        {
            seen[nums[i]]+=1;
        }
    }

   
    for (auto it = seen.begin(); it != seen.end(); it++)
    {
        if (it->second > max_count)
        {
            // it->first is the key, it->second is the value, so if value is greater than max_count, then update max_count and max_element
            max_count = it->second;
            max_element = it->first;
        }
    }

    return max_element;

}


int main()
{
    // vector<int> nums = {2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2};
    // vector<int> nums = {1, 3, 1, 1};
    vector<int> nums = {1};
    cout << majorityElement(nums) << endl;
    return 0;
}