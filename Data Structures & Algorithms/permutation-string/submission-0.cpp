#include <ranges>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> counter{};
        for( auto item : s1) { 
            counter[item]++;
        }

        for(auto window : s2 | std::views::slide(s1.length()) ){
            //brute force
            std::unordered_map<char, int> fr{};
            for( auto item : window){
                fr[item]++;
            }
            if(fr == counter) return true;
        }

        return false;

    }
};
