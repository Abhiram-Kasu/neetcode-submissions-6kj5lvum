class Solution {
public:
    std::vector<std::optional<int>> dp_arr{};

    int dp(vector<int>& nums, int start = 0) {
        if (start >= nums.size()) {
            return 0;
        }

        if (dp_arr[start]) {
            return *dp_arr[start];
        }

        return *(dp_arr[start] = std::max(
            dp(nums, start + 1),                 
            nums[start] + dp(nums, start + 2)    
        ));
    }

    int rob(vector<int>& nums) {
        dp_arr.resize(nums.size(), std::nullopt);
        return dp(nums);
    }
};