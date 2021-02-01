// 405. Convert a Number to Hexadecimal

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert a Number to Hexadecimal.
// Memory Usage: 8.3 MB, less than 28.57% of C++ online submissions for Convert a Number to Hexadecimal.

class Solution {
public:
    string toHex(int num) {
        const static vector<string> v{
            "0", "1", "2", "3", 
            "4", "5", "6", "7",
            "8", "9", "a", "b",
            "c", "d", "e", "f",
        };
        
        string ans;
        for (int i = 32 - 4; i >= 0; i -= 4) {
            unsigned int n = 15 & ((unsigned int)num >> i);
            // cout << bitset<32>(n) << " : " << n << endl;
            if (n == 0 && ans.empty()) continue;
            ans.append(v[n]);
        }
        if (ans.empty()) return "0";
        return ans;
    }
};