class Solution {
public:

    std::vector<int> parents{};

    auto find(int item) -> int{
        if(parents[item] != item){
            parents[item] = find(parents[item]);
        }
        return parents[item];
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        //UF

        for(auto i{0}; i < n; i ++){
            parents.push_back(i);
        }
        auto components = n;

        for (auto& e : edges) {
            int p1 = find(e[0]);
            int p2 = find(e[1]);

            if (p1 != p2) {
                parents[p1] = p2;
                components--;
            }
        }

        return components;
    }
};
