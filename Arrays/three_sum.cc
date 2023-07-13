 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;   
    
vector<vector<int>> threeSum(vector<int>& nums) {
        int a=0;
        int b=1;
        int c=2;
        int n=nums.size();
        vector<vector<int>> result;
        vector<int> temp;

        if (n<=3)
        {
            if (n<3) return result;
            if (nums[0] + nums[1] + nums[2] != 0)
            {
                return result;
            }
            result.push_back(nums);
            return result;
        }

        

        while (c<=n)
        {
            if (nums[a] + nums[b] + nums[c] == 0)
            {
                temp.push_back(nums[a]);
                temp.push_back(nums[b]);
                temp.push_back(nums[c]);
            }

            a++;
            b++;
            c++;
            result.push_back(temp);
            temp.clear();
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