// 558. Logical OR of Two Binary Grids Represented as Quad-Trees
// https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/

// Runtime: 24 ms, faster than 87.18% of C++ online submissions for Logical OR of Two Binary Grids Represented as Quad-Trees.
// Memory Usage: 16.5 MB, less than 24.36% of C++ online submissions for Logical OR of Two Binary Grids Represented as Quad-Trees.

/*
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
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (!quadTree1) return quadTree2;
        if (!quadTree2) return quadTree1;
        
        Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (quadTree1->isLeaf && quadTree2->isLeaf) 
            return new Node(quadTree1->val | quadTree2->val, true);

        if (quadTree1->isLeaf) {
            if (quadTree1->val) return quadTree1;
            return quadTree2;
        }
        if (quadTree2->isLeaf) {
            if (quadTree2->val) return quadTree2;
            return quadTree1;
        }
        
        int leafs = (topLeft && topLeft->isLeaf ? 1 : 0) + 
                    (topRight && topRight->isLeaf ? 1 : 0) +
                    (bottomLeft && bottomLeft->isLeaf ? 1 : 0) +
                    (bottomRight && bottomRight->isLeaf ? 1 : 0);
        int leaf_val = (topLeft && topLeft->val ? 1 : 0) + 
                       (topRight && topRight->val ? 1 : 0) +
                       (bottomLeft && bottomLeft->val ? 1 : 0) +
                       (bottomRight && bottomRight->val ? 1 : 0);
        if (leafs == 4 && leaf_val == 4) return new Node(1, true);
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};