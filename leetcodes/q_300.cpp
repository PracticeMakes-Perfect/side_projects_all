/*
Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements 
without changing the order of the remaining elements. 

Constraints:
	1 <= nums.length <= 2500
    -104 <= nums[i] <= 104

For example, 
[3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

ex1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

ex2:
Input: nums = [0,1,0,3,2,3]
Output: 4

ex:3
Input: nums = [7,7,7,7,7,7,7]
Output: 1

*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        
        maxLen = 0;
        numsLen = nums.size();
        
        
        maxLenOfIndex = new int[numsLen];
        myNums = nums;
        
        for (int i = 0; i < numsLen; ++i) {
            maxLenOfIndex[i] = 0;
        }
        
        maxLenOfIndex[numsLen - 1] = 1;

        return topDown(numsLen);
    }
    
private:
    int maxLen;
    int* maxLenOfIndex;
    int numsLen;
    std::vector<int> myNums;
    
    int topDown(int len) {
        int maxSub = 0;
        
        for (int j = len - 2; j > -1; --j) {
            for (int i = j + 1; i < len; ++i) {
                if (myNums[j] < myNums[i]) {
                    maxSub = std::max(maxSub, maxLenOfIndex[i]);
                }
            }
            
            if (maxSub == 0)
                maxLenOfIndex[j] = 1;
            else
                maxLenOfIndex[j] = 1 + maxSub;
            
            if (maxLenOfIndex[j] > maxLen)
                maxLen = maxLenOfIndex[j];
            
            maxSub = 0;
        }
        
        
        return maxLen;
    }
    
};