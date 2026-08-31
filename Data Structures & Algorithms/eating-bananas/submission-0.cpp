class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto low = 1;
        auto high = *std::max_element(piles.begin(), piles.end());

        while (low < high) {
            auto middle = low + (high - low) / 2;

            auto time = 0ull;

            for (auto pile : piles) {
                time += (pile + middle - 1) / middle;
            }

            if (time <= h) {
                // This speed works, so try something slower.
                high = middle;
            } else {
                // Too slow, need to increase the speed.
                low = middle + 1;
            }
        }

        return low;
    }
};