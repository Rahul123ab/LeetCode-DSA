class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { //TC = O(m*n)
        int m = matrix.size(); // no of rows
        int n = matrix[0].size(); // no of columns
        vector<int> ans;

        int stRow = 0, stCol = 0;
        int endRow = m-1, endCol = n-1;

        while (stRow <= endRow && stCol <= endCol) {
            //top boundary
            for(int i=stCol; i<=endCol; i++) {
                ans.push_back(matrix[stRow][i]);
            }

            //right boundary
            for(int j=stRow+1; j<=endRow; j++) {
                ans.push_back(matrix[j][endCol]);
            }

            //bottom boundary
            for(int i=endCol-1; i>=stCol; i--) {
                if(stRow == endRow) {//corner case in odd size matrix
                    break;
                }
                ans.push_back(matrix[endRow][i]);
            }

            //left boundary
            for(int j=endRow-1; j>=stRow+1; j--) {
                if(stCol == endCol) {//corner case in odd size matrix
                    break;
                }
                ans.push_back(matrix[j][stCol]);
            }
            stRow++; stCol++;
            endRow--; endCol--;
        }
        return ans;
    }
};