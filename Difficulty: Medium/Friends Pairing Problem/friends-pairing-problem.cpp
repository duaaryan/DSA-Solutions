class Solution {
public:
    int countFriendsPairings(int n) {
        if (n <= 2) return n;
        
        long long a = 1; 
        long long b = 2; 
        long long c = 0;
        long long mod = 1e9 + 7; 
        
        for (int i = 3; i <= n; i++) {
            c = (b + (i - 1) * a) % mod;
            a = b;
            b = c;
        }
        return b;
    }
};
