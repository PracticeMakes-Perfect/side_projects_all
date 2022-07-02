/*
You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

    Choose one integer x from either the start or the end of the array nums.
    Add multipliers[i] * x to your score.
    Remove x from the array nums.

Return the maximum score after performing m operations.

ex1:
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.

ex2:
Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.

*/
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        nums_len = nums.size();
        multi_len = multipliers.size();
        myNums = nums;
        myMulti = multipliers;
        memo = std::vector<std::vector<int>> (multi_len, std::vector<int> (multi_len));
        
        return topDown(0, 0);
    }
private:
    std::vector<int> myNums;
    std::vector<int> myMulti;
    int nums_len;
    int multi_len;
    std::vector<std::vector<int>> memo;
    
    int topDown(int pos_now, int pos_left) {
        //base case
        if (pos_now == multi_len) {
            return 0;
        }
        
        int multiplier = myMulti[pos_now];
        int pos_right = nums_len - 1 - (pos_now - pos_left);
        
        if (memo[pos_now][pos_left] == 0) {
            memo[pos_now][pos_left] = std::max(multiplier * myNums[pos_left] + topDown(pos_now + 1, pos_left + 1), 
                                               multiplier * myNums[pos_right] + topDown(pos_now + 1, pos_left));
        }
        
        return memo[pos_now][pos_left];
    }
};