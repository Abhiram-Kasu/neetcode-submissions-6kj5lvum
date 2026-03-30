class Solution {

    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void visit(string airport) {
        auto& destinations = adj[airport];
        while (!destinations.empty()) {
            string next = destinations.top();
            destinations.pop(); 
            visit(next);
        }

        result.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) {
            adj[t[0]].push(t[1]);
        }
        
        visit("JFK");
        
        reverse(result.begin(), result.end());
        return result;
    }
};