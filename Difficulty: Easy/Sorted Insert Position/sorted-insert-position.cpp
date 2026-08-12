class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int ar = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
        return ar;
    }
};