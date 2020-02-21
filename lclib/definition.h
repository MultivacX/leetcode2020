#ifndef _lclib_definition_h_
#define _lclib_definition_h_

/**
 * Definition for singly-linked list.
  */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
#endif // _lclib_definition_h_