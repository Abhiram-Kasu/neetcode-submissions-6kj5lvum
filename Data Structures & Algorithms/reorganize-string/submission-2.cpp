class Solution {
public:
    string reorganizeString(string s) {
        //get a counter of all the strings with their frequencies
        // Priority queue of the frequencies, we then alternate between 
        // the highest and the second highest 

        std::unordered_map<char, size_t> freq{};

        for( auto c : s){
            freq[c]++;
        }
        std::priority_queue<std::tuple<size_t,char>> pq{};
        for(auto& [c, s] : freq){
            pq.push({s,c});
        }

        std::vector<char> temp{};
        

        auto hold_item = std::optional<std::tuple<size_t, char>>{}; 

        while(not pq.empty() or hold_item){
            //can either get the first item or the next, 

            if(hold_item and pq.empty()) return "";

            auto [freq, item] = pq.top();
            pq.pop();

            temp.push_back(item);
            freq-=1;
            if( hold_item ){

                pq.push(*hold_item);
                hold_item = nullopt;
            }

            if(freq >0)
                hold_item = {freq, item};
        }

        return string{temp.begin(), temp.end()};


    }
};