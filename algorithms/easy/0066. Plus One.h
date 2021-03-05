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


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(begin(digits), end(digits));
        const int n = digits.size();
        int carry = 1;
        for (int i = 0; i < n; ++i) {
            int v = digits[i] + carry;
            carry = v / 10;
            digits[i] = v % 10;
        }
        if (carry > 0) digits.push_back(carry);
        reverse(begin(digits), end(digits));
        return digits;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int n = digits.size();
        int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            int v = digits[i] + carry;
            carry = v / 10;
            digits[i] = v % 10;
        }
        if (carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};