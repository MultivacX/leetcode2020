// 427. Construct Quad Tree
// https://leetcode.com/problems/construct-quad-tree/

// Runtime: 24 ms, faster than 41.19% of C++ online submissions for Construct Quad Tree.
// Memory Usage: 16.1 MB, less than 75.52% of C++ online submissions for Construct Quad Tree.

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
    
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<Node*>> nodes(N, vector<Node*>(N, nullptr));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                nodes[i][j] = new Node(grid[i][j], true);
            
        
        while (N > 1) {
            N >>= 1;
            vector<vector<Node*>> parents(N, vector<Node*>(N, nullptr));

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    Node* topLeft = nodes[i * 2][j * 2];
                    Node* topRight = nodes[i * 2][j * 2 + 1];
                    Node* bottomLeft = nodes[i * 2 + 1][j * 2];
                    Node* bottomRight = nodes[i * 2 + 1][j * 2 + 1];
                    int val = topLeft->val + topRight->val + bottomLeft->val + bottomRight->val;
                    int leaf = topLeft->isLeaf + topRight->isLeaf + bottomLeft->isLeaf + bottomRight->isLeaf;
                    if (leaf == 4 && (val == 0 || val == 4)) {
                        parents[i][j] = new Node(val, true);
                        delete topLeft, delete topRight, delete bottomLeft, delete bottomRight;
                    } else {
                        parents[i][j] = new Node(val, false, topLeft, topRight, bottomLeft, bottomRight);
                    }
                }
            }
            
            nodes = parents;
        }
        return nodes[0][0];
    }
};