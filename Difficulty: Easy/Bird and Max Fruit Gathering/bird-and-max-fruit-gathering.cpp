class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        // Edge case: if m is greater than or equal to total trees,
        // the bird can just collect fruits from all trees.
        if (m >= n) {
            int total_sum = 0;
            for (int fruit : arr) {
                total_sum += fruit;
            }
            return total_sum;
        }

        int current_sum = 0;
        // Step 1: Calculate the sum of the first window of size m
        for (int i = 0; i < m; i++) {
            current_sum += arr[i];
        }

        int max_sum = current_sum;

        // Step 2 & 3: Slide the window across the circular array
        // The window starts at index 0 and slides n times to check all start positions
        for (int i = 0; i < n; i++) {
            // Subtract the element leaving the window: arr[i]
            // Add the element entering the window: arr[(i + m) % n]
            current_sum = current_sum - arr[i] + arr[(i + m) % n];

            // Step 4: Update the maximum fruit collected
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};
