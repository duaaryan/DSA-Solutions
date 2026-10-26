class Solution {
public:
    int minDiff(int k, vector<int>& arr) {
        int n = arr.size();

        vector<int> prefMin(n), prefMax(n);
        vector<int> suffMin(n), suffMax(n);

        prefMin[0] = arr[0], prefMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefMin[i] = min(prefMin[i - 1], arr[i]);
            prefMax[i] = max(prefMax[i - 1], arr[i]);
        }

        suffMin[n - 1] = arr[n - 1], suffMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], arr[i]);
            suffMax[i] = max(suffMax[i + 1], arr[i]);
        }

        int ans = INT_MAX;

        // Try removing subarray starting at index i of length k
        for (int i = 0; i <= n - k; i++) {
            int L = i, R = i + k - 1;
            int curMin = INT_MAX, curMax = INT_MIN;

            if (L > 0) {
                curMin = min(curMin, prefMin[L - 1]);
                curMax = max(curMax, prefMax[L - 1]);
            }
            if (R < n - 1) {
                curMin = min(curMin, suffMin[R + 1]);
                curMax = max(curMax, suffMax[R + 1]);
            }

            ans = min(ans, curMax - curMin);
        }

        return ans;
    }
};
