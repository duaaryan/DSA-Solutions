class Solution {
  public:
    int minOperation(int n) {
      
          
              int operations = 0;

              while (n > 0) {
                  if (n % 2 == 0) {
                      n /= 2; // Reverse of doubling
                  } else {
                      n -= 1; // Reverse of adding 1
                  }
                  operations++;
              }

              return operations;
          }
      };
