class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        int res =0;
        
        for (int i =0;i<n;i++){
            long long freq = (long long) (i+1)*(n-i);
            
            if(freq % 2==1){
                res ^=arr[i];
            }
        }
        return res;
    }
};