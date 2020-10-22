// 1090. Largest Values From Labels
// https://leetcode.com/problems/largest-values-from-labels/

// Runtime: 88 ms, faster than 31.14% of C++ online submissions for Largest Values From Labels.
// Memory Usage: 20.2 MB, less than 8.01% of C++ online submissions for Largest Values From Labels.

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<array<int, 2>> q(values.size());
        for (int i = 0; i < values.size(); ++i) {
            q[i][0] = values[i];
            q[i][1] = labels[i];
        }
        sort(begin(q), end(q));
        unordered_map<int, int> m;
        int ans = 0;
        while (num_wanted > 0 && !q.empty()) {
            int value = q.back()[0];
            int label = q.back()[1];
            // printf("value:%d, label:%d, count:%d\n", value, label, m[label]);
            if (m[label] < use_limit) {
                --num_wanted;
                ans += value;
                ++m[label];
            }
            q.pop_back();
        }
        return ans;
    }
};

// Runtime: 88 ms, faster than 31.14% of C++ online submissions for Largest Values From Labels.
// Memory Usage: 20.5 MB, less than 8.01% of C++ online submissions for Largest Values From Labels.

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        priority_queue<array<int, 2>> q;
        for (int i = 0; i < values.size(); ++i) 
            q.push(array<int, 2>{values[i], labels[i]});
        unordered_map<int, int> m;
        int ans = 0;
        while (num_wanted > 0 && !q.empty()) {
            int value = q.top()[0];
            int label = q.top()[1];
            // printf("value:%d, label:%d, count:%d\n", value, label, m[label]);
            if (m[label] < use_limit) {
                --num_wanted;
                ans += value;
                ++m[label];
            }
            q.pop();
        }
        return ans;
    }
};