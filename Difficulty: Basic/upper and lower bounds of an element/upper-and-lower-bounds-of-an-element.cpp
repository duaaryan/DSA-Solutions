int upBound(vector<int>& arr, int k) {
   int into = upper_bound(arr.begin(), arr.end(), k) - arr.begin() ;
   return arr[into]; 
}

int lowBound(vector<int>& arr, int k) {
     int into1 = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
     return arr[into1];
    }
