// 347. Top K Frequent Elements

// Runtime: 20 ms, faster than 80.75% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 11.3 MB, less than 96.77% of C++ online submissions for Top K Frequent Elements.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // auto cmp = [](pair<int, int>& left, pair<int, int>& right) { return left.first < right.first; };
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        unordered_map<int, int> m;
        for (int i : nums) ++m[i];
        auto cmp = [&](int left, int right) { return m[left] > m[right]; };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (auto it : m) {
            q.push(it.first);
            if (q.size() > k) q.pop();
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};