class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        // -1 = unknown, 0 = false, 1 = true
        vector<vector<int>> memo(
            s1.size() + 1, vector<int>(s2.size() + 1, -1)
        );

        auto dp = [&](auto&& self, size_t i, size_t j) -> bool {
            if (i == s1.size() && j == s2.size()) return true;

            int& result = memo[i][j];
            if (result != -1) return result;

            size_t k = i + j;
            bool possible =
                (i < s1.size() && s1[i] == s3[k] && self(self, i + 1, j)) ||
                (j < s2.size() && s2[j] == s3[k] && self(self, i, j + 1));

            result = possible;
            return possible;
        };

        return dp(dp, 0, 0);
    }
};