// 476. Number Complement

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number Complement.
// Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Number Complement.

class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        bool find = false;
        for (int i = 30; i >= 0; --i) {
            if ((1 << i) & num) {
                find = true;
            } else if (find) {
                ans |= (1 << i);
            }
        }
        // cout << bitset<32>(num) << endl;
        // cout << bitset<32>(ans) << endl;
        return ans;
    }
};