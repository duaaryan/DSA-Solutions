class Solution {
public:
    // Helper function to count elements <= target in a sorted row
    int countLessThanEqualTo(const vector<int>& row, int target) {
        return upper_bound(row.begin(), row.end(), target) - row.begin();
    }

    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Find the absolute minimum and maximum in the matrix
        int low = mat[0][0];
        int high = mat[0][m - 1];

        for (int i = 1; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        // Target number of elements that should be <= the median
        int targetCount = (n * m) / 2;

        // Binary search on the answer range
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            // Count elements <= mid across all rows
            for (int i = 0; i < n; i++) {
                count += countLessThanEqualTo(mat[i], mid);
            }

            if (count <= targetCount) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
