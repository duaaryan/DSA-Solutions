class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0 ;
        int zeros = 0;
        int best = 0;
        int n = arr.size();
        
        for(int r = 0; r<n;r++){
            if(arr[r]==0){
                zeros++;
            }
            while(zeros >k){
                if(arr[left]==0){
                    zeros--;
                    
                }
                
                left++;
                
            }
            best = max(best, r - left+1);
        }
        return best;
    }
};
