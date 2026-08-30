class Solution {
public:
    int minCost(int n, int i, int d, int c) {
        // dp[x] stores the minimum cost to reach length x
        vector<long long> dp(n + 1, 0);

        // Base case: 1 character can only be obtained by insertion
        dp[1] = i;

        for (int x = 2; x <= n; ++x) {
            if (x % 2 == 0) {
                dp[x] = min(dp[x - 1] + i, dp[x / 2] + c);
            } else {
                dp[x] = min(dp[x - 1] + i, dp[(x + 1) / 2] + c + d);
            }
        }

        return dp[n];
    }
};
