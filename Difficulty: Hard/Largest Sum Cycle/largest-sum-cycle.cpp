class Solution {
public:
    long long largestSumCycle(vector<int>& edge) {
        int n = edge.size();
        vector<int> visited(n, 0); // 0: unvisited, 1: visiting, 2: fully processed
        long long maxCycleSum = -1;

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                int curr = i;
                vector<int> currentPath;

                // Traverse until we hit a node that is already being visited or fully processed
                while (curr != -1 && visited[curr] == 0) {
                    visited[curr] = 1; // Mark as visiting (active path)
                    currentPath.push_back(curr);
                    curr = edge[curr];
                }

                // If we hit a node currently in the active path, a cycle is found
                if (curr != -1 && visited[curr] == 1) {
                    long long currentCycleSum = 0;
                    // Backtrack from the end of our current path to find the start of the cycle
                    for (int j = currentPath.size() - 1; j >= 0; --j) {
                        currentCycleSum += currentPath[j];
                        if (currentPath[j] == curr) {
                            break; // Reached the start node of the cycle
                        }
                    }
                    maxCycleSum = max(maxCycleSum, currentCycleSum);
                }

                // Mark all nodes in the current path traversal as fully processed
                for (int node : currentPath) {
                    visited[node] = 2;
                }
            }
        }

        return maxCycleSum;
    }
};
