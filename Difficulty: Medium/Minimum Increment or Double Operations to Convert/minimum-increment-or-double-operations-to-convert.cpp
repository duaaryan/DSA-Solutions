class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int total_increments = 0;
        int max_doubles = 0;
        
        for (int x : arr) {
            int current_doubles = 0;
            
            while (x > 0) {
                // If odd, it requires an increment operation
                if (x % 2 == 1) {
                    total_increments++;
                }
                
                // If it can be halved further, increment individual double count
                if (x > 1) {
                    current_doubles++;
                }
                
                x /= 2;
            }
            
            // The global double operations are bounded by the maximum bits needed
            max_doubles = max(max_doubles, current_doubles);
        }
        
        return total_increments + max_doubles;
    }
};
