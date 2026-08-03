class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    for(int i = 0; i < arr.size(); i++) {
        if(cnt1 == 0 && el2 != arr[i]) {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && el1 != arr[i]) {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else { cnt1--; cnt2--; }
    }
    
    
    cnt1 = 0; cnt2 = 0;
    for(int x : arr) {
        if(x == el1) cnt1++;
        else if(x == el2) cnt2++;
    }
    
    vector<int> ans;
    int n = arr.size();
    if(cnt1 > n/3) ans.push_back(el1);
    if(cnt2 > n/3) ans.push_back(el2);
    sort(ans.begin(), ans.end());
    return ans;
}
};