class Solution {
public:



    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> items {nums.begin(), nums.end()};
        auto max_len = 0uz;
        for(auto i : items) { 
            if (not items.contains(i-1)) { 
                //head, start counting
                auto counter = 0uz;
                
                while(items.contains(i)){
                    i++;
                    counter++;
                }
                max_len = std::max(max_len, counter);
            }
        }
        return max_len;
    }
};
