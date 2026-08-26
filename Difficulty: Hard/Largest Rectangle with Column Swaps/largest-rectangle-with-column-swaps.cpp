class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int r = mat.size();
        if (r == 0) return 0;
        int c = mat[0].size();

        // hist[j] will store the count of consecutive 1s in column j
        vector<int> hist(c, 0);
        int max_area = 0;

        // Traverse row by row
        for (int i = 0; i < r; ++i) {
            // Update the consecutive 1s count for the current row
            for (int j = 0; j < c; ++j) {
                if (mat[i][j] == 1) {
                    hist[j] += 1;
                } else {
                    hist[j] = 0;
                }
            }

            // Create a copy of the current histogram row to sort
            vector<int> sorted_hist = hist;
            sort(sorted_hist.begin(), sorted_hist.end(), greater<int>());

            // Calculate max area for this row configuration
            for (int k = 0; k < c; ++k) {
                int width = k + 1;
                int height = sorted_hist[k];
                int area = width * height;
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};
