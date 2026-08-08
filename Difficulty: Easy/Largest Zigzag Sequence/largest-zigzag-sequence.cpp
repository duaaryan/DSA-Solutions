class Solution {
	public:
	int zigzagSequence(vector<vector<int>> & mat) {
		int n = mat.size();
		
		for (int i = n - 2; i >= 0; i--) {
			
			int largestElement = -1;
			int secondLargest = -1;
			int largestIdx = -1;
			for (int j = 0; j < n; j++) {
				if (mat[i + 1][j] > largestElement) {
					secondLargest = largestElement;
					largestElement = mat[i + 1][j];
					largestIdx = j;
				}
				else if (mat[i + 1][j] > secondLargest) {
					secondLargest = mat[i + 1][j];
				}
			}
			for (int j = 0; j < n; j++) {
				if (j == largestIdx)
					mat[i][j] += secondLargest;
				else
					mat[i][j] += largestElement;
			}
		}
		
		int maxSum = 0;
		
		for (int j = 0; j < n; j++)
			maxSum = max(maxSum, mat[0][j]);
		
		return maxSum;
	}
};