class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
       int ind = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
       return ind;
        
    }
};
