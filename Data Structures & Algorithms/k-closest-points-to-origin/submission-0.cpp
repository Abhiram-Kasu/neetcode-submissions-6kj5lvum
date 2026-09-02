class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        std::priority_queue<std::pair<int, int>,        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>> pq{};
        auto counter = 0;
        for(auto& point : points){
            auto distance_sqrd = point[0] * point[0] + point[1] * point[1];
            pq.push({distance_sqrd,counter++ });
        }
        auto temp = vector<vector<int>> {};
        for(auto i = 0; i < k; ++i){
            temp.push_back(std::move(points[pq.top().second]));
            pq.pop();
        }
        return temp;
        
    }
};
