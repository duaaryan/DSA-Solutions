class Solution {
public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;

        // Tracks the minimum costs for choices 0, 1, and 2 of the previous row
        int prev0 = mat[0][0];
        int prev1 = mat[0][1];
        int prev2 = mat[0][2];

        for (int i = 1; i < n; i++) {
            // Calculate current row's min costs using previous row's values
            int curr0 = mat[i][0] + min(prev1, prev2);
            int curr1 = mat[i][1] + min(prev0, prev2);
            int curr2 = mat[i][2] + min(prev0, prev1);

            // Update previous values for the next iteration
            prev0 = curr0;
            prev1 = curr1;
            prev2 = curr2;
        }

        // Return the overall minimum cost after processing all rows
        return min({prev0, prev1, prev2});
    }
};