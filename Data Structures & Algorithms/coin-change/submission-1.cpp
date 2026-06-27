class Solution {
public:
    vector<int64_t> dpArr;

    auto solve(vector<int>& coins,
               uint64_t amount,
               uint64_t currAmount = 0,
               uint64_t currCoins = 0)
    {
        if (currAmount > amount)
            return;

        // already reached here with fewer coins
        if (dpArr[currAmount] != -1 &&
            dpArr[currAmount] <= currCoins)
            return;

        dpArr[currAmount] = currCoins;

        for (int coin : coins) {
            solve(coins,
                  amount,
                  currAmount + coin,
                  currCoins + 1);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        dpArr.assign(amount + 1, -1);

        solve(coins, amount);

        return dpArr[amount];
    }
};
