class Solution {
  public:
    int maxLength(vector<int>& arr) {
        map<int, int> presummap;
        int sum =0;
        int len =0;
        for (int i=0;i<arr.size();i++){
            sum += arr[i];
        if (sum==0){
            len=max(len,i+1);
        }
        int rem = sum-0;
        if (presummap.find(rem) !=presummap.end()){
        int lenn = i - presummap[rem];
        len = max(len,lenn);
        }
        if (presummap.find(sum) == presummap.end()){
            presummap[sum]=i;
        }
    
    }
return len;
}
};
        
 