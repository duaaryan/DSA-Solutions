class Solution {
public:
    // Direction vectors for moving up, down, left, and right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(int x, int y, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& dp) {
        // If already calculated, return the cached result
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int max_len = 1; // Base case: a single cell has a path length of 1

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check boundaries and ensure the neighbor's value is strictly greater
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[x][y]) {
                max_len = max(max_len, 1 + dfs(nx, ny, matrix, n, m, dp));
            }
        }

        // Memoize and return the result for the current cell
        return dp[x][y] = max_len;
    }

    int longIncPath(vector<vector<int>>& matrix, int n, int m) {
        if (n == 0 || m == 0) return 0;

        // Initialize memoization table with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int longestPath = 0;

        // Compute the longest path starting from each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longestPath = max(longestPath, dfs(i, j, matrix, n, m, dp));
            }
        }

        return longestPath;
    }
};
