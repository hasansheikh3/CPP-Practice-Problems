 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;   
    
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3)
        {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int start = i + 1;
                int end = n - 1;
                while (start < end)
                {
                    int sum = nums[i] + nums[start] + nums[end];
                    if (sum == 0)
                    {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[start]);
                        tmp.push_back(nums[end]);
                        result.push_back(tmp);
                        while (start < end && nums[start] == nums[start + 1])
                        {
                            start++;
                        }
                        while (start < end && nums[end] == nums[end - 1])
                        {
                            end--;
                        }
                        start++;
                        end--;
                    }
                    else if (sum < 0)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }
            }
        }
        return result;        
    }

    int main()
    {
        vector<int> nums = {-1,0,1,2,-1,-4};
        // vector<int> nums = {1, 3, 5, 8, 9};
        // int target = 4;
        vector<vector<int>> result = threeSum(nums);
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return 0;
    }