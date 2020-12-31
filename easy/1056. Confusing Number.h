// 1056. Confusing Number
// https://leetcode.com/problems/confusing-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Confusing Number.
// Memory Usage: 6.3 MB, less than 47.20% of C++ online submissions for Confusing Number.
    
class Solution {
public:
    bool confusingNumber(int N) {
        string s(to_string(N));
        for (auto& c : s) {
            if (c == '2' || c == '3' || c == '4' || c == '5' || c == '7')
                return false;
            if (c == '6') c = '9';
            else if (c == '9') c = '6';
        }
        reverse(begin(s), end(s));
        // cout << s << endl;
        return stoi(s) != N;
    }
};