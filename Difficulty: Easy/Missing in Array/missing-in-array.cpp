class Solution {
  public:
    int missingNum(vector<int>& arr) {
         int size = arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<=size;i++){
            if( i+1 != arr[i]){
                return i+1;
            }
        }
    }
};