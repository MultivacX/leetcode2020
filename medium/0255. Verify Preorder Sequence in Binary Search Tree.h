// 255. Verify Preorder Sequence in Binary Search Tree
// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/

// Runtime: 1556 ms, faster than 11.74% of C++ online submissions for Verify Preorder Sequence in Binary Search Tree.
// Memory Usage: 22.8 MB, less than 61.41% of C++ online submissions for Verify Preorder Sequence in Binary Search Tree.
    
class Solution {
    bool verify(vector<int>& preorder, int start, int end) {
        // [start, end)
        if (start + 1 >= end) return true;
        
        int root = preorder[start];
        
        // left: [start+1, i)
        int i = start + 1;
        while (i < end && preorder[i] < root) ++i;
        if (!verify(preorder, start + 1, i)) return false;
        
        // right: [i, end)
        for (int j = i; j < end; ++j)
            if (preorder[j] < root) return false;
        return verify(preorder, i, end);
    }
    
public:
    bool verifyPreorder(vector<int>& preorder) {
        return verify(preorder, 0, preorder.size());
    }
};