class Solution {
    bool solve(int i, int remaining, vector<int>& arr,
               vector<vector<int>>& dp) {
        if (remaining == 0) return true;
        if (i == arr.size() || remaining < 0) return false;

        if (dp[i][remaining] != -1)
            return dp[i][remaining];

        bool take = solve(i + 1, remaining - arr[i], arr, dp);

        // Take se mil gaya toh skip check karne ki zaroorat nahi
        if (take) return dp[i][remaining] = 1;

        bool skip = solve(i + 1, remaining, arr, dp);

        return dp[i][remaining] = skip;
    }

public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
        return solve(0, k, arr, dp);
    }
};