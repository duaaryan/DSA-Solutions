class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 0);
        
        
        dp[0] = max(h[0], l[0]);
        
        if (n == 1) return dp[0];
        
       
        dp[1] = max({l[1] + dp[0], h[1], dp[0]});
        
        
        for (int i = 2; i < n; i++) {
            int low_task = l[i] + dp[i - 1];
            int high_task = h[i] + dp[i - 2];
            int skip_task = dp[i - 1];
            
            dp[i] = max({low_task, high_task, skip_task});
        }
        
        return dp[n - 1];
    }
};
