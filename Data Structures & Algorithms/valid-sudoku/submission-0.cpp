class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //can optimize with bit array??vector of bool?? 
        vector<vector<vector<bool>>> boxes(3, vector(3, vector(10, false)));
        // for each row
        vector<vector<bool>> rows(9, vector(10,false));
        vector<vector<bool>> cols(9, vector(10,false));


        for(auto x = 0; x < board.size(); ++x) { 
            for( auto y = 0; y < board.size(); ++y) {
                auto row = x;
                auto col = y;
                if ( board[row][col] == '.') continue;

                // get corresponding box
                auto box_x = x /3;
                auto box_y = y/3;

                auto digit = board[row][col] - '0';

                //check if digit already exists in box: 
                if(boxes[box_x][box_y][digit]){
                    return false;
                }
                boxes[box_x][box_y][digit] = true;

                if(rows[row][digit]){
                    return false;
                }
                rows[row][digit] = true;

                if(cols[col][digit]){
                    return false;
                }
                cols[col][digit] = true;
            }
        }
        return true;



        // iterate through each x,y in the board
        // add the item to its corresponding box set or
        // corresponding row + col, and if theres a duplicate 
        // then we are coooked
        for(auto i = 0; i < 9; ++i){
            auto start_x = (i* 3) % 9;
            // i = 0,1,2 => 0
            // i = 3, 4, 5 => 1
            auto start_y = i / 3;


            // check the current box: 
            {
                std::unordered_set<char> curr_set;
                for(auto x = start_x; x < start_x + 3; ++x) {
                    for (auto y = start_y; y < start_y + 3; ++y) {
                        
                    }
                }
            }
        }
    }
};
