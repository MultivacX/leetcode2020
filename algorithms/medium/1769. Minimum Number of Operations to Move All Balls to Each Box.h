// 1769. Minimum Number of Operations to Move All Balls to Each Box
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Minimum Number of Operations to Move All Balls to Each Box.
// Memory Usage: 9.3 MB, less than 50.00% of C++ online submissions for Minimum Number of Operations to Move All Balls to Each Box.
    
class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.length();
        int left_cnt = 0, right_cnt = 0;
        int left_opt = 0, right_opt = 0;
        for (int i = 1; i < n; ++i) {
            if (boxes[i] == '0') continue;
            right_cnt += 1;
            right_opt += i;
        }
        
        vector<int> ans;
        ans.push_back(left_opt + right_opt);
        for (int i = 1; i < n; ++i) {
            if (boxes[i - 1] == '1') 
                left_cnt += 1;
            left_opt += left_cnt;
            
            right_opt -= right_cnt;
            if (boxes[i] == '1') 
                right_cnt -= 1;    
            
            ans.push_back(left_opt + right_opt);
        }
        return ans;
    }
};