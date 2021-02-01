// 916. Word Subsets

// Runtime: 280 ms, faster than 31.97% of C++ online submissions for Word Subsets.
// Memory Usage: 81.2 MB, less than 75.00% of C++ online submissions for Word Subsets.

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> b(26, 0);
        for (const auto& s : B) {
            vector<int> t(26, 0);
            for (const auto& c : s) ++t[c - 'a'];
            for (int i = 0; i < 26; ++i) b[i] = max(b[i], t[i]);
        }
        int L = 0;
        for (int i = 0; i < 26; ++i) L += b[i];
        
        vector<string> ans;
        for (const auto& s : A) {
            if (s.length() < L) continue;
            
            vector<int> a(26, 0);
            for (const auto& c : s) ++a[c - 'a'];
            
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (a[i] < b[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(s);
        }
        return ans;
    }
};