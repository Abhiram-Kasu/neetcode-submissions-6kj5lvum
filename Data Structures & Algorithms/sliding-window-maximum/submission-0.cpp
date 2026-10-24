class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res{};
        std::multiset<int> sorted_items{};
        // deal with current window
        for (auto i{0}; i < k; ++i) { 
            sorted_items.insert(nums[i]);
        }
        //push the biggest item
        res.push_back(*sorted_items.rbegin());
        auto start = 0;
        auto end = start+k;

        while (end < nums.size()){ 
            //get the value to remove
            auto value_to_remove = nums[start];
            // remove that value from the multiset
            sorted_items.erase(sorted_items.find(value_to_remove));

            //add the new value
            sorted_items.insert(nums[end]);

            //push the new greatest value
            res.push_back(*sorted_items.rbegin());

            //increment start and end

            start++;
            end++;
        }
        return res;
    }
};
