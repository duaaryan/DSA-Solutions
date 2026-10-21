class Solution {
public:
    int minSubarraySum(vector<int>& arr) {
        // Initialize with the first element
        int min_ending_here = arr[0];
        int min_so_far = arr[0];

        // Loop through the rest of the array
        for (size_t i = 1; i < arr.size(); i++) {
            // Decide to either extend the current subarray or start a new one
            min_ending_here = min(arr[i], min_ending_here + arr[i]);

            // Update the global minimum if a smaller sum is found
            min_so_far = min(min_so_far, min_ending_here);
        }

        return min_so_far;
    }
};
