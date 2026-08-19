class Solution {
  private:
    // Helper function to count triplets with sum <= X
    int countTripletsLessThanOrEqual(std::vector<int>& arr, int X) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int current_sum = arr[i] + arr[j] + arr[k];
                if (current_sum <= X) {
                    // If sum <= X, all triplets from j to k are valid
                    count += (k - j);
                    j++; 
                } else {
                    k--;
                }
            }
        }
        return count;
    }

  public:
    int countTriplets(std::vector<int>& arr, int l, int r) {
        // Sort the array first
        std::sort(arr.begin(), arr.end());

        // Triplets in range [l, r] = (Triplets <= r) - (Triplets <= l - 1)
        return countTripletsLessThanOrEqual(arr, r) - countTripletsLessThanOrEqual(arr, l - 1);
    }
};
