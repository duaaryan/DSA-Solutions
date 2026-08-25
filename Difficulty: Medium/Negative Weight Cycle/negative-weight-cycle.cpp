class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>>& edges) {
        // Initialize all distances to 0 to handle disconnected components
        vector<int> dist(n, 0);

        // Relax all edges V - 1 times
        for (int i = 0; i < n - 1; i++) {
            for (const auto& it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // N-th relaxation to check for negative weight cycle
        for (const auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] + wt < dist[v]) {
                return 1; // Negative cycle detected
            }
        }

        return 0; // No negative cycle
    }
};


