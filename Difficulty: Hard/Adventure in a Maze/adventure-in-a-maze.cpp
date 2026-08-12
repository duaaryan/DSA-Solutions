class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        const int MOD = 1e9 + 7;
        
        // dp[i][j].first = totalPaths, dp[i][j].second = maxAdventure
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
        
        // Base case: Destination cell
        dp[n - 1][n - 1] = {1, grid[n - 1][n - 1]};
        
        // Iterate backward from the bottom-right to top-left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == n - 1 && j == n - 1) continue;
                
                int paths = 0;
                int max_adv = 0;
                
                // 1 means move Right only, 3 means Right or Down
                if ((grid[i][j] == 1 || grid[i][j] == 3) && j + 1 < n) {
                    if (dp[i][j + 1].first > 0) {
                        paths = (paths + dp[i][j + 1].first) % MOD;
                        max_adv = max(max_adv, dp[i][j + 1].second);
                    }
                }
                
                // 2 means move Down only, 3 means Right or Down
                if ((grid[i][j] == 2 || grid[i][j] == 3) && i + 1 < n) {
                    if (dp[i + 1][j].first > 0) {
                        paths = (paths + dp[i + 1][j].first) % MOD;
                        max_adv = max(max_adv, dp[i + 1][j].second);
                    }
                }
                
                // If a valid path to the destination exists from here
                if (paths > 0) {
                    dp[i][j] = {paths, max_adv + grid[i][j]};
                }
            }
        }
        
        return {dp[0][0].first, dp[0][0].second};
    }
};
