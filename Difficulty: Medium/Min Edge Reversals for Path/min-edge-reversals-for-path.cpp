class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
            // Build the adjacency list: pair<neighbor, weight>
            vector<vector<pair<int, int>>> adj(n + 1);
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back({v, 0}); // Original edge costs 0
                adj[v].push_back({u, 1}); // Reversed edge costs 1
            }

            // Distance array initialized to infinity
            vector<int> dist(n + 1, 1e9);
            deque<int> dq;

            // Start from the source node
            dist[src] = 0;
            dq.push_back(src);

            while (!dq.empty()) {
                int u = dq.front();
                dq.pop_front();

                // If we reached the destination, we can return early
                if (u == dst) {
                    return dist[dst];
                }

                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;

                    // Relaxation step
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;

                        // 0-1 BFS logic: push to front if weight is 0, back if 1
                        if (weight == 0) {
                            dq.push_front(v);
                        } else {
                            dq.push_back(v);
                        }
                    }
                }
            }

            // If dst is unreachable, return -1
            return dist[dst] == 1e9 ? -1 : dist[dst];
        }
    };