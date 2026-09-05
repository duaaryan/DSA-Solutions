class Solution {
public:
    int longestSubseq(vector<int>& arr) {
        // map/unordered_map to store the maximum subsequence length ending at a particular number
        unordered_map<int, int> dp;
        int maxLength = 0;

        for (int num : arr) {
            // Check lengths if the previous element was (num - 1) or (num + 1)
            int len1 = dp.count(num - 1) ? dp[num - 1] : 0;
            int len2 = dp.count(num + 1) ? dp[num + 1] : 0;

            // The current number extends the longer of the two chains
            dp[num] = max(len1, len2) + 1;

            // Keep track of the global maximum length found so far
            maxLength = max(maxLength, dp[num]);
        }

        return maxLength;
    }
};
