class Solution {
public:
    bool canPlace(vector<int>& arr, int k, double mid) {
        int cnt = 0;
        for(int i = 1; i < arr.size(); i++) {
            cnt += (int)((arr[i] - arr[i-1]) / mid);
        }
        return cnt <= k;
    }

    double minMaxDist(vector<int>& arr, int k) {
        double low = 0, high = arr.back() - arr[0];
        
        for(int i = 0; i < 50; i++) {  // 50 iterations for precision
            double mid = (low + high) / 2.0;
            if(canPlace(arr, k, mid)) {
                
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    }
};