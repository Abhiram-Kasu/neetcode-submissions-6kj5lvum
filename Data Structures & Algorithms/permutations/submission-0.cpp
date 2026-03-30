class Solution {
public:

    auto recurse(vector<int>& nums, vector<int> curr_list, std::set<size_t> available, vector<vector<int>>& res ) {
        if(available.size() <1){
            res.push_back(curr_list);
          return;  
        } 
        auto copy = auto(available);
        for(auto item: available){
            curr_list.push_back(nums[item]);
            copy.erase(item);
            recurse(nums, curr_list, copy, res);
            curr_list.pop_back();
            copy.insert(item);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        std::set<size_t> available;
        for(auto i{0uz}; i < nums.size(); i++){
            available.insert(i);
        }
        vector<int> curr;

        recurse(nums, curr, available, res);
        return res;
    }
};
