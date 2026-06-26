class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto maxProfit = 0;
        auto currLowest = prices[0];
        auto currHighest = prices[0];
        for(auto p : prices) {
            currLowest = std::min(currLowest, p);

            maxProfit = std::max(p - currLowest, maxProfit);
        }
        return maxProfit;
    }
};
