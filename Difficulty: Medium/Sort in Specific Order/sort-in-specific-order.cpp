class Solution {
  public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            bool aOdd = (a % 2 != 0);
            bool bOdd = (b % 2 != 0);

            // If one is odd and the other is even, the odd number comes first
            if (aOdd != bOdd) {
                return aOdd; 
            }

            // If both are odd, sort in descending order
            if (aOdd) {
                return a > b;
            }

            // If both are even, sort in ascending order
            return a < b;
        });
    }
};
