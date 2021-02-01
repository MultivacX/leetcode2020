// 402. Remove K Digits

// Runtime: 24 ms, faster than 25.39% of C++ online submissions for Remove K Digits.
// Memory Usage: 105.1 MB, less than 9.09% of C++ online submissions for Remove K Digits.

class Solution {
public:
    string removeKdigits(string num, int k) {
        while (!num.empty() && num.front() == '0')
            num.erase(num.begin());
        if (num.length() <= k) 
            return "0";
        if (k == 0) 
            return num;
        // num.length() > k > 0
        for (int i = 0; i < num.length() - 1; ++i) {
            if (num[i] > num[i + 1]) {
                num.erase(num.begin() + i);
                return removeKdigits(num, k - 1);
            }
        }
        num.pop_back();
        return removeKdigits(num, k - 1);
    }
};