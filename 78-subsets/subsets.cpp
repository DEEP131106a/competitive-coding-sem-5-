class Solution {
public:

    void solve(int i,vector<int>& nums,vector<int>& subset,vector<vector<int>>& result)
    {
        // Base case
        if(i == nums.size())
        {result.push_back(subset);
    return;
        }

// Include current element
 subset.push_back(nums[i]);
solve(i + 1, nums, subset, result);

// Backtrack
subset.pop_back();

// Exclude current element
solve(i + 1, nums, subset, result);
    }

 vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> subset;

        solve(0, nums, subset, result);

        return result;
    }
};