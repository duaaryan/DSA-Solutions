class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int n = arr.size();
       long long sn= (long long) n*(n+1)/2;
       long long s2n = (long long)n*(n+1) * (2*n+1) /6;
       long long s =0, s2 =0;
       for (int i =0; i<n;i++){
           s += arr[i];
           s2 += (long long)arr[i] * (long long)arr[i];
           
       }
        long long  val1 = s -sn;
           long long val2 = s2 - s2n;
           val2 = val2 / val1;
           long long x = (val2 + val1) /2;
           long long y = x -  val1;
           return {(int)x, (int)y };  
    }
};