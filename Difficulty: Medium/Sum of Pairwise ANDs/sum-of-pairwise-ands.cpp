class Solution {
public:
    long long pairAndSum(vector<int>& arr) {
        long long totalSum = 0;

        // Loop through all possible 32 bits of an integer
        for (int k = 0; k < 32; k++) {
            long long count = 0;

            // Count how many elements have the k-th bit set
            for (int num : arr) {
                if ((num >> k) & 1) {
                    count++;
                }
            }

            // Number of pairs that will have the k-th bit set in their AND result
            long long pairs = (count * (count - 1)) / 2;

            // Add the contribution of this bit to the total sum
            totalSum += pairs * (1LL << k);
        }

        return totalSum;
    }
};
