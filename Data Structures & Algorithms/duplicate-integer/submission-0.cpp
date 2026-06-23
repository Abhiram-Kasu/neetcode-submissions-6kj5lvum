class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for(auto i : nums) { 
            if (set.contains(i)) { 
                return true; 
            }
            set.insert(i);
        }
        return false;
    }
};