/*

Given an integer array, find a pair with the maximum product in it.

Each input can have multiple solutions. The output should match with either one of them.

Input : [-10, -3, 5, 6, -2]
Output: (-10, -3) or (-3, -10) or (5, 6) or (6, 5)

Input : [-4, 3, 2, 7, -5]
Output: (3, 7) or (7, 3)

If no pair exists, the solution should return the pair (-1, -1).

Input : [1]
Output: (-1, -1)

link : https://www.techiedelight.com/?problem=MaximumProductPair

 **************PLEASE TRY TO SOLVE THIS PROBLEM ON YOUR OWN BEFORE LOOKING AT THE SOLUTION***************

*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

pair<int,int> findMaxProductUsingSorting(vector<int> &nums)
{
    /*
    1. Sort the Array in increasing order.
    2. If all elements are positive, return the pair of last two elements.
    3. If some elements are negative, return the pair of first two and last two elements.
    Time Complexity : O(n*logn)

    Mind Teaser : What if prod1 == prod2 ??
    */

    // edge case
    if (nums.size() <= 1)
    {
        pair<int,int> result = make_pair(-1,-1);
        return result;
    }

    pair<int,int> result;
    int n=nums.size();
    sort(nums.begin(),nums.end());

    int n1,n2;

    int prod1 = nums[0] * nums[1]; // If array contains negative elements
    int prod2 = nums[n-1] * nums[n-2];  // If array contains only positive elements

    if (prod1 > prod2)
    {
        // This means Array indeed contained negative elements
        result = make_pair(nums[0],nums[1]);
        return result;
    }

    result = make_pair(nums[n-1],nums[n-2]); // Array contained only positive elements
    return result;
    
}

pair<int,int> findMaxProduct(vector<int> &nums)
{
    /*
    1. Declare four variables 
    2. Iterate over the array and update four variables, max positive, second max positive, max negative, second max negative.
    3. Return the pair of max1 and max2.

    Time Complexity : O(n)
    
    */

    // edge case
    if (nums.size() <= 1)
    {
        pair<int,int> result = make_pair(-1,-1);
        return result;
    }

    pair<int,int> result;
    int n=nums.size();
    int pmax1=0, pmax2=0, nmax1=0, nmax2=0; 

    for (int i=0; i<n; i++)
    {
        if (nums[i] > pmax1)
        {
            // pmax1 is the largest element
            pmax2 = pmax1;
            pmax1 = nums[i];
        }
        else if (nums[i] > pmax2)
        {
            // pmax2 is the second largest element
            pmax2 = nums[i];
        }

        if (nums[i] < 0 && abs(nums[i]) > abs(nmax1))
        {
            // nmax1 is the largest negative element
            nmax2 = nmax1;
            nmax1 = nums[i];
        }
        else if (nums[i] < 0 && abs(nums[i]) > abs(nmax2))
        {
            // nmax2 is the second largest negative element
            nmax2 = nums[i];
        }
    }

    if (pmax1 * pmax2 > nmax1 * nmax2)
    {
        // This means Array contained positive elements
        result = make_pair(pmax1,pmax2);
        return result;
    }

    result = make_pair(nmax1,nmax2); // Array contained negative elements
    return result;
}


int main()
{
    pair<int,int> result;
    // vector<int> inp = {6,3,4,5,7};
    vector<int> inp = {-10, -4, 5, 6, -2};
    result = findMaxProduct(inp);
    cout << "The pair is : " << result.first << " " << result.second << "\n";
    return 0;

}