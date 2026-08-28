class Solution {
  public:
  int mallu(vector<int>&arr ,long long maxsum){
      int n = arr.size();
      int bro = 1;
      long long bro1 =arr[0];
      for(int i =1;i<n;i++){
          if(bro1 +arr[i] <= maxsum){
              bro1 += arr[i];
          }
          else{
              bro++;
              bro1 = arr[i];
          }
      }
      return bro;
  }
    int minTime(vector<int>& arr, int k) {
       int low = *max_element(arr.begin(), arr.end());
       int high = accumulate(arr.begin(), arr.end(), 0);
       int ans = -1;
       while(low<=high){
           int mid = (low + high)/2;
           int mal = mallu(arr, mid);
           if(mal >k){
               low = mid +1;
               
           }
           else{
               ans = mid;
               high = mid -1;
           }
           
       }
        return ans;
    }
};