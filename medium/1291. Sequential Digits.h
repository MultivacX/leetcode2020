// 1291. Sequential Digits

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sequential Digits.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Sequential Digits.

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string ls(to_string(low));
        string hs(to_string(high));
        for (int i = ls.length(); i <= hs.length(); ++i) {
            for (char c = '1'; c + i - 1 <= '9'; ++c) {
                string s(i, ' ');
                for (int j = 0; j < i; ++j) {
                    s[j] = c + j;
                }
                int d = stoi(s);
                if (d >= low && d <= high)
                    ans.push_back(d);
            }
        }
        return ans;
    }
};