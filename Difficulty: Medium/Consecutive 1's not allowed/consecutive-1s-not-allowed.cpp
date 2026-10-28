class Solution {
  public:
    int countStrings(int n) {
      long long end0 =1, end1= 1;
      for(int i = 2; i<=n;i++){
          long long new0 = end0 +end1;
          long long new1 = end0;
          end0 = new0;
          end1 = new1;
      }
        return end0 + end1;
    }
}; 