class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        int n =arr.size();
        sort(arr.begin(), arr.end());
        int cnt=0;
        int left =0;
        int right =1;
        
        while(right < arr.size()){
            if(arr[right]-arr[left] <k){
                cnt +=right -left;
                right++;
            }
            else {
                left++;
            }
        }
        return cnt;
    }
};