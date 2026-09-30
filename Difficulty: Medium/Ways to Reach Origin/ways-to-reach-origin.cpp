class Solution {
public:
    int ways(int x, int y) {
        int MOD = 1e9 + 7;

        // dp[i][j] stores the number of paths from (i, j) to (0, 0)
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        // Base cases: if y == 0, there is only 1 path (always move left)
        for (int i = 0; i <= x; i++) {
            dp[i][0] = 1;
        }

        // Base cases: if x == 0, there is only 1 path (always move down)
        for (int j = 0; j <= y; j++) {
            dp[0][j] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

        return dp[x][y];
    }
};
