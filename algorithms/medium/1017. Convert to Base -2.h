// 1017. Convert to Base -2

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert to Base -2.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Convert to Base -2.

class Solution {
public:
    string baseNeg2(int N) {
        string ans;
        while (N) {
            ans.push_back((N & 1) ? '1' : '0');
            N = -(N >> 1);
            // cout << bitset<32>(N) << "  " << N << endl;
        }
        if (ans.empty()) return "0";
        reverse(begin(ans), end(ans));
        return ans;
    }
};