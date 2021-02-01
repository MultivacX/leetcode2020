// 1065. Index Pairs of a String
// https://leetcode.com/problems/index-pairs-of-a-string/

// Runtime: 4 ms, faster than 93.81% of C++ online submissions for Index Pairs of a String.
// Memory Usage: 8.3 MB, less than 94.69% of C++ online submissions for Index Pairs of a String.
    
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        for (const auto& w : words) {
            const int L = w.length();
            auto i = text.find(w, 0);
            while (i != string::npos) {
                ans.push_back({(int)i, (int)i + L - 1});
                i = text.find(w, i + 1);
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};