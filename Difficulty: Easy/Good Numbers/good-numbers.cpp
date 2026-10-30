class Solution {
    bool isgood(int n , int d){
        int last = n % 10;
        if(last==d) return false;
        int sum = last;
        n /=10;
        
        while(n>0){
            int digit = n % 10;
            if(digit==d) return false;
            if(digit<=sum) return false;
            sum += digit;
            n /=10;
            
        }
        return true;
        
    }
  public:
    vector<int> goodNumbers(int l, int r, int d) {
        vector<int> ans;
        for(int x = l; x<=r;x++){
            if(isgood(x,d)) ans.push_back(x);
            
        }
        return ans;
        
    }
};