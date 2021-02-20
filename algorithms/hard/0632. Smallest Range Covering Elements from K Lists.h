// 632. Smallest Range Covering Elements from K Lists
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

// Runtime: 68 ms, faster than 65.98% of C++ online submissions for Smallest Range Covering Elements from K Lists.
// Memory Usage: 14.5 MB, less than 91.78% of C++ online submissions for Smallest Range Covering Elements from K Lists.

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int n = nums.size();
        // nums[i][j]
        
        auto num = [&](pair<int, int>& l){ return nums[l.first][l.second]; };
        
        auto cmp_min = [&](pair<int, int>& l, pair<int, int>& r) { 
            return num(l) > num(r); 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp_min)> q(cmp_min);
        
        pair<int, int> l = {0, 0}, r = {0, 0};
        for (int i = 0; i < n; ++i) {
            q.push({i, 0});
            if (num(l) > nums[i][0]) l = {i, 0};
            if (num(r) < nums[i][0]) r = {i, 0};
        }
        vector<int> ans{num(l), num(r)};
        
        while (true) {
            int i = q.top().first;
            int j = q.top().second + 1;
            q.pop();
            
            if (j == nums[i].size()) break;
            
            q.push({i, j});
            l = q.top();
            if (num(r) < nums[i][j]) r = {i, j};
            if (ans[1] - ans[0] > num(r) - num(l)) 
                ans = {num(l), num(r)};
        }
        
        return ans;
    }
};

// WA
// 86 / 88 test cases passed.
class Solution {
    vector<int> f0(vector<vector<int>>& nums) {
        const int n = nums.size();
        // nums[i][j]
        
        int b = INT_MIN;
        auto cmp_max = [&](pair<int, int>& l, pair<int, int>& r) { 
            return nums[l.first][l.second] < nums[r.first][r.second]; 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp_max)> q(cmp_max);
        for (int i = 0; i < n; ++i) q.push({i, nums[i].size() - 1});
        while (true) {
            int i = q.top().first;
            int j = q.top().second;
            q.pop();
            if (j == 0) {
                b = nums[i][j];
                break;
            }
            q.push({i, --j});
        }
        
        int a = INT_MAX;
        auto cmp_min = [&](pair<int, int>& l, pair<int, int>& r) { 
            return nums[l.first][l.second] > nums[r.first][r.second]; 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp_min)> p(cmp_min);
        for (int i = 0; i < n; ++i) p.push({i, 0});
        while (true) {
            int i = p.top().first;
            int j = p.top().second;
            p.pop();
            if (j + 1 == nums[i].size() || nums[i][j + 1] > b) {
                a = nums[i][j];
                break;
            }
            p.push({i, ++j});
        }
        
        return {a, b};
    }

    vector<int> f1(vector<vector<int>>& nums) {
        const int n = nums.size();
        // nums[i][j]
        
        int a = INT_MAX;
        auto cmp_min = [&](pair<int, int>& l, pair<int, int>& r) { 
            return nums[l.first][l.second] > nums[r.first][r.second]; 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp_min)> p(cmp_min);
        for (int i = 0; i < n; ++i) p.push({i, 0});
        while (true) {
            int i = p.top().first;
            int j = p.top().second;
            p.pop();
            if (j + 1 == nums[i].size()) {
                a = nums[i][j];
                break;
            }
            p.push({i, ++j});
        }
        
        int b = INT_MIN;
        auto cmp_max = [&](pair<int, int>& l, pair<int, int>& r) { 
            return nums[l.first][l.second] < nums[r.first][r.second]; 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp_max)> q(cmp_max);
        for (int i = 0; i < n; ++i) q.push({i, nums[i].size() - 1});
        while (true) {
            int i = q.top().first;
            int j = q.top().second;
            q.pop();
            if (j == 0 || nums[i][j - 1] < a) {
                b = nums[i][j];
                break;
            }
            q.push({i, --j});
        }
        
        return {a, b};
    }

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto r0 = f0(nums);
        auto r1 = f1(nums);
        cout << r0[0] << ", " << r0[1] << endl;
        cout << r1[0] << ", " << r1[1] << endl;
        if (r0[1] - r0[0] == r1[1] - r1[0]) return r0[0] < r1[0] ? r0 : r1;
        return r0[1] - r0[0] < r1[1] - r1[0] ? r0 : r1;
    }
};