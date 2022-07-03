/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 200
    0 <= grid[i][j] <= 100

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        rowMax = grid.size() - 1;
        colMax = grid[0].size() - 1;
        myGrid = grid;
        
        return buttomUp();
    }
private:
    int colMax;
    int rowMax;
    vector<vector<int>> myGrid;
        
    int bottomUp() {
        for (int i = rowMax; i > -1; --i) {
            for (int j = colMax; j > -1; --j) {
                if (i == rowMax && j != colMax) {
                    //when it is in the last row, this comes from right one
                    myGrid[i][j] = myGrid[i][j] + myGrid[i][j + 1];
                    
                } else if (i != rowMax && j == colMax) {
                    //when it is in the last column, this comes from buttom one
                    myGrid[i][j] = myGrid[i][j] + myGrid[i + 1][j];
                    
                } else if (i != rowMax && j != colMax) {
                    myGrid[i][j] = myGrid[i][j] + std::min(myGrid[i + 1][j], myGrid[i][j + 1]);
                }
            }
        } 
        
        return myGrid[0][0];
    }
};