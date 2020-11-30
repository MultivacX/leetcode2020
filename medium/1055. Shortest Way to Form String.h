// 1055. Shortest Way to Form String
// https://leetcode.com/problems/shortest-way-to-form-string/

// Runtime: 8 ms, faster than 29.59% of C++ online submissions for Shortest Way to Form String.
// Memory Usage: 7.1 MB, less than 30.87% of C++ online submissions for Shortest Way to Form String.
    
class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < source.length(); ++i)
            m[source[i]].push_back(i);
        
        int ans = 0;
        for (int i = 0, j = 2000; i < target.length(); ++i) {
            char c = target[i];
            if (m.count(c) == 0) return -1;
            auto it = upper_bound(begin(m[c]), end(m[c]), j);
            if (it != end(m[c])) {
                j = *it;
            } else {
                j = m[c][0];
                ++ans;
            }
            // cout << c << ":" << j << " ";
        }
        return ans;
    }
};