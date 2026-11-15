class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto cur_ptr = nums[0];
        while(true) { 
            if ( nums[cur_ptr] == 0) { 
                // we have already come to this index already, so the index that got us here is a duplicate
                return cur_ptr;
            }
            const auto temp = nums[cur_ptr];
            nums[cur_ptr] = 0;
            cur_ptr = temp;
        }

    }
};
