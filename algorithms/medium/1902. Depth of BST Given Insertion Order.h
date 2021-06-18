// 1902. Depth of BST Given Insertion Order
// https://leetcode.com/problems/depth-of-bst-given-insertion-order/

// Runtime: 640 ms, faster than 100.00% of C++ online submissions for Depth of BST Given Insertion Order.
// Memory Usage: 165.8 MB, less than 100.00% of C++ online submissions for Depth of BST Given Insertion Order.
    
class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        const int n = order.size();
        
        vector<int> depths(n + 2, 0);
        set<int> nodes{0, n + 1};
        
        int ans = 1;
        for (int i : order) {
            auto it = nodes.upper_bound(i);
            int g = *it;
            int l = *(--it);
            depths[i] = max(depths[l], depths[g]) + 1;
            nodes.insert(i);
            ans = max(ans, depths[i]);
        }
        return ans;
    }
};


// WA: TLE
// 65 / 70 test cases passed.
class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        const int n = order.size();
        vector<array<int, 2>> tree(n + 1, array<int, 2>{0, 0});
        int root = order[0];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int d = 1;
            int cur = order[0];
            while (true) {
                ++d;
                int& l = tree[cur][0];
                int& r = tree[cur][1];
                if (order[i] < cur) {
                    if (l == 0) {
                        l = order[i];
                        break;
                    } else {
                        cur = l;
                    }
                } else {
                    if (r == 0) {
                        r = order[i];
                        break;
                    } else {
                        cur = r;
                    }
                }
            }
            ans = max(ans, d);
        }
        return ans;
    }
};