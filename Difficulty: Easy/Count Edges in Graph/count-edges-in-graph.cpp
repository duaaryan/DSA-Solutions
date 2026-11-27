class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        int totalDegree = 0;

        // Sum the number of neighbors for every vertex
        for (int i = 0; i < adj.size(); i++) {
            totalDegree += adj[i].size();
        }

        // Each undirected edge is counted twice, so divide by 2
        return totalDegree / 2;
    }
};
