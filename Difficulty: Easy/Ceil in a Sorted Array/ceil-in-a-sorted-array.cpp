class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
       int ar = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
       if(ar == arr.size()) return -1;
        return ar;
    }
    
};