// 555. Split Concatenated Strings
// https://leetcode.com/problems/split-concatenated-strings/

// Runtime: 56 ms, faster than 51.52% of C++ online submissions for Split Concatenated Strings.
// Memory Usage: 201.7 MB, less than 36.36% of C++ online submissions for Split Concatenated Strings.
    
class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string tmp;
        for (auto& s : strs) {
            string t(s); reverse(begin(t), end(t));
            if (s < t) reverse(begin(s), end(s));
            tmp += s;
        }
        // cout << tmp << endl << endl;
        
        const int N = strs.size();
        string ans(tmp);
        for (int i = 0, j = 0; i < N; ++i) {
            string& s = strs[i];
            string t(s); reverse(begin(t), end(t));
            string m(tmp.substr(j + s.length()) + tmp.substr(0, j));
            j += s.length();
            
            for (int k = 1; k <= s.length(); ++k) {
                string ss(s.substr(k) + m + s.substr(0, k));
                string tt(t.substr(k) + m + t.substr(0, k));
                if (ans < ss) ans = ss;
                if (ans < tt) ans = tt;
                // cout << ss << endl;
                // cout << tt << endl << endl;
            }
        }
        return ans;
    }
};