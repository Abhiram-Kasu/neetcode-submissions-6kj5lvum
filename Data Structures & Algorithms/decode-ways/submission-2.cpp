class Solution {
public:
    std::unordered_map<size_t, int> dict{};
    auto brute(const string& s, size_t ptr) -> int {

        if(dict.contains(ptr)) return dict[ptr];
       // reached end -> found one valid decoding
        if (ptr == s.size()) return (dict[ptr] = 1);

        // cannot decode numbers starting with 0
        if (s[ptr] == '0') return (dict[ptr]=0);

        // take one digit
        int res = brute(s, ptr + 1);

        // take two digits if possible
        if (ptr + 1 < s.size()) {
            int num = (s[ptr] - '0') * 10 + (s[ptr + 1] - '0');

            if (num <= 26) {
                res += brute(s, ptr + 2);
            }
        }

        return (dict[ptr] = res);
    }
    int numDecodings(string s) {
        return brute(s,0);
    }
};
