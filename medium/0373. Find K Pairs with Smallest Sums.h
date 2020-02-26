// 373. Find K Pairs with Smallest Sums

// Runtime: 280 ms, faster than 21.51% of C++ online submissions for Find K Pairs with Smallest Sums.
// Memory Usage: 85.1 MB, less than 20.00% of C++ online submissions for Find K Pairs with Smallest Sums.

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) return {};
        const int s1 = nums1.size();
        if (s1 == 0) return {};
        const int s2 = nums2.size();
        if (s2 == 0) return {};
        
        auto cmp = [&](vector<int>& a, vector<int>& b) { return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        
        vector<vector<int>> ans;
        int step = 0;
        int cnt = 0;
        while (k > 0) {
            int i = 0;
            int j = step;
            while (i <= step && j >= 0 && cnt < s1 * s2) {
                if (i < s1 && j < s2) {
                    q.push({i, j});
                    ++cnt;
                }
                ++i;
                --j;
            }
            if (q.empty())
                break;
            ans.push_back({nums1[q.top()[0]], nums2[q.top()[1]]});
            q.pop();
            ++step;
            --k;
        }
        return ans;
    }
};