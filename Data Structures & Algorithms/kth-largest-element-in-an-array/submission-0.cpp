class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto q = std::priority_queue<int, std::vector<int>, std::greater<int>>();


        for(auto num : nums){
            
            if(q.size() < k){
                q.push(num);
            }
            else if(num > q.top()){
                q.pop();
                q.push(num);
            }
        }

      
        
        return q.top();
    }
};
