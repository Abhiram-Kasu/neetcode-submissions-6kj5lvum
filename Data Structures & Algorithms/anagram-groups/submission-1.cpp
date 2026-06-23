class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const auto& str : strs) {
            array<int,26> freq{};
            for(char c : str) {
                freq[c - 'a']++;
            }
            string key;
            for(int count : freq) {
                key += "#" + to_string(count);
            }

            groups[key].push_back(str);
        }

        vector<vector<string>> res;
        for(auto& [_, group] : groups) {
            res.push_back(std::move(group));
        }

        return res;
    }
};