class Solution {
public:
    int cntSubsets(vector<int>& arr, int l, int r) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        // 1. Calculate the frequency of each element up to N.
        // Elements greater than N cannot affect a MEX value <= N.
        vector<int> freq(n + 1, 0);
        for (int x : arr) {
            if (x <= n) {
                freq[x]++;
            }
        }

        // 2. Precompute powers of 2 modulo 10^9 + 7
        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        long long totalSubsets = 0;

        // waysRequired stores the product of (2^freq[i] - 1) for all i < mex
        long long waysRequired = 1; 
        int usedElements = 0;

        // Iterate through all possible MEX values up to r
        for (int mex = 0; mex <= r; mex++) {
            // Count elements that are strictly greater than the current mex
            int greaterElements = n - usedElements - freq[mex];

            // Subsets with exactly this MEX
            long long ways = (waysRequired * pow2[greaterElements]) % MOD;

            // Add to total if the current MEX lies in the requested [l, r] range
            if (mex >= l) {
                totalSubsets = (totalSubsets + ways) % MOD;
            }

            // Update waysRequired for the next MEX value.
            // The current mex element must appear at least once in future subsets.
            long long currentWays = (pow2[freq[mex]] - 1 + MOD) % MOD;
            waysRequired = (waysRequired * currentWays) % MOD;

            // If a required element does not exist at all, no larger MEX is possible
            if (waysRequired == 0) {
                break;
            }

            usedElements += freq[mex];
        }

        return totalSubsets;
    }
};
