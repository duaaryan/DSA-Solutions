class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
         vector<int> ans;
         int maxi = INT_MIN;
         int n =arr.size();
         for (int i=n-1;i>=0;i--){
             if(arr[i]>=maxi){
                 ans.push_back(arr[i]);
             }
             maxi = max(maxi, arr[i]);
         }
         
      reverse(ans.begin(), ans.end());
      return ans;
    }
};