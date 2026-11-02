#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // DSU structures
    vector<int> parent;
    vector<int> sz;

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

public:
    vector<int> maximumWeight(int n, vector<vector<int>>& edges, vector<int>& queries) {
        // Initialize DSU for 1-based indexing nodes
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Sort edges based on their weights (u, v, weight)
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        // Store queries along with their original indices to place answers correctly
        int q = queries.size();
        vector<pair<int, int>> sorted_queries(q);
        for (int i = 0; i < q; i++) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> ans(q);
        int current_paths = 0;
        int edge_idx = 0;
        int num_edges = edges.size();

        // Process each query offline
        for (int i = 0; i < q; i++) {
            int max_weight = sorted_queries[i].first;
            int q_idx = sorted_queries[i].second;

            // Add all edges that have a weight less than or equal to the current query weight
            while (edge_idx < num_edges && edges[edge_idx][2] <= max_weight) {
                int u = edges[edge_idx][0];
                int v = edges[edge_idx][1];

                int root_u = find_set(u);
                int root_v = find_set(v);

                // If they belong to different components, merge them
                if (root_u != root_v) {
                    current_paths += sz[root_u] * sz[root_v];

                    // Union by size
                    if (sz[root_u] < sz[root_v]) {
                        swap(root_u, root_v);
                    }
                    parent[root_v] = root_u;
                    sz[root_u] += sz[root_v];
                }
                edge_idx++;
            }

            ans[q_idx] = current_paths;
        }

        return ans;
    }
};
