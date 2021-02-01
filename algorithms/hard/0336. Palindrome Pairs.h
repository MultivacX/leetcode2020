// 336. Palindrome Pairs
// https://leetcode.com/problems/palindrome-pairs/

// Runtime: 460 ms, faster than 53.65% of C++ online submissions for Palindrome Pairs.
// Memory Usage: 50.8 MB, less than 52.63% of C++ online submissions for Palindrome Pairs.

class Solution {
    bool isPalindrome(string word) {
        int i = 0;
        int j = word.length() - 1;
        while (i < j) {
            if (word[i] != word[j]) return false;
            ++i, --j;
        }
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int N = words.size();
        
        unordered_map<string, int> m;
        for (int i = 0; i < N; ++i) m[words[i]] = i;
        
        unordered_set<uint64_t> visited; // i * N + j
        
        for (int i = 0; i < N; ++i) {
            string l(words[i]);
            reverse(begin(l), end(l));
            string r(l);
            
            while (true) {
                if (m.count(l) && i != m[l] && !visited.count(i * N + m[l]) && isPalindrome(l + words[i])) {
                    // cout << l << " + " << words[i] << endl;
                    visited.insert(m[l] * N + i);
                }
                if (l.empty()) break;
                l.pop_back();
            }
            
            while (true) {
                if (m.count(r) && i != m[r] && !visited.count(i * N + m[r]) && isPalindrome(words[i] + r)) {
                    // cout << words[i] << " + " << r << endl;
                    visited.insert(i * N + m[r]);
                }
                if (r.empty()) break;
                r = r.substr(1);
            }
        }
        
        vector<vector<int>> ans;
        for (uint64_t key : visited) ans.push_back({(int)(key / N), (int)(key % N)});
        return ans;
    }
};