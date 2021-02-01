// 315. Count of Smaller Numbers After Self

// Runtime: 92 ms, faster than 36.78% of C++ online submissions for Count of Smaller Numbers After Self.
// Memory Usage: 36.6 MB, less than 16.67% of C++ online submissions for Count of Smaller Numbers After Self.

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return {0};
        
        vector<int> ans(n, 0);
        vector<vector<int>> v(n, vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            v[i][0] = nums[i];
            v[i][1] = i;
        }
        merge(ans, v, 0, n);
        return ans;
    }
    
    void merge(vector<int>& ans, vector<vector<int>>& v, int begin, int end) {
        if (end - begin <= 1) return;
        
        int mid = begin + (end - begin) / 2;
        merge(ans, v, begin, mid);
        merge(ans, v, mid, end);

        // printf("[%d, %d)\n", begin, mid);
        // for (int i = begin; i < mid; ++i) cout << v[i][0] << ", ";
        // cout << endl;
        // printf("[%d, %d)\n", mid, end);
        // for (int i = mid; i < end; ++i) cout << v[i][0] << " ";
        // cout << endl;
        
        auto first = v.begin() + mid;
        auto last = v.begin() + end;
        for (int i = mid - 1; i >= begin && first != last; --i) {
            auto it = lower_bound(first, last, v[i]);
            if (it == first) break;
            ans[v[i][1]] += it - first;
        }
        
        inplace_merge(v.begin() + begin, v.begin() + mid, v.begin() + end);
    }
};

// Time Limit Exceeded
// 16 / 16 test cases passed, but took too long.
/*class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        multiset<int> s;
        for (int i = nums.size() - 1; i >= 0; --i) {
            auto it = s.lower_bound(nums[i]);
            if (it == s.end()) {
                ans.push_back(s.size());
            } else {
                ans.push_back(distance(s.begin(), it));
            }
            s.insert(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};*/