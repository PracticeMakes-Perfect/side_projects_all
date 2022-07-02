/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

ex1: 
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

ex2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

constraints:
1 <= n <= 45
*/

class Solution {
public:
    int climbStairs(int n) {
        mem = std::vector<int>(n);
        
        return 1 + dp(n-1);
    }
private:
    std::vector<int> mem;
    
    int dp(int n) {
        if (n <= 0) {
            return 0;
        }
        
        if (mem[n] != 0)
            return mem[n];
        
        mem[n] = 1 + std::max(dp(n-1), 0) + std::max(dp(n-2), 0);
        
        return mem[n];
    }
};