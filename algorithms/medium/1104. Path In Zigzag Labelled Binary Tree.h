// 1104. Path In Zigzag Labelled Binary Tree

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Path In Zigzag Labelled Binary Tree.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Path In Zigzag Labelled Binary Tree.

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        if (label == 1) return {1};
        
        // l_bound_child = l_bound_root * 2
        // r_bound_child = r_bound_root * 2 + 1
        // root = child / 2
        
        vector<int> ans{label};
        vector<int> sum{1};
        int l_bound_root = 1;
        int r_bound_root = 1;
        while (ans.back() >> 1) {
            ans.push_back(ans.back() >> 1);
            
            l_bound_root = l_bound_root * 2;
            r_bound_root = r_bound_root * 2 + 1;
            sum.push_back(l_bound_root + r_bound_root);
        }
        reverse(begin(ans), end(ans));
        for (int i = (int)ans.size() - 2; i > 0; i -= 2) {
            ans[i] = sum[i] - ans[i];
        }
        return ans;
    }
};