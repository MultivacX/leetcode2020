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


class Solution {
    struct segment_tree {
        const int n;
        vector<int> tree;

        segment_tree(vector<int>& nums) : n(nums.size()), tree(nums.size() << 1, 0) {
            for (int i = 0; i < n; ++i)
                tree[n + i] = nums[i];
            for (int i = n - 1; i > 0; --i)
                tree[i] = tree[i << 1] + tree[i << 1 ^ 1];
        }

        void update(int i, int diff) {
            for (int j = n + i; j > 0; j >>= 1)
                tree[j] += diff;
        }

        int query(int l, int r) {
            int sum = 0;
            // [l, r)
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) sum += tree[l++];
                if (r & 1) sum += tree[--r];
            }
            return sum;
        }
        };
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        map<int, int> m;
        for (int i : nums) m[i];
        int idx = 0;
        for (auto& it : m) it.second = idx++;
        const int N = m.size();
        vector<int> v(N);
        segment_tree tree(v);
        
        vector<int> ans(nums.size());
        for (int j = nums.size() - 1; j >= 0; --j) {
            int i = m[nums[j]];
            tree.update(i, 1);
            ans[j] = tree.query(0, i);
        }
        return ans;
    }
};