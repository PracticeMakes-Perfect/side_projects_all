/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

 
Constraints:

    n == matrix.length == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100



*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        rowMax = matrix.size() - 1;
        colMax = matrix[0].size() - 1;
        myGrid = matrix;
        
        //for topdown method
        /*
        mem = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), MIN));
        
        int mini = MAX;
        for (int i = 0; i <= rowMax; ++i)  {
            mini = std::min(mini, topDown(0, i));
        }
        return mini;
        */
        
        //tabulation method
        return buttomUp();
    }
    
private:
    int colMax;
    int rowMax;
    vector<vector<int>> myGrid;
    vector<vector<int>> mem;
    int MAX = std::numeric_limits<int>::max();
    int MIN = std::numeric_limits<int>::min();
    
    int topDown(int rowNow, int colNow) {
        
        //base cases
        if (colNow < 0 || colNow > colMax) {
            return MAX;
        }
        
        //reach the last row
        if (rowNow == rowMax) {
            return myGrid[rowNow][colNow];
        }
        
        //retrieve from mem
        if (mem[rowNow][colNow] != MIN) {
            return mem[rowNow][colNow];
        }
        
        int left = topDown(rowNow + 1, colNow - 1);
        int middle = topDown(rowNow + 1, colNow);
        int right = topDown(rowNow + 1, colNow + 1);
        
        mem[rowNow][colNow] = std::min(left, std::min(middle, right)) + myGrid[rowNow][colNow];
        
        return mem[rowNow][colNow];
    }
    
    int bottomUp() {
        vector<int> dp(myGrid.size() + 1, 0);
        vector<int> currentRow(myGrid.size() + 1, 0);
        
        for (int row = rowMax; row > -1; --row) {
            for (int col = 0; col < colMax + 1; ++col) {
                if (col == 0) {
                    currentRow[col] = std::min(dp[col], dp[col + 1]) + myGrid[row][col];
                } else if (col == colMax) {
                    currentRow[col] = std::min(dp[col], dp[col - 1]) + myGrid[row][col];
                } else {
                    currentRow[col] = std::min(dp[col - 1], std::min(dp[col], dp[col + 1])) + myGrid[row][col];
                }
            }
            
            dp = currentRow;
        }
        
        int minFalling = MAX;
        for (int k = 0; k < myGrid.size(); ++k) {
            minFalling = std::min(minFalling, dp[k]);
        }
        
        return minFalling;    
    }
};