// 1433. Check If a String Can Break Another String

// Runtime: 80 ms, faster than 97.34% of C++ online submissions for Check If a String Can Break Another String.
// Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Check If a String Can Break Another String.

// Time Complexity: O(s1.length() + s2.length()).
// Space Complexity: O(1).

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> p1(26, 0);
        for (const char& c : s1) ++p1[c - 'a'];
        
        vector<int> p2(26, 0);
        for (const char& c : s2) ++p2[c - 'a'];
        
        int break_state = 0;
        int used = 0;
        int i = 0;
        int j = 0;
        while (i < 26 && j < 26) {
            if (p1[i] == 0) { ++i; continue; }
            if (p2[j] == 0) { ++j; continue; }
            
            if (i != j) {
                if (break_state == 0) break_state = i < j ? -1 : 1;
                else if (i < j && break_state != -1) return false;
                else if (i > j && break_state != 1) return false;
            }
            
            int cnt = min(p1[i], p2[j]);
            p1[i] -= cnt;
            p2[j] -= cnt;
            used += cnt;
        }
        return used == s1.length();
    }
};