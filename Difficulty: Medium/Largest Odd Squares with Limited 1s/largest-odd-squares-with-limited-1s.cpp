class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
    
    int n = mat.size();
        int m = mat[0].size();
        
        // 1. Build a 2D Prefix Sum Matrix (1-indexed for seamless edge-boundary handling)
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i-1][j-1] 
                           + pref[i-1][j] 
                           + pref[i][j-1] 
                           - pref[i-1][j-1];
            }
        }
        
        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
        };
        
        vector<int> ans;
        
        // 2. Evaluate each target query
        for (auto& q : queries) {
            int r = q[0];
            int c = q[1];
            
            // Maximum distance the square center can grow symmetrically before exiting boundaries
            int max_radius = min({r, c, n - 1 - r, m - 1 - c});
            
            int low = 0, high = max_radius;
            int max_valid_side = 1; // Default minimum valid fallback shape size (1x1)
            
            // before binary search, check if even 1x1 is valid
if(getSum(r+1, c+1, r+1, c+1) > k) {
    ans.push_back(-1);
    continue;
}
            // 3. Apply Binary Search to locate the maximum allowed expansion boundary
            while (low <= high) {
                int mid = low + (high - low) / 2;
                
                // Convert coordinates into 1-indexed system equivalents for prefix lookup maps
                int r1 = (r - mid) + 1;
                int c1 = (c - mid) + 1;
                int r2 = (r + mid) + 1;
                int c2 = (c + mid) + 1;
                
                if (getSum(r1, c1, r2, c2) <= k) {
                    max_valid_side = 2 * mid + 1; // Formula to compute odd side dimensions
                    low = mid + 1;                // Attempt scanning for a larger boundary configuration
                } else {
                    high = mid - 1;               // Excess elements found, contract target search volume
                }
            }
            ans.push_back(max_valid_side);
        }
        
        return ans;
    }
};