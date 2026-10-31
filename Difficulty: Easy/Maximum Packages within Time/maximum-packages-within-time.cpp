class Solution {
public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int n = arr.size();

        // If totalTime allows us to visit all locations, we can just sum the whole array.
        if (totalTime >= n) {
            int totalSum = 0;
            for (int x : arr) {
                totalSum += x;
            }
            return totalSum;
        }

        // Find the sum of the first window of size 'totalTime'
        int currentSum = 0;
        for (int i = 0; i < totalTime; i++) {
            currentSum += arr[i];
        }

        int maxSum = currentSum;

        // Slide the window across the rest of the array
        for (int i = totalTime; i < n; i++) {
            // Add the new element entering the window and remove the element leaving it
            currentSum += arr[i] - arr[i - totalTime];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
