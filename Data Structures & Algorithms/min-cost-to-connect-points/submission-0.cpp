class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        vector<tuple<int,int,int>> edges;

        // build all edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        // sort edges by cost
        sort(edges.begin(), edges.end());

        int totalCost = 0;
        int edgesUsed = 0;

        for (auto& [cost, u, v] : edges) {
            int pu = find(u);
            int pv = find(v);

            if (pu != pv) {
                parent[pu] = pv;
                totalCost += cost;
                edgesUsed++;

                if (edgesUsed == n - 1) break;
            }
        }

        return totalCost;
    }
};