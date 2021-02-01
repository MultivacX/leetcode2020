// 1157. Online Majority Element In Subarray
// https://leetcode.com/problems/online-majority-element-in-subarray/

// Runtime: 272 ms, faster than 95.05% of C++ online submissions for Online Majority Element In Subarray.
// Memory Usage: 72.3 MB, less than 6.59% of C++ online submissions for Online Majority Element In Subarray.

class MajorityChecker {
    // { {num, idx0, idx1, ... }, ... }
    vector<vector<int>> _arr;
    
public:
    MajorityChecker(vector<int>& arr) {
        // {num, {idx0, idx1, ... }}
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < arr.size(); ++i) {
            if (m[arr[i]].empty())
                m[arr[i]].push_back(arr[i]);
            m[arr[i]].push_back(i);   
        }
        for (auto it : m) _arr.push_back(it.second);
        sort(begin(_arr), end(_arr), [](vector<int>& a, vector<int>& b){
            return a.size() > b.size();
        });
    }
    
    int query(int left, int right, int threshold) {
        for (auto& v : _arr) {
            // v[0] : num
            // v[1], ... : index
            if (v.size() < 1 + threshold) break;
            auto l = lower_bound(begin(v) + 1, end(v), left);
            if (l == end(v)) continue;
            auto r = upper_bound(begin(v) + 1, end(v), right);
            auto cnt = distance(l, r);
            if (cnt >= threshold) return v[0];
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */

// Time Limit Exceeded
// 26 / 27 test cases passed.
class MajorityChecker {
    vector<int>& arr_;
    
public:
    MajorityChecker(vector<int>& arr) : arr_(arr) {
        
    }
    
    int query(int left, int right, int threshold) {
        int val = arr_[left];
        int cnt = 1;
        for (int i = left + 1; i <= right; ++i) {
            if (val == arr_[i]) {
                ++cnt;
            } else if (cnt == 0) {
                val = arr_[i];
                ++cnt;
            } else {
                --cnt;
            }
        }
        cnt = 0;
        for (int i = left; i <= right; ++i) {
            if (val == arr_[i]) ++cnt;
            if (cnt >= threshold) return val;
        }
        return -1;
    }
};