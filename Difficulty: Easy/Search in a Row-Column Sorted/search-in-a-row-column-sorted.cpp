class Solution {
  public:
    bool matSearch(vector<vector<int>> &arr, int x) {
        int n = arr.size();

        // Perform binary search on each row individually
        for (int i = 0; i < n; i++) {
            int low = 0;
            int high = arr[i].size() - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[i][mid] == x) {
                    return true;
                }
                else if (arr[i][mid] < x) {
                    low = mid + 1; // Search right half of the row
                }
                else {
                    high = mid - 1; // Search left half of the row
                }
            }
        }

        return false;
    }
};
