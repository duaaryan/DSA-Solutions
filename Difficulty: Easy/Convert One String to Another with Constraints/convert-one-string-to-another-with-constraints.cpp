class Solution {
 public:
     bool isItPossible(string &s1, string &s2) {
         int n = s1.length();
         int m = s2.length();

         // If the lengths are different, transformation is impossible
         if (n != m) return false;

         int i = 0, j = 0;

         while (i < n || j < m) {
             // Skip '#' in the first string
             while (i < n && s1[i] == '#') i++;
             // Skip '#' in the second string
             while (j < m && s2[j] == '#') j++;

             // If both pointers reach the end, transformation is successful
             if (i == n && j == m) return true;

             // If one pointer reaches the end but the other doesn't
             if (i == n || j == m) return false;

             // The characters at the non-hash positions must match
             if (s1[i] != s2[j]) return false;

             // Check structural position constraints
             if (s1[i] == 'A' && i < j) return false; // 'A' cannot move right
             if (s1[i] == 'B' && i > j) return false; // 'B' cannot move left

             // Move to the next characters
             i++;
             j++;
         }

         return true;
     }
 };
