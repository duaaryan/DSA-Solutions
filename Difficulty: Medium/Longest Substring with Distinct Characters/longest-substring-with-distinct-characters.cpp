class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_set<char> seen;
        int left = 0;
        int best = 0;
        
        for(int right = 0;right<s.size();right++){
            while(seen.count(s[right])> 0){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            best = max(best, right -left +1);
        }
        return best;
}
};