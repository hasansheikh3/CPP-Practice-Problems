/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>> &nums)
{
    vector<vector<int>> tmp(nums[0].size(), vector<int>(nums.size()));

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            tmp[j][nums.size() - 1 - i] = nums[i][j];
        }
    }

    nums = tmp;
}

int main()
{
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(nums);
    for (int i=0; i<nums.size();i++)
    {
        for (int j=0; j<nums[i].size();j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}