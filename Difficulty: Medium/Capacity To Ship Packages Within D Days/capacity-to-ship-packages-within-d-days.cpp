class Solution {
  public:
  int fdays(vector<int>& w, int cap){
      int days =1;
      int load =0;
      for(int i =0; i< w.size();i++){
          if(load + w[i] > cap){
              days ++;
              load = w[i];
          }
          else {
              load += w[i];
      }
      
      }
      return days;
  }

  
    int leastWeightCapacity(vector<int>& arr, int d) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low<=high){
            int mid = low +(high-low)/2;
            int nod = fdays(arr, mid);
            if(nod <= d){
                high = mid-1;
            }
            
            else{
                low = mid+1;
            }
        }
        return low;
    }
  
    
};