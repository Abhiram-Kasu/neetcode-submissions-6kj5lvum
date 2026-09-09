class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::unordered_set<char> operators{ '+', '-', '/', '*'};
        auto st = std::stack<int>{};
        for(auto& item : tokens) { 
            if (item.length() == 1 and operators.contains(item[0])) { 
                auto item1 = st.top();
                st.pop();
                auto item2 = st.top();
                st.pop();

                switch (item[0]) { 
                    case '+': 
                        st.push(item1 + item2);
                        break;
                    case '-':
                        st.push(item2-item1);
                        break;
                    case '/':
                        st.push(item2 / item1);
                        break;
                    case '*':
                        st.push(item1*item2);
                        break;
                    default:
                }
            }else { 
                st.push(stoi(item));
            }
        }
        return st.top();
        
    }
};
