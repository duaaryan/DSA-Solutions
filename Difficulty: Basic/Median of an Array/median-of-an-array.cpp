class Solution {
  public:
    double findMedian(vector<int> &arr) {
       int n = arr.size();
       if (n == 0) return 0;

       std::sort(arr.begin(), arr.end());

       if (n % 2 != 0) {
           return arr[n / 2];
       } else {
           return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
       }
    }
};