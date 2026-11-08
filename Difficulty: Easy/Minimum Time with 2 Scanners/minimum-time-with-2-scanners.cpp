class Solution {
public:
    int minTime(int n, int s1, int s2) {
        // Use long long for binary search bounds to prevent any potential overflow
        long long low = 1;
        long long high = (long long)min(s1, s2) * n;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // Total documents scanned by both scanners within 'mid' time
            long long totalDocs = (mid / s1) + (mid / s2);

            if (totalDocs >= n) {
                ans = mid;        // 'mid' is a valid time, try to minimize it
                high = mid - 1;
            } else {
                low = mid + 1;   // Not enough time, increase it
            }
        }

        return (int)ans;
    }
};
