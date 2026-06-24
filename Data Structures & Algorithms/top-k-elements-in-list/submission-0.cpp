class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //get the frequencies of all the items: 
        unordered_map<int, int> freq{};
        for ( auto i : nums ) { 
            freq[i]++;
        }

        // bucket sort
        auto buckets = std::vector<std::vector<int>>(nums.size()+1, std::vector<int>{});
        for( auto [ch, fre] : freq) {
            buckets[fre].push_back(ch);
        }
        vector<int> results{};
        auto counter = 0uz;
        for(int i = buckets.size() -1 ; i>= 0 ; i--) { 
            for( auto& item : buckets[i]){
                if(counter == k) return results;

                results.push_back(item);
                counter++;
            }
        }
        return results;
        
    }
};
