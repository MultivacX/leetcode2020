// 415. Add Strings

// Runtime: 4 ms, faster than 92.54% of C++ online submissions for Add Strings.
// Memory Usage: 9 MB, less than 69.57% of C++ online submissions for Add Strings.

class Solution {
public:
    string addStrings(string num1, string num2) {
        const int len1 = num1.length();
        if (len1 == 0) return num2;
        const int len2 = num2.length();
        if (len2 == 0) return num1;
        
        int carry = 0;
        string ans;
        int i = 0;
        while (i < len1 && i < len2) {
            int v = (num1[len1 - i - 1] - '0') + (num2[len2 - i - 1] - '0') + carry;
            carry = v / 10;
            v = v % 10;
            ans += (v + '0');
            ++i;
        }
        while (i < len1) {
            int v = (num1[len1 - i - 1] - '0') + carry;
            carry = v / 10;
            v = v % 10;
            ans += (v + '0');
            ++i;
        }
        while (i < len2) {
            int v = (num2[len2 - i - 1] - '0') + carry;
            carry = v / 10;
            v = v % 10;
            ans += (v + '0');
            ++i;
        }
        if (carry > 0) {
            ans += (carry + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};