// 973. K Closest Points to Origin

// Runtime: 668 ms, faster than 15.30% of C++ online submissions for K Closest Points to Origin.
// Memory Usage: 46.2 MB, less than 51.56% of C++ online submissions for K Closest Points to Origin.

// Time Complexity: O(N*lgK).
// Space Complexity: O(K).

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [&](vector<int>& i, vector<int>& j) { return i[0] * i[0] + i[1] * i[1] < j[0] * j[0] + j[1] * j[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (const auto& p : points) {
            q.push(p);
            while (q.size() > K) q.pop();
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [&](int i, int j) { 
            return points[i][0] * points[i][0] + points[i][1] * points[i][1] < 
                   points[j][0] * points[j][0] + points[j][1] * points[j][1]; 
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        
        for (int i = 0; i < points.size(); ++i) {
            q.push(i);
            if (q.size() > k)
                q.pop();
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(points[q.top()]);
            q.pop();
        }
        return ans;
    }
};