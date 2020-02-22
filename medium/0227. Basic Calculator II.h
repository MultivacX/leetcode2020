// 227. Basic Calculator II

// Runtime: 16 ms, faster than 59.27% of C++ online submissions for Basic Calculator II.
// Memory Usage: 11.5 MB, less than 39.29% of C++ online submissions for Basic Calculator II.

class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> opts;
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                if (opts.empty() || opts.back() == '+' || opts.back() == '-') {
                    nums.push_back(num);
                    opts.push_back(s[i]);   
                } else {
                    if (opts.back() == '*') nums.back() *= num;
                    else if (opts.back() == '/') nums.back() /= num;
                    opts.back() = s[i];
                }
                num = 0;
            } else if (s[i] == '*' || s[i] == '/') {
                if (!opts.empty() && (opts.back() == '*' || opts.back() == '/')) {
                    if (opts.back() == '*') nums.back() *= num;
                    else if (opts.back() == '/') nums.back() /= num;
                    opts.back() = s[i];
                } else {
                    nums.push_back(num);
                    opts.push_back(s[i]);    
                }
                num = 0;
            }
        }
        
        if (nums.empty()) {
            return num;
        } else if (opts.back() == '*') {
            nums.back() *= num;
            opts.pop_back();
        } else if (opts.back() == '/') {
            nums.back() /= num;
            opts.pop_back();
        } else {
            nums.push_back(num);
        }
        
        int ans = nums[0];
        for (int i = 0; i < nums.size() - 1; ++i) {
            ans += opts[i] == '+' ? nums[i + 1] : -nums[i + 1];
        }
        return ans;
    }
};