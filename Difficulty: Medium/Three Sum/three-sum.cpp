class Solution {
  public:
    vector<vector<int>> triplets(vector<int> &arr) {
        vector <vector <int>> ans;
        int n=arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            int j =i+1;
            int k= n-1;
            while (j<k) {
                int sum = arr[i]+arr[j]+arr[k];
                if(sum<0){
                    j++;
                }
                    else if(sum>0){
                        k--;
                    }
                        
                           else {
    ans.push_back({arr[i], arr[j], arr[k]});
    int tempj = arr[j], tempk = arr[k];
    while(j < k && arr[j] == tempj) j++;
    while(j < k && arr[k] == tempk) k--;

                
            }
        }
       
    }
    return ans;
}
};
