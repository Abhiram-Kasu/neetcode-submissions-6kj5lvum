class Solution {

    struct car{ 
        int position, speed;
    };
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //if a fast car is behind a slow car, then those two cars will become part of a fleet,
        // we need to go through the slowest speeds, and 
        vector<car> cars{};
        for(auto i{0uz}; i < position.size() ; i ++){
            cars.push_back({position[i], speed[i]});
        }

        // sort the vec of cars based on position
        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
        return a.position > b.position; 
    });

    auto calc = [target](auto currPos, auto currSpeed) {
        return (target-currPos) / static_cast<float>(currSpeed);
    };

    std::map<float, int> groups;
    auto curr_limiting_time = calc(cars[0].position, cars[0].speed);
    groups[curr_limiting_time]++;
    for(auto i = 1uz; i < cars.size(); i ++){
        auto curr_time = calc(cars[i].position, cars[i].speed);
        if(curr_time < curr_limiting_time){
            //add to fleet
            groups[curr_limiting_time]++;
        }else{
            //make new fleet from ts
            curr_limiting_time = curr_time;
            groups[curr_time]++;
        }
    }
    return groups.size();
    }
    
};
