#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // Find the maximum pizza size to determine the upper bound of the DP array
        int max_size = std::max({s, m, l});
        int max_bound = x + max_size;

        // dp[i] will store the minimum cost to get at least area 'i'
        std::vector<int> dp(max_bound + 1, 1e9); // Using 1e9 to prevent overflow during addition

        // Base case: 0 cost to get 0 area
        dp[0] = 0;

        // Fill the DP table
        for (int i = 1; i <= max_bound; ++i) {
            if (i >= s) {
                dp[i] = std::min(dp[i], dp[i - s] + cs);
            }
            if (i >= m) {
                dp[i] = std::min(dp[i], dp[i - m] + cm);
            }
            if (i >= l) {
                dp[i] = std::min(dp[i], dp[i - l] + cl);
            }
        }

        // Find the minimum cost for any area >= x
        int min_cost = 1e9;
        for (int i = x; i <= max_bound; ++i) {
            min_cost = std::min(min_cost, dp[i]);
        }

        return min_cost;
    }
};
