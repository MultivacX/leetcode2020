// 1002. Find Common Characters
// https://leetcode.com/problems/find-common-characters/

// Runtime: 12 ms, faster than 64.78% of C++ online submissions for Find Common Characters.
// Memory Usage: 9.9 MB, less than 49.86% of C++ online submissions for Find Common Characters.
    
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        const int N = A.size();
        vector<int> m(26, 0);
        for (int i = 0; i < N; ++i) {
            vector<int> n(26, 0);
            for (char c : A[i]) 
                ++n[c - 'a'];
            if (i == 0) m = n;
            else for (int j = 0; j < 26; ++j) {
                if (m[j] == 0) continue;
                int k = m[j] / i;
                m[j] = min(k, n[j]) * (i + 1);
            }
            // for (int j = 0; j < 26; ++j) if (n[j]) printf("%c%d ", j+'a', n[j]); cout << endl;
            // for (int j = 0; j < 26; ++j) if (m[j]) printf("%c%d ", j+'a', m[j]); cout << endl;
            // cout << endl;
        }
        vector<string> ans;
        for (int j = 0; j < 26; ++j)
            for (int i = 0; i < m[j] / N; ++i)
                ans.emplace_back(1, (char)(j + 'a'));
        return ans;
    }
};