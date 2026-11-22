class Solution {
  public:
    int longestSubarrayDivK(vector<int>& nums, int k) {
        unordered_map<int, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Add current element to the running prefix sum
            sum += nums[i];

            // Calculate positive remainder when divided by k
            int rem = ((sum % k) + k) % k;

            // Case 1: Subarray starting from index 0 is divisible by k
            if (rem == 0) {
                maxLen = max(maxLen, i + 1);
            }

            // Case 2: Check if the same remainder has been seen before
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // Store the first occurrence of this remainder
            if (preSumMap.find(rem) == preSumMap.end()) {
                preSumMap[rem] = i;
            }
        }

        return maxLen;
    }
};
