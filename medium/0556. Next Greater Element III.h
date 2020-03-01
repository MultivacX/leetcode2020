// 556. Next Greater Element III

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Greater Element III.
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Next Greater Element III.

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n <= 10) 
            return -1;
        
        vector<int> v{n % 10};
        n /= 10;
        while (n) {
            int cur = n % 10;
            n /= 10;
            if (v.back() <= cur) {
                v.push_back(cur);
                continue;
            }
            auto it = upper_bound(v.begin(), v.end(), cur);
            int64_t ans = *it + n * 10;
            *it = cur;
            for (int i = 0; i < v.size(); ++i) {
                ans = ans * 10 + v[i];
            }
            return ans > (int64_t)INT_MAX ? -1 : ans;
        }
        
        return -1;
    }
};