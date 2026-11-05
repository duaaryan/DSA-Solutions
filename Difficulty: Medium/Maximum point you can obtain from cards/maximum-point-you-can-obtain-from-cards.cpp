class Solution {
  public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int sum = 0;
        
        for (int i =0; i<k;i++){
            sum+=card[i];
        }
        int best = sum;
        
        
        for (int i =0; i<k;i++){
            sum -= card[k-1-i];
            sum += card[n-1-i];
        
        best = max(best, sum);
        }
        return best;
    }
};
