/*
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

Return the maximum number of points you can earn by applying the above operation some number of times.

ex1:
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

ex2:
Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            //init hashmap
            if (points.find(nums[i]) != points.end()) {
                points[nums[i]] += nums[i];
            } else {
                points[nums[i]] = nums[i];
            }
            
            maxNum = std::max(maxNum, nums[i]);
        }
        
        return maxPoints(maxNum);
    }
    
private:
    std::unordered_map<int, int> points;
    std::unordered_map<int, int> memo;
    
    int maxPoints(int num) {
        //base cases 0
        if (num == 0) {
            return 0;
        }
        // case 1
        if (num == 1) {
            if (points.find(1) != points.end()) {
                return points[1];
            } else {
                return 0;
            }
        }
        //return from cache if it exists
        if (memo.find(num) != memo.end()) {
            return memo[num];
        }
        
        //use the recurrence relation
        int gain = (points.find(num) != points.end()) ? points[num] : 0;
        memo[num] = std::max(maxPoints(num - 1), maxPoints(num - 2) + gain);
        
        return memo[num];
    }
};