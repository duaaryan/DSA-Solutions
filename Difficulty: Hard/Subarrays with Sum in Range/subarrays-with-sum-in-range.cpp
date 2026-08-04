class Solution {
private:
    // Helper function to count subarrays with a sum less than or equal to x
    long long countSubarraysLessThanOrEqual(const vector<int>& arr, int x) {
        long long count = 0;
        long long current_sum = 0;
        int start = 0;

        for (int end = 0; end < arr.size(); ++end) {
            current_sum += arr[end];

            // Shrink the window from the left if the sum exceeds x
            while (current_sum > x && start <= end) {
                current_sum -= arr[start];
                start++;
            }

            // All subarrays ending at 'end' and starting from 'start' to 'end' are valid
            count += (end - start + 1);
        }

        return count;
    }

public:
    int countSubarray(vector<int>& arr, int l, int r) {
        long long count_r = countSubarraysLessThanOrEqual(arr, r);
        long long count_l_minus_1 = countSubarraysLessThanOrEqual(arr, l - 1);
        
        return (int)(count_r - count_l_minus_1);
    }
};

