class Solution {
  public:
    int findd(vector<int>& v){
        int maxi= INT_MIN;
        int n =v.size();
        for(int i =0;i<n;i++){
            maxi =max(maxi,v[i]);
        }
        return maxi;
    }
    int coco(vector<int>&v, int hourly) {
        int totalh =0;
        int n =v.size();
    for(int i =0;i<n;i++){
    totalh += ceil((double)v[i] / (double)hourly);
    }
    return totalh;
    }
    int kokoEat(vector<int>& v, int k) {
       int low =1;
       int high = findd(v);
       while(low<=high){
           int mid = (low+high)/2;
           int totalh = coco(v, mid);
           if(totalh <=k){
               high = mid-1;
           }
           else{
               low =mid+1;
           }
       }
       return low; 
    }
};