// 1461. Check If a String Contains All Binary Codes of Size K
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

// Runtime: 204 ms, faster than 93.57% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
// Memory Usage: 22.9 MB, less than 100.00% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int N = s.length();
        int substrs = N - k + 1;
        int codes = 1 << k;
        if (codes > substrs) return false;
        
        int mask = 0;
        unordered_set<int> visited;
        int val = 0;
        for (int i = 0; i < k; ++i) {
            val = (val << 1) | (s[i] - '0');
            mask = (mask << 1) | 1;
        }
        visited.insert(val);
        // cout << bitset<32>(mask) << " " << codes << " " << substrs << endl;
        --substrs;
        --codes;
        // cout << bitset<32>(val) << " " << codes << " " << substrs << endl;
        
        for (int i = k; i < N && codes > 0; ++i) {
            val = (val << 1) | (s[i] - '0');
            val &= mask;
            --substrs;
            if (!visited.count(val)) {
                visited.insert(val);    
                --codes;
            }
            // cout << bitset<32>(val) << " " << codes << " " << substrs << endl;
            if (codes > substrs) return false;
        }
        return visited.size() == (1 << k);
    }
};