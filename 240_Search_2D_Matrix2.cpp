class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {// TC=O(m+n)

        int n = matrix[0].size(); //no of column
        int m = matrix.size(); //no of rows

        int row = 0;
        int col = n-1;

        while (row < m && col >=0 ) {
            if(target == matrix[row][col]) {
                return true;
            } else if (target < matrix[row][col]) {
                    col--;
            } else {
                    row++;
            }
        }
      return false;  
    }
};