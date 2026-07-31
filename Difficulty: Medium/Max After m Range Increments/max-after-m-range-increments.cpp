class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
       vector<int> pref(n+1, 0);
      
      int nn=a.size();
      for(int i=0; i<nn; i++){
        pref[a[i]]+=k[i];  
        pref[b[i]+1]-=k[i];  
      }
      
      int ans=pref[0];
      for(int i=1; i<n; i++){
        pref[i]+=pref[i-1];
        ans=max(ans, pref[i]);
      }
      
      
      return ans;
        
    }
};