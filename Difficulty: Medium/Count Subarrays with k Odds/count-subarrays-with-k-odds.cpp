class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        freq[0]=1;
        
        int count =0 ;
        int ans= 0;
        int n = arr.size();
        for(int right=0; right<n;right++){
            count += arr[right] % 2;
            ans += freq[count-k];
            freq[count]++;
            
        }
        return ans;
    }
};