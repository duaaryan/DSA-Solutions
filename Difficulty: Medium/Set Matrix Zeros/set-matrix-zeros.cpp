class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &matrix) {
    
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;
    
    
    // Step 1: mark first row/col as indicators
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                // mark the i-th row
                matrix[i][0] = 0;
                // mark the j-th col
                if(j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;  // first col has a zero
            }
        }
    }
    
    // Step 2: zero out cells based on markers (skip first row/col)
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] != 0) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    // Step 3: zero out first row if needed
    if(matrix[0][0] == 0) {
        for(int j = 0; j < m; j++) matrix[0][j] = 0;
    }
    
    // Step 4: zero out first col if needed
    if(col0 == 0) {
        for(int i = 0; i < n; i++) matrix[i][0] = 0;
    }
}
        
    
};