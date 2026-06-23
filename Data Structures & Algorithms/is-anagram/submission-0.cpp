class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, size_t> map1;
        std::unordered_map<char, size_t> map2;
        for(auto c : s) { 
            map1[c]++;
        }
        for(auto c : t) { 
            map2[c]++;
        }

        return map2 == map1;

    }
};
