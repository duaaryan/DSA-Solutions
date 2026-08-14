class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> sequence;
        sequence.push_back(s);
        long long current_sum = s;

        
        for (int num : arr) {
            long long next_val = current_sum + num;
         
            if (next_val > x) {
                break;
            }
            sequence.push_back(next_val);
            current_sum += next_val;
        }
  
  int target =x;
        for (int i = sequence.size() - 1; i >= 0; i--) {
            if (target >= sequence[i]) {
                target -= sequence[i];
            }
        }

        
        return target == 0;
    }
};
