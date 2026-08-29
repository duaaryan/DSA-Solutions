class Solution {
public:
    int countSubsequences(string s, int n) {
        int len = s.length();
        int MOD = 1e9 + 7;

        // dp[r] stores the count of subsequences that give remainder 'r' modulo n
        vector<long long> dp(n, 0);

        for (int i = 0; i < len; i++) {
            int digit = s[i] - '0';
            // Create a temporary array to store updates for the current digit
            vector<long long> next_dp = dp;

            // 1. Extend existing subsequences with the current digit
            for (int r = 0; r < n; r++) {
                if (dp[r] > 0) {
                    int next_rem = (r * 10 + digit) % n;
                    next_dp[next_rem] = (next_dp[next_rem] + dp[r]) % MOD;
                }
            }

            // 2. Start a new single-digit subsequence with the current digit
            int self_rem = digit % n;
            next_dp[self_rem] = (next_dp[self_rem] + 1) % MOD;

            // Update the main DP array for the next iteration
            dp = next_dp;
        }

        // Return the number of subsequences completely divisible by n (remainder 0)
        return dp[0];
    }
};