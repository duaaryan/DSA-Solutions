class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
       map<int, int> mpp;
       mpp[0]=1;
       int presum =0, cnt=0;
       for(int i=0;i<arr.size();i++){
           presum += arr[i];
           int removee = presum -k;
           cnt += mpp[removee];
           mpp[presum] += 1;
       }
        return cnt;
    }
};