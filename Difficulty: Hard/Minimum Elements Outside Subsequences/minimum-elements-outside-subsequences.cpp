class Solution {
    int dp[101][102][102];

    int solve(int idx, int last_inc, int last_dec, vector<int>& arr) {
        // Base case: processed all elements
        if (idx == arr.size()) {
            return 0;
        }

        // Return memoized result if already calculated
        if (dp[idx][last_inc][last_dec] != -1) {
            return dp[idx][last_inc][last_dec];
        }

        // Choice 1: Skip the current element
        int res = solve(idx + 1, last_inc, last_dec, arr);

        // Choice 2: Add to the strictly increasing subsequence
        if (arr[idx] > last_inc) {
            res = max(res, 1 + solve(idx + 1, arr[idx], last_dec, arr));
        }

        // Choice 3: Add to the strictly decreasing subsequence
        if (arr[idx] < last_dec) {
            res = max(res, 1 + solve(idx + 1, last_inc, arr[idx], arr));
        }

        return dp[idx][last_inc][last_dec] = res;
    }

public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        // Initialize DP table with -1
        memset(dp, -1, sizeof(dp));

        // Find the maximum number of elements we can include
        // last_inc starts at 0, last_dec starts at 101
        int max_included = solve(0, 0, 101, arr);

        // Unused elements = Total elements - Maximum included elements
        return n - max_included;
    }
};
