class Solution {
  public:
    int maxDepth(string &s) {
       string res = " ";
       int depth = 0;
       int maxd = 0;
       for(char c :s){
           if (c == '(') {
           depth++; 
           maxd = max(depth, maxd);
           }
           else if (c==')') {
               depth--; 
               
           }
       
       }
        return maxd;
    }
};