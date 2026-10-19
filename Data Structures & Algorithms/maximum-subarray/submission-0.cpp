class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto curr_sum = nums[0];
        auto best_sum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            curr_sum = std::max(
                curr_sum + nums[i], // Extend the previous subarray
                nums[i]             // Start a new subarray here
            );

            best_sum = std::max(best_sum, curr_sum);
        }

        return best_sum;
    }
};