// 784. Letter Case Permutation
// https://leetcode.com/problems/letter-case-permutation/

// Runtime: 4 ms, faster than 99.39% of C++ online submissions for Letter Case Permutation.
// Memory Usage: 11.9 MB, less than 5.88% of C++ online submissions for Letter Case Permutation.

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if (S.empty()) return {};
        
        vector<string> a;
        if (isdigit(S[0])) a.emplace_back(string(1, S[0]));
        else {
            a.emplace_back(string(1, tolower(S[0])));
            a.emplace_back(string(1, toupper(S[0])));
        }
        if (S.length() == 1) return a;
        
        vector<string> v(letterCasePermutation(S.substr(1)));
        vector<string> ans;
        for (auto& s : a) {
            for (auto& t : v) {
                ans.push_back(s + t);
            }
        }
        return ans;
    }
};