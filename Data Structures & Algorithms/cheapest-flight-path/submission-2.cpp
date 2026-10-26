class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // (total_cost, airport, flights_used)
        using State = tuple<int, int, int>;

        vector<vector<pair<int, int>>> graph(n);

        for (const auto& f : flights) {
            graph[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, src, 0});

        vector<vector<int>> dist(
            n, vector<int>(k + 2, INT_MAX)
        );
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, airport, used] = pq.top();
            pq.pop();

            if (airport == dst)
                return cost;

            if (used == k + 1)
                continue;

            for (auto [next, price] : graph[airport]) {
                int newCost = cost + price;

                if (newCost < dist[next][used + 1]) {
                    dist[next][used + 1] = newCost;
                    pq.push({newCost, next, used + 1});
                }
            }
        }

        return -1;
    }
};