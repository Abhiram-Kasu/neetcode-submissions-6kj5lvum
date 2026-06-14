class Solution {
public:

    std::map<std::pair<int, int>, bool> dp_arr;
    auto dp(int startIndex , int len, const std::string& mainString, const std::unordered_set<std::string>& wordDict) -> bool { 
        if (startIndex >=mainString.length()) { 
            // we got to the end
            return true;
        }

        if(dp_arr.contains({startIndex, len})) return dp_arr[{startIndex, len}];

        auto currString = mainString.substr(startIndex, len);

        if (wordDict.contains(currString)){
            //remember that we can get here
            dp_arr[{startIndex, len}] = true;
            
            // have a choice to either add this or not, do both
            return /*add */ dp(startIndex + len, 0, mainString, wordDict) || 
                /*dont add*/ dp(startIndex, len+1, mainString, wordDict); 
        } else {
            if ( startIndex + len >= mainString.length()){
                //stuff left at end
                return false;
            }else { 
                //we cant get here
                dp_arr[{startIndex, len}] = false;

                // return dp of next increment;
                return dp(startIndex, len+1, mainString, wordDict);


            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set words ( wordDict.begin(), wordDict.end() );
        return dp(0,0,s, words);

    }


};
