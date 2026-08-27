class Solution {
  public:
  bool canwe(vector<int>& w, int dist, int cows){
      int cntcows = 1;
      int last = w[0];
      for(int i =1;i<w.size();i++){
          if(w[i] - last >= dist){
              cntcows++;
              last = w[i];
              
          }
          
      }
      if (cntcows >= cows) return true;
          return false;
  }
    int aggressiveCows(vector<int> &arr, int k) {
       int n = arr.size();
       sort(arr.begin(), arr.end());
       int low = 0;
       int high = arr[n-1] - arr[0];
       while(low <= high){
           int mid = (low + high)/2;
           if(canwe(arr,mid,k) == true){
               low = mid +1;
           }
           else{
               high = mid -1;
           }
       }
       return high ;
       
       
    }
};