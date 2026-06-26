class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Keep track of the min height from the left and the right and then 
        auto calcArea = [&](auto index1, auto index2) { 
            auto height = std::min(heights[index1], heights[index2]);
            return height * (index2-index1);
        } ;

        auto left = 0;
        auto right = heights.size()-1;
        auto currMax = calcArea(left, right);

        while(left < right) { 
            currMax = std::max(currMax, calcArea(left,right));
            //move the smaller item
            if (heights[left] < heights[right]) { 
                //move the left in
                left++;
            }else { 
                // move right in
                right--;
            }
        }

        return currMax;
    }
};
