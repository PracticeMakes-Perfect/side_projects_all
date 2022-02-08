/*
258. Add Digits
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

constraints:
0 <= num <= 2^31 - 1
ex1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

ex2:
Input: num = 0
Output: 0
*/

class Solution {
public:
    int addDigits(int num) {
        /*
        std::vector<int> tmp {};
        int i = num;
        int j = i;
        int m = 0;
        while(j > 9) {
            while(i > 9) {
                tmp.push_back(i % 10);
                i = i / 10;    
            }
            
            tmp.push_back(i);
            for (int k = 0; k < tmp.size(); ++k) {
                m += tmp[k];
            }
            
            j = m;
            i = j;
            m = 0;
            tmp.clear();
        }
        
        return j;
        */
        
        /*
            mathematical solution is beautiful!
        */
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
    
};