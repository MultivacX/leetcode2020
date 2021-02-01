// 424. Longest Repeating Character Replacement

// Runtime: 176 ms, faster than 5.19% of C++ online submissions for Longest Repeating Character Replacement.
// Memory Usage: 50.2 MB, less than 6.90% of C++ online submissions for Longest Repeating Character Replacement.

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (k < 0) return 0;
        const int n = s.length();
        if (n <= k) return n;

        int i = 0;
        int len = 1;
        int letter = s[i] - 'A';
        
        // {letter - 'A', cnt}
        int v[26] = {0}; 
        v[letter] = 1;

        // {cnt, {letters - 'A'}}
        map<int, unordered_set<int>> m; 
        m[1].insert(letter); 

        for (int j = 1; j < n; ++j) {
            int max_cnt = m.rbegin()->first;

            // add s[j]
            letter = s[j] - 'A';
            int pre_cnt = v[letter];
            if (m.count(pre_cnt)) {
                m[pre_cnt].erase(letter);
                if (m[pre_cnt].empty()) m.erase(pre_cnt);
            }
            int cur_cnt = ++v[letter];
            m[cur_cnt].insert(letter);

            if (max_cnt < cur_cnt) max_cnt = cur_cnt;
            int cur_len = j - i + 1;
            int must_be_replaced = cur_len - max_cnt;
            if (must_be_replaced <= k) {
                len = max(len, cur_len);
            } else {
                // remove s[i]
                letter = s[i++] - 'A';
                pre_cnt = v[letter];
                m[pre_cnt].erase(letter);
                if (m[pre_cnt].empty()) m.erase(pre_cnt);
                cur_cnt = --v[letter];
                if (cur_cnt > 0) m[cur_cnt].insert(letter);
            }
        }

        return len;
    }
};