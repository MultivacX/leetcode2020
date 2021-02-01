// 267. Palindrome Permutation II
// https://leetcode.com/problems/palindrome-permutation-ii/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Palindrome Permutation II.
// Memory Usage: 7.2 MB, less than 38.46% of C++ online submissions for Palindrome Permutation II.
    
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        const int N = s.size();
        if (N == 0) return {};
        if (N == 1) return {s};
        
        unordered_map<char, int> m;
        for (char c : s) ++m[c];    
        char odd = '\0';
        for (auto it : m) {
            if (it.second & 1) {
                if (odd != '\0') return {};
                odd = it.first;
            }
        }
        if (odd != '\0' && --m[odd] == 0) m.erase(odd); 
        
        vector<string> ans;
        string p(N / 2, odd);
        int i = 0;
        for (auto it : m) {
            int l = it.second / 2;
            fill_n(p.begin() + i, l, it.first);
            i += l;
        }
        sort(p.begin(), p.end());
        do {
            string t(p);
            reverse(t.begin(), t.end());
            if (odd != '\0') ans.push_back(p + odd + t);
            else ans.push_back(p + t);
        } while(next_permutation(p.begin(), p.end()));
        return ans;
    }
};