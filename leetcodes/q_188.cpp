/*
188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

constraints:
    0 <= k <= 100
    0 <= prices.length <= 1000
    0 <= prices[i] <= 1000

ex1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

ex2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        myPrices = prices;
        tmp = new int**[prices.size()];
        
        for (int i = 0; i < prices.size(); ++i) {
            tmp[i] = new int*[k + 1];
        }
        
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 0; j < k + 1; ++j) {
                tmp[i][j] = new int[2];
            }
        }
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 0; j < k + 1; ++j) {
                for (int m = 0; m < 2; ++m) {
                    tmp[i][j][m] = 0;
                }
            }
        }
        
        
        return dp(0, k, 0);
    }
private:
    vector<int> myPrices;
    int*** tmp;
    
    //this is for TopDown method
    int dp(int i, int transRmn, int holding) {
        
        //base cases
        if (transRmn == 0 || i == myPrices.size()) {
            return 0;
        }
        
        if (tmp[i][transRmn][holding] == 0) {
            int doNothing = dp(i + 1, transRmn, holding);
            int doSomething;
            
            if (holding == 1) {
                doSomething = myPrices[i] + dp(i + 1, transRmn - 1, 0);
            } else {
                doSomething = -myPrices[i] + dp(i + 1, transRmn, 1);
            }
            
            tmp[i][transRmn][holding] = std::max(doNothing, doSomething);
        }
        
        return tmp[i][transRmn][holding];
    }
};