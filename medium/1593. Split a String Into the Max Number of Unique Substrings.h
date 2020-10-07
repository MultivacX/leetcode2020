// 1593. Split a String Into the Max Number of Unique Substrings
// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

// Runtime: 292 ms, faster than 85.58% of C++ online submissions for Split a String Into the Max Number of Unique Substrings.
// Memory Usage: 44.2 MB, less than 54.75% of C++ online submissions for Split a String Into the Max Number of Unique Substrings.

class Solution {
    unordered_set<string> subs;
    
    int maxUniqueSplit(const string& s, int p) {
        const int N = s.length();
        if (p >= N) return 0;
        
        int ans = 0;
        for (int i = 1; i + p <= N; ++i) {
            auto it = subs.insert(s.substr(p, i));
            if (!it.second) continue;
            
            ans = max(ans, 1 + maxUniqueSplit(s, i + p));
            subs.erase(it.first);
        }
        return ans;
    }
    
public:
    int maxUniqueSplit(string s) {
        return maxUniqueSplit(s, 0);
    }
};