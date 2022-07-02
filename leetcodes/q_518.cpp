/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.


ex1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

ex2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

ex3:
Input: amount = 10, coins = [10]
Output: 1

Constraints:

    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000


*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        c = coins;
        amt = amount;
        maxLen = c.size();
        std::sort(c.begin(), c.end());
 
        mem = std::vector<int>(amt + 1);
        mem[0] = 1;
        
        return buttonUp();
        
        /*
        mem = std::vector<std::vector<int>>(maxLen);
        for (int i = 0; i < mem.size(); ++i) {
            mem[i] = std::vector<int>(amt);
        }
        
        return topDown(0, 0);
        */
    }
private:
    int maxLen;
    int amt;
    std::vector<int> c;
    std::vector<int> mem;
    
    int buttonUp() {
        for (int i = 0; i < c.size(); ++i) {
            for (int j = c[i]; j < amt + 1; ++j) {
                mem[j] += mem[j - c[i]];
            }
            
        }
        
        return mem[amt];
    }
    
    /* for topDown 
    std::vector<std::vector<int>> mem;
    
    //topDown time limit Exceede 
    int topDown(int coinNow, int val) {        
        if (val == amt)
            return 1;
        
        if (val > amt)
            return 0;
        
        if (coinNow == maxLen)
            return 0;
            
        if (mem[coinNow][val] != 0) 
            return mem[coinNow][val];
        
        mem[coinNow][val] = dp(coinNow, val + c[coinNow]) + dp(coinNow + 1, val);

        return mem[coinNow][val];
    }
    */
};