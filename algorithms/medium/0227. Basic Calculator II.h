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


class Solution {
    int getNum(const string& s, int n, int& i) {
        while (i < n && s[i] == ' ') ++i;
        int num = 0;
        while (i < n && isdigit(s[i])) 
            num = num * 10 - '0' + s[i++];
        return num;
    }
    
    char getOpt(const string& s, int n, int& i) {
        while (i < n && s[i] == ' ') ++i;
        return s[i++];
    }
    
public:
    int calculate(string s) {
        int n = s.length();
        while (n > 0 && s[n - 1] == ' ') --n;
        
        int i = 0;
        vector<int> nums{getNum(s, n, i)};
        while (i < n) {
            char opt = getOpt(s, n, i);
            int num = getNum(s, n, i);
            if (opt == '+') nums.push_back(num);
            else if (opt == '-') nums.push_back(-num);
            else if (opt == '*') nums.back() *= num;
            else nums.back() /= num;
        }
        return accumulate(begin(nums), end(nums), 0);
    }
};