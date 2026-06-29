class Solution {
public:
//

    vector<vector<int>> memo;

    int dp(vector<int>& nums, int i, int prev) {
        if (i == nums.size()) return 0;

        if (memo[i][prev + 1] != -1)
            return memo[i][prev + 1];

        int skip = dp(nums, i + 1, prev);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + dp(nums, i + 1, i);
        }

        return memo[i][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        memo.assign(nums.size(), vector<int>(nums.size() + 1, -1));
        return dp(nums, 0, -1);
    }
};
