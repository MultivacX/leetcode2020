// 520. Detect Capital
// https://leetcode.com/problems/detect-capital/

// Runtime: 4 ms, faster than 38.46% of C++ online submissions for Detect Capital.
// Memory Usage: 6.4 MB, less than 12.03% of C++ online submissions for Detect Capital.

class Solution {
public:
    bool detectCapitalUse(string word) {
        const int N = word.length();
        if (N <= 1) return true;
        bool c = word[0] >= 'A' && word[0] <= 'Z';
        int cnt = 0;
        for (int i = 0; i < N; ++i) 
            if (word[i] >= 'A' && word[i] <= 'Z')
                ++cnt;
        return (c && (cnt == 1 || cnt == N)) || (!c && cnt == 0);
    }
};