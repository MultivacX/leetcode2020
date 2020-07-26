// 1297. Maximum Number of Occurrences of a Substring
// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

// Runtime: 1140 ms, faster than 9.36% of C++ online submissions for Maximum Number of Occurrences of a Substring.
// Memory Usage: 149.1 MB, less than 6.82% of C++ online submissions for Maximum Number of Occurrences of a Substring.

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        const int N = s.length();
        
        // optim: maxSize is useless cause substr[i, i+maxSize] includes substr[i, i+minSize], 
        //        count(substr[i, i+maxSize]) <= count(substr[i, i+minSize])
        unordered_map<string, int> substrs; // optim: string_view
        unordered_map<char, int> unique; // optim: array
        
        for (int i = 0, len = 0; i <= N - minSize; ++i) {
            while (i + len < N && unique.size() <= maxLetters) {
                char c = s[i + len];
                if (unique.count(c) || unique.size() + 1 <= maxLetters) {
                    ++unique[c];
                    ++len;
                } else {
                    break;
                }
            }
            
            for (int j = minSize; j <= min(len, maxSize); ++j)
                ++substrs[s.substr(i, j)];
            
            --unique[s[i]];
            if (unique[s[i]] == 0) unique.erase(s[i]);
            --len;
        }
        
        int ans = 0;
        for (const auto& it : substrs)
            ans = max(ans, it.second);
        return ans;
    }
};