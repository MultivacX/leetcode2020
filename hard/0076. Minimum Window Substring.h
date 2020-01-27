// 76. Minimum Window Substring

// Runtime: 28 ms, faster than 44.30% of C++ online submissions for Minimum Window Substring.
// Memory Usage: 10.5 MB, less than 44.00% of C++ online submissions for Minimum Window Substring.

class Solution {
public:
	string minWindow(string s, string t) {
        if (/*s.empty() || */t.empty() || s.length() < t.length()) return "";
        
        const int all = t.length();
        int cnt = 0;
        unordered_map<char, int> m, tmp;
        for (char c : t) ++m[c];
        
        string ans;
        int l = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (m.count(c) == 0) continue;
            
            ++tmp[c];
            if (tmp[c] <= m[c]) ++cnt;
            
            if (cnt == all) {
                while (l < i) {
                    if (m.count(s[l]) == 0) ++l; 
                    else if (tmp[s[l]] > m[s[l]]) --tmp[s[l++]];
                    else break;
                }
                
                if (ans.empty() || ans.length() > i - l + 1) 
                    ans = s.substr(l, i - l + 1);
                --cnt;
                --tmp[s[l++]];
            }
        }
        return ans;
    }

	// WRONG
	// 193 / 268 test cases passed.
	/*"aaaaaaaaaaaabbbbbcdd"
	"abcdd"
	"abbbbbcdd"*/
    /*string minWindow(string s, string t) {
        if (t.empty() || s.length() < t.length()) return "";
        
        const int all = t.length();
        int cnt = 0;
        unordered_map<char, int> m, tmp;
        for (char c : t) ++m[c];
        
        string ans;
        int l = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (m.count(c) == 0) continue;
            
            while (l < i && m.count(s[l]) == 0) ++l;
            
            ++cnt;
            ++tmp[c];
            
            if (tmp[c] == m[c]) {
                if (cnt == all) {
                    if (ans.empty() || ans.length() > i - l + 1) 
                        ans = s.substr(l, i - l + 1);
                    --cnt;
                    --tmp[s[l++]];
                }
            } else if (tmp[c] > m[c]) {
                while (s[l] != c) {
                    if (tmp.count(s[l])) {
                        --cnt;
                        --tmp[s[l]];
                    }
                    ++l;
                }
                --cnt;
                --tmp[s[l++]];
            }
        }
        return ans;
    }*/
};