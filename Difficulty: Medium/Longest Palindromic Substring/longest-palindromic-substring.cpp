class Solution {
  public:
    string getLongestPal(string &s) {
        int n = s.size();
        if (n==0) return "";
        int best = 0;
        int bestL = 1;
        
        
        for(int i = 0; i<n;i++){
            int l = i;
            int r = i;
            
            while(l>= 0 && r <n && s[l]==s[r]){
                l--;
                r++;
                
            }
            int len = r-l-1;
            if(len > bestL){
                bestL = len;
                best= l+1;
            }
            l =i;
            r = 1+i;
          while(l>= 0 && r <n && s[l]==s[r]){
              l--;
              r++;
        }
        len = r-l-1;
        if(len > bestL){
            bestL= len;
            best = l+1;
        }
        }
        return s.substr(best, bestL); 
    }
};