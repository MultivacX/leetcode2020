// 692. Top K Frequent Words

// Runtime: 20 ms, faster than 43.75% of C++ online submissions for Top K Frequent Words.
// Memory Usage: 11.4 MB, less than 94.44% of C++ online submissions for Top K Frequent Words.

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto i : words) ++m[i];
        auto cmp = [&](string& left, string& right) { return (m[left] > m[right]) || (m[left] == m[right] && left < right); };
        priority_queue<string, vector<string>, decltype(cmp)> q(cmp);
        for (auto it : m) {
            q.push(it.first);
            if (q.size() > k) q.pop();
        }
        vector<string> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};