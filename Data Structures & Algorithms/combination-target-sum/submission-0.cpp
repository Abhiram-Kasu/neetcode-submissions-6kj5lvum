class Solution {
public:

    auto recurse(vector<int>& nums, size_t left_barrier, vector<int>& curr_list, size_t curr_sum, vector<vector<int>>& subsets, size_t target){
        if(curr_sum == target){
            subsets.push_back(auto(curr_list));
        }
        if( curr_sum > target){
            return;
        }


        
        for(auto i{ left_barrier }; i < nums.size() ;  i++){
            curr_list.push_back(nums[i]);
            recurse(nums, i, curr_list, curr_sum + nums[i], subsets, target);
            curr_list.pop_back();
        }


    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<int> curr_list;
        std::vector<vector<int>> subsets;

        recurse(nums,0,  curr_list, 0, subsets, target);

        return subsets;
    }   
};
