class Solution {
  public:
  vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    
    for(int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

    vector<int> nthRowOfPascalTriangle(int n) {
        vector<vector<int>> ans;
        int N= n;
    for(int i = 1; i <= N; i++) {
        ans.push_back(generateRow(i));
    }
    return ans[n-1];  
        
    }
};