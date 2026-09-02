class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
       int n = arr.size();
       int m = arr[0].size();
       int maxcount = 0;
       int ans = -1;
       for(int i =0;i<n;i++){
           int count = m - (lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin());
           if(count > maxcount){
               maxcount = count;
               ans = i;
           }
       }
      return ans;  
    }
};