class Solution {
private:
    // Helper function to perform DFS and find Topological Sort
    void topoSort(int u, vector<pair<int, int>> adj[], vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                topoSort(v, adj, visited, st);
            }
        }
        st.push(u);
    }

public:
    vector<int> maxDistance(int V, int src, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<pair<int, int>> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // Step 2: Get the Topological Order using DFS
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topoSort(i, adj, visited, st);
            }
        }

        // Step 3: Initialize distances array
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        // Step 4: Process vertices in topological order
        while (!st.empty()) {
            int u = st.top();
            st.pop();

            // Only relax edges from reachable vertices
            if (dist[u] != INT_MIN) {
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (dist[u] + w > dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        return dist;
    }
};
