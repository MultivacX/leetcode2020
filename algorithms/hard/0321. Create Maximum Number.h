// 321. Create Maximum Number
// https://leetcode.com/problems/create-maximum-number/

// Runtime: 244 ms, faster than 40.93% of C++ online submissions for Create Maximum Number.
// Memory Usage: 26.6 MB, less than 65.84% of C++ online submissions for Create Maximum Number.
    
class Solution {
    vector<int> maxNumber(const vector<int>& nums, int k) {
        if (k <= 0) return {};
        
        const int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int size = ans.size();
            while (size > 0 && size + n - i > k && ans.back() < nums[i]) {
                ans.pop_back();
                --size;
            }
            ans.push_back(nums[i]);
        }
        ans.resize(k);
        return ans;
    }
    
    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        if (nums1.size() == 0) return nums2;
        if (nums2.size() == 0) return nums1;
        
        vector<int> ans(nums1.size() + nums2.size());
        int k = 0;
        while (nums1.size() + nums2.size()) {
            auto& cur = nums1 > nums2 ? nums1 : nums2;
            ans[k++] = cur[0];
            cur.erase(cur.begin());
        }
        return ans;
    }
    
    // nums1 < nums2
    bool less(const vector<int>& nums1, const vector<int>& nums2) {
        const int n = nums1.size();
        for (int i = 0; i < n; ++i)
            if (nums1[i] != nums2[i])
                return nums1[i] < nums2[i];
        return false;
    }
    
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k <= 0) return {};
        const int m = nums1.size();
        const int n = nums2.size();
        if (k >= m + n) return merge(nums1, nums2);
        
        vector<int> ans(k, 0);
        for (int k1 = 0, k2 = k - k1; k1 <= m; ++k1, --k2) {
            // printf("%d:%d %d:%d\n", k1, m, k2, n);
            if (k2 < 0 || k2 > n) continue;
            
            vector<int> n1 = maxNumber(nums1, k1);
            vector<int> n2 = maxNumber(nums2, k2);
            vector<int> cur = merge(n1, n2);
            if (less(ans, cur)) ans = cur;
            
            // for (int i : n1) cout << i; cout << endl;
            // for (int i : n2) cout << i; cout << endl;
            // for (int i : cur) cout << i; cout << endl;
            // cout << endl;
        }
        return ans;
    }
};