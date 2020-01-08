// 451. Sort Characters By Frequency

// Runtime: 24 ms, faster than 28.26% of C++ online submissions for Sort Characters By Frequency.
// Memory Usage: 11 MB, less than 58.82% of C++ online submissions for Sort Characters By Frequency.

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        auto cmp = [&](char left, char right) { return m[left] < m[right]; };
        priority_queue<char, vector<char>, decltype(cmp)> q(cmp);
        for (auto it : m) q.push(it.first);
        
        string ans;
        while (!q.empty()) {
            ans += string(m[q.top()], q.top());
            q.pop();
        }
        return ans;
    }
};