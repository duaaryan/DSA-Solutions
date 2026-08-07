class Solution {
private:
    // Helper function to perform Depth First Search
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        
        // Critical condition: Not enough total edges to connect n vertices
        if (m < n - 1) {
            return -1;
        }

        // Step 1: Build the adjacency list representation of the graph
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Traverse the graph to find the number of connected components
        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }

        // Step 3: Minimum operations required is (components - 1)
        return components - 1;
    }
};
