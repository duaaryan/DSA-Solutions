class Solution {
  public:
    int numberOfSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        freq[0]= 1;
        
    int sum =0;
    long long ans = 0;
    int n = arr.size();
    
    for(int right =0; right<n; right++){
        sum += arr[right];
        ans += freq[sum - k];
        freq[sum]++;
        
    }
    return ans;
    }
};