/*

Given an unsorted integer array, find a pair with the given sum in it.

• Each input can have multiple solutions. The output should match with either one of them.

Input : nums[] = [8, 7, 2, 5, 3, 1], target = 10
Output: (8, 2) or (7, 3)

• The solution can return pair in any order. If no pair with the given sum exists, the solution should return the pair (-1, -1).

Input : nums[] = [5, 2, 6, 8, 1, 9], target = 12
Output: (-1, -1)

link : https://www.techiedelight.com/?problem=TwoSum

*/

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

pair<int,int> findPair(vector<int> const &nums, int target)
	{
		// Write your code here...
		pair<int,int> result;
		if (nums.size() <= 1)
		{
			result = make_pair(-1,-1);
			return result;
		}
		
		int compliment=0;
		map<int,int> pos;
		
		for (int i=0; i<nums.size();i++)
		{
			compliment = target - nums[i];
			if (pos.find(compliment) == pos.end())
			{
				pos[nums[i]] = i;
			}
			else
			{
				result = make_pair(compliment,nums[i]);
				return result;
			}
		}
		result = make_pair(-1,-1);
		return result;
	}


int main()
{
    pair<int,int> result;
    vector<int> inp = {6,3,2,2,1};
    result = findPair(inp,10);

    cout << "Pair : (" << to_string(result.first) + "," + to_string(result.second) + ")";
    return 0;
}