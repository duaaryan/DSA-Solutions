class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> freq;
        int left =0;
        int n = arr.size();
        int best =0 ;
        
        for(int right = 0 ; right <n;right++){
            freq[arr[right]]++; 
            while (freq.size() > 2) {
                freq[arr[left]]--;

                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }

                left++;
            }

            best = max(best, right - left + 1);
            
        }
        return best;
    }
};