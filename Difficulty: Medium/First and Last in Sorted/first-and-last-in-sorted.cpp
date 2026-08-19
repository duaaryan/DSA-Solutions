class Solution {
  public:
  vector<int> find(vector<int>& arr, int x) {
      int n = arr.size();
  
int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
          if(lb==n || arr[lb] !=x){
          return vector<int>{-1, -1};

          }
         int up = upper_bound(arr.begin(), arr.end(), x) - arr.begin() -1 ;
        return vector<int>{lb, up};

    }
};