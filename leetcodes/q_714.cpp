/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

Constraints:

    1 <= prices.length <= 5 * 10^4
    1 <= prices[i] < 5 * 10^4
    0 <= fee < 5 * 10^4

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        len = prices.size();
        myFee = fee;
        myPrices = prices;
        
        //for topDown
        mem = vector<vector<int>>(len, vector<int>(2, std::numeric_limits<int>::min()));
        
        //return bottomUp();
        return topDown(0, 0);
    }
private:
    int len;
    int myFee;
    vector<int> myPrices;
    vector<vector<int>> mem;
    
    int topDown(int day, int haveStk) {
        if (day == len) {
            return 0;
        }
        
        if (mem[day][haveStk] != std::numeric_limits<int>::min()) {
            return mem[day][haveStk];
        }
        
        int keepStkProfit = topDown(day + 1, haveStk);
        
        int opProfit = 0;
        if (haveStk == 1) {
            //have stock and sell it
            opProfit = myPrices[day] + topDown(day + 1, 0) - myFee;
        } else {
            //no stock and buy one
            opProfit = topDown(day + 1, 1) - myPrices[day];
        }
        
        mem[day][haveStk] = std::max(keepStkProfit, opProfit);
        
        return mem[day][haveStk];
    }
    
    int bottomUp() {
        int cash = 0;
        int hold = -myPrices[0];
        
        for (int i = 1; i < len; ++i) {
            //if you had stock in i -1 day, sell it to maximize your cash
            cash = std::max(cash, hold + myPrices[i] - myFee);
            
            //hold is like balance
            hold = std::max(hold, cash - myPrices[i]);
        }
        
        return cash;
    }
};