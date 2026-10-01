#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        int n = duration.size();

        // Step 1: Build adjacency list and compute in-degrees
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (const auto& dep : dependencies) {
            int u = dep[0];
            int v = dep[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Step 2: Initialize queue with nodes having 0 in-degree
        queue<int> q;
        vector<int> maxTime(n, 0);

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                maxTime[i] = duration[i];
            }
        }

        // Step 3: Process the nodes
        int visitedNodes = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visitedNodes++;

            for (int v : adj[u]) {
                // The minimum start time for v is the max completion time among all its dependencies
                maxTime[v] = max(maxTime[v], maxTime[u] + duration[v]);

                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Step 4: If visited nodes != total nodes, there's a cycle
        if (visitedNodes != n) {
            return -1;
        }

        // Step 5: Find the maximum time required overall
        int minTotalTime = 0;
        for (int i = 0; i < n; i++) {
            minTotalTime = max(minTotalTime, maxTime[i]);
        }

        return minTotalTime;
    }
};
