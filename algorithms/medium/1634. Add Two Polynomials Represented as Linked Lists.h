// 1634. Add Two Polynomials Represented as Linked Lists
// https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/

// Runtime: 168 ms, faster than 78.95% of C++ online submissions for Add Two Polynomials Represented as Linked Lists.
// Memory Usage: 39.3 MB, less than 84.87% of C++ online submissions for Add Two Polynomials Represented as Linked Lists.
    
/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode head;
        auto p = &head;
        while (poly1 && poly2) {
            if (poly1->power == poly2->power) {
                int c = poly1->coefficient + poly2->coefficient;
                if (c != 0) {
                    poly1->coefficient = c;
                    p->next = poly1;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
                if (c != 0) {
                    p = p->next;
                    p->next = nullptr;
                }
            } else if (poly1->power > poly2->power) {
                p->next = poly1;
                poly1 = poly1->next;
                p = p->next;
                p->next = nullptr;
            } else {
                p->next = poly2;
                poly2 = poly2->next;
                p = p->next;
                p->next = nullptr;
            }
            
        }
        while (poly1) {
            p->next = poly1;
            poly1 = poly1->next;
            p = p->next;
            p->next = nullptr;
        }
        while (poly2) {
            p->next = poly2;
            poly2 = poly2->next;
            p = p->next;
            p->next = nullptr;
        }
        return head.next;
    }
};