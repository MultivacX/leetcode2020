// 890. Find and Replace Pattern

// Runtime: 4 ms, faster than 87.86% of C++ online submissions for Find and Replace Pattern.
// Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Find and Replace Pattern.

// Time Complexity: O(size(words) * N).
// Space Complexity: O(size(words matche the pattern)).

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        const int N = pattern.length();
        vector<string> ans;
        unordered_map<char, char> p2w;
        unordered_map<char, char> w2p;
        for (const auto& word : words) {
            int i = 0;
            for (; i < N; ++i) {
                if (!p2w.count(pattern[i]) && !w2p.count(word[i])) {
                    p2w[pattern[i]] = word[i];
                    w2p[word[i]] = pattern[i];
                } else if (p2w.count(pattern[i]) && w2p.count(word[i])) {
                    if (p2w[pattern[i]] != word[i] || w2p[word[i]] != pattern[i])
                        break;
                } else {
                    break;
                }
            }
            // for (auto it : p2w) printf("%c:%c ", it.first, it.second); cout << endl;
            // for (auto it : w2p) printf("%c:%c ", it.first, it.second); cout << endl;
            p2w.clear();
            w2p.clear();
            
            if (i == N) ans.emplace_back(word);
        }
        return ans;
    }
};