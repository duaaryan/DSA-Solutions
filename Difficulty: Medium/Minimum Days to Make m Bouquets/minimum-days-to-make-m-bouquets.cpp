class Solution {
public:
    bool canMake(vector<int>& arr, int day, int k, int m) {
        int bouquets = 0, flowers = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= day) {
                flowers++;
                if(flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long total = (long long)k * m;
        if(total > arr.size()) return -1;

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(canMake(arr, mid, k, m)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};