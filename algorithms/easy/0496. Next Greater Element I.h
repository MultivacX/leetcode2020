// 496. Next Greater Element I

// Runtime: 8 ms, faster than 98.19% of C++ online submissions for Next Greater Element I.
// Memory Usage: 8.9 MB, less than 89.47% of C++ online submissions for Next Greater Element I.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) return {};
        
        // vector<int> greater_idxs(nums2.size(), -1);
        // unordered_map<int, int> val2idx;
        unordered_map<int, int> m;
        stack<int> s;
        for (int i = 0; i < nums2.size(); ++i) {
            // val2idx.emplace(nums2[i], i);
            while (!s.empty() && nums2[s.top()] < nums2[i]) {
                // greater_idxs[s.top()] = i;
                m.emplace(nums2[s.top()], nums2[i]);
                s.pop();
            }
            s.push(i);
        }
        
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            // auto it = val2idx.find(nums1[i]);
            // if (it == val2idx.end() || greater_idxs[it->second] < 0) 
            //     continue;
            // ans[i] = nums2[greater_idxs[it->second]];
            auto it = m.find(nums1[i]);
            if (it == m.end())
                continue;
            ans[i] = it->second;
        }
        return ans;
    }
};