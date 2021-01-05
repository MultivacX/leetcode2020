// 1256. Encode Number
// https://leetcode.com/problems/encode-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Encode Number.
// Memory Usage: 6.3 MB, less than 81.58% of C++ online submissions for Encode Number.
    
class Solution {
public:
    string encode(int num) {
        if (num <= 0) return "";
        string code;
        for (int i = 1, l = 0; i < 31; ++i) {
            int size = 1 << i;
            int r = l + size;
            if (l < num && num <= r) {
                if (num <= l + size / 2) code = "0" + encode(num - size / 2);
                else code = "1" + encode(num - size);
                break;
            }
            l += size;
        }
        return code;
    }
};