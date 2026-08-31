class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // keep track of the highest temp so far from the back

        auto res = std::vector<int>(temperatures.size(), 0);
        stack<std::pair<int, int> > indices;
        indices.push({0, temperatures.front()});
        for (auto i = 1 ; i < temperatures.size(); ++i ){
            if (temperatures[i] > indices.top().second) { 
                while (not indices.empty() and indices.top().second < temperatures[i]){
                    auto diff = i - indices.top().first;
                    res[indices.top().first] = diff;
                    indices.pop();
                }


            }
                indices.push({i, temperatures[i]});
            
        }

        return res;



        // // brute force
        // auto res = std::vector<int>(temperatures.size(), 0);
        // for (auto i = 0; i < temperatures.size(); ++i) { 
        //     for(auto counter = i; counter < temperatures.size(); ++counter){ 
        //         if (temperatures[counter] > temperatures[i]) {
        //             res[i] = counter - i;
        //             break;
        //         }
        //     }
        // }
        // return res;
    }
};
