class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();

        int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
                  if(lb==n || arr[lb] !=target){
                  return 0;

                  }
                 int up = upper_bound(arr.begin(), arr.end(), target) - arr.begin()  ;
                return (up - lb);
        
    }
};
