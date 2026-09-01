class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &arr, int x) {
                       int n = arr.size();
                       int m = arr[0].size();

                       int low =0;
                      int high = (n*m-1);
                      while(low<=high){
                          int mid = (low+high)/2;
                          int row = mid/m;
                          int col = mid%m;
                          if(arr[row][col]==x) return true;
                          else if (arr[row][col] < x){
                              low = mid +1;
                          }
                          else{
                              high = mid -1;
                          }
                      }
                      return false;
                   }
               };