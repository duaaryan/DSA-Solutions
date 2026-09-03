class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Base cases for the first element (index 0)
        // No differences calculated yet, so initial sums are 0
        int prev_original = 0;
        int prev_replaced = 0;

        for (int i = 1; i < n; i++) {
            // If we keep the current element arr[i] as original
            int curr_original = max(
                prev_original + abs(arr[i] - arr[i-1]),  // previous was original
                prev_replaced + abs(arr[i] - 1)          // previous was replaced by 1
            );

            // If we replace the current element arr[i] with 1
            int curr_replaced = max(
                prev_original + abs(1 - arr[i-1]),       // previous was original
                prev_replaced + abs(1 - 1)               // previous was replaced by 1
            );

            // Update variables for the next iteration
            prev_original = curr_original;
            prev_replaced = curr_replaced;
        }

        // The answer is the maximum achievable sum at the last element
        return max(prev_original, prev_replaced);
    }
};
