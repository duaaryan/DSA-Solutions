class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        int n = arr.size();
        int minLen = INT_MAX;
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // Expand the window by adding the current element
            currentSum += arr[right];

            // Shrink the window from the left as long as the sum is strictly greater than x
            while (currentSum > x) {
                minLen = min(minLen, right - left + 1);
                currentSum -= arr[left];
                left++;
            }
        }

        // If no valid subarray was found, return 0
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
