// 66. Plus One
// https://leetcode.com/problems/plus-one/submissions/

// Runtime: 4 ms, faster than 44.50% of C++ online submissions for Plus One.
// Memory Usage: 8.7 MB, less than 67.21% of C++ online submissions for Plus One.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int val = carry + digits[i];
            carry = val / 10;
            ans.push_back(val % 10);
        }
        if (carry) ans.push_back(carry);
        reverse(begin(ans), end(ans));
        return ans;
    }
};