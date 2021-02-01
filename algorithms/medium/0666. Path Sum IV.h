// 666. Path Sum IV
// https://leetcode.com/problems/path-sum-iv/

// Runtime: 4 ms, faster than 72.41% of C++ online submissions for Path Sum IV.
// Memory Usage: 10.4 MB, less than 83.91% of C++ online submissions for Path Sum IV.
    
class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_map<int, int> nodes;
        vector<pair<int, int>> leaves;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int d = nums[i] / 100;
            int p = nums[i] / 10 % 10;
            int v = nums[i] % 10;
            nodes.insert({nums[i] / 10, v});
            
            int leaf_d = d + 1;
            int leaf_l = leaf_d * 10 + 2 * p - 1;
            int leaf_r = leaf_l + 1;
            if (nodes.count(leaf_l) == 0 && nodes.count(leaf_r) == 0)
                leaves.push_back({nums[i] / 10, v});
        }
        int sum = 0;
        for (int i = 0; i < leaves.size(); ++i) {
            int d = leaves[i].first / 10;
            int p = leaves[i].first % 10;
            int v = leaves[i].second;
            do {
                sum += v;
                --d;
                p = (p + 1) / 2;
                int k = d * 10 + p;
                if (nodes.count(k))
                    v = nodes[k];
            } while (d);
        }
        return sum;
    }
};