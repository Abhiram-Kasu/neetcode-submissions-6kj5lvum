class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto start = 0uz;
        auto end = numbers.size()-1;
        auto curr = numbers[start] + numbers[end];
        while(curr != target) { 
            if (curr < target) { 
                // increase the start
                start++;
            }else { 
                end--;
            }
            curr = numbers[start] + numbers[end];
        }

        return {int(start)+1, int(end)+1};
    }
};
