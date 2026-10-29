class Solution {
    double solve(double b, long long n) {
        if (n == 0) return 1;                 
        double half = solve(b, n / 2);
        if (n % 2 == 0) return half * half;       
        else return b * half  * half;              
    }

public:
    double power(double b, int e) {
        long long n = e;                          
        if (n < 0) {
            b = 1 / b;
            n = -n;
        }
        return solve(b, n);
    }
};