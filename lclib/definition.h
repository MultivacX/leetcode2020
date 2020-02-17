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


#endif // _lclib_definition_h_