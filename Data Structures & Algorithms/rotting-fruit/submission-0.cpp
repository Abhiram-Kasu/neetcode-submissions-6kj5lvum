class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     auto curr_time{0};
     std::vector<std::pair<int,int>> rotten{};
     for(auto i{0}; i < grid.size(); i ++ ){
        for(auto j{ 0}; j < grid[0].size(); j ++ ) {
            if(grid[i][j] == 2){
                //add to bfs queue;
                rotten.push_back({i,j}); 
            }
        }
     }


     while(not rotten.empty()){

        //go through entire level
        auto temp = decltype(rotten){};
        auto rotted_this_round = false;
        for(auto [i,j] : rotten){
            if(i+1 < grid.size() and grid[i+1][j] == 1){
            //rot this fresh fruit and add to queue
            temp.push_back({i+1, j});
            grid[i+1][j] = 2;
            rotted_this_round = true;
        }
        if(i-1 >= 0 and grid[i-1][j] == 1){
            //rot this fresh fruit and add to queue
            temp.push_back({i-1, j});
            grid[i-1][j] = 2;
            rotted_this_round = true;

        }if(j+1 < grid[0].size() and grid[i][j+1] == 1){
            //rot this fresh fruit and add to queue
            temp.push_back({i, j+1});
            grid[i][j+1] = 2;
            rotted_this_round = true;

        }if(j-1 >= 0 and grid[i][j-1] == 1){
            //rot this fresh fruit and add to queue
            temp.push_back({i, j-1});
            grid[i][j-1] = 2;
            rotted_this_round = true;
        }
        }

        rotten = std::move(temp);

        
        if(rotted_this_round) curr_time++;
     }


     //check if any remain

     for(auto& row: grid){
        for(auto item : row){
            if(item == 1){
                return -1;
            }
        }
     }
     return curr_time;

    }


};
