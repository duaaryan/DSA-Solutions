class Solution {
  public:
    int prefixStrings(int n) {
     vector<long long>dp(n+1,0);

     int mod=1000000007;

     dp[0]=1,dp[1]=1;

     for(int i=2;i<=n;i++){

         for(int j=0;j<i;j++){

             dp[i]+=((dp[j]%mod)*(dp[i-j-1]%mod))%mod;

         }

     }

     return dp[n]%mod;
        
    }
};