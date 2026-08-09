class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int ans = INT_MIN;
        int prefix = 0;
        int suffix = 0;
        for (int i = 0;i<arr.size();i++){
            if (prefix ==0) prefix =1;
            if (suffix ==0) suffix =1;
            prefix = prefix * arr[i];
            suffix = suffix * arr[arr.size()-i-1];
            ans = max(ans, max(prefix, suffix));
        }
        
        return ans;
    }
};