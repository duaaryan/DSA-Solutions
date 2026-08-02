class Solution {
  public:
 int maxSumWithK(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> pre(n);
    pre[0] = arr[0];
    for(int i = 1; i < n; i++)
        pre[i] = pre[i-1] + arr[i];
    
    vector<int> minPre(n);
    minPre[0] = pre[0];
    for(int i = 1; i < n; i++)
        minPre[i] = min(minPre[i-1], pre[i]);
    
    int result = INT_MIN;
    for(int i = k-1; i < n; i++){
        result = max(result, pre[i]); // subarray from index 0
        if(i-k >= 0)
            result = max(result, pre[i] - minPre[i-k]);
    }
    return result;
}
};