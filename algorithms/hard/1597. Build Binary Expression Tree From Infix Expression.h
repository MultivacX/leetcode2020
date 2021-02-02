// 1597. Build Binary Expression Tree From Infix Expression
// https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Build Binary Expression Tree From Infix Expression.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Build Binary Expression Tree From Infix Expression.
    
/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void check(const string& s, int& i) {
        ++i;
        int cnt = 1;
        while (cnt > 0) {
            if (s[i] == '(') ++cnt;
            else if (s[i] == ')') --cnt;
            ++i;
        }
    }
    
public:
    Node* expTree(string s) {
        int N = s.length();
        if (s[0] == '(' && s[N - 1] == ')') {
            int i = 0;
            check(s, i);
            if (i == N) {
                N -= 2;
                s = s.substr(1, N);
            }
        }

        if (N == 0) return nullptr;
        if (N == 1) return new Node(s[0]);
        if (N == 2) return nullptr;
        if (N == 3) return new Node(s[1], new Node(s[0]), new Node(s[2]));
        
        int i = 0;
        int operand = -1;
        while (i < N) {
            if (s[i] == '+') {
                operand = i;
                break;
            } else if (s[i] == '-') {
                operand = i;
                ++i;
            } else if (s[i] == '*' || s[i] == '/') {
                if (operand < 0 || s[operand] != '-')
                    operand = i;
                ++i;
            } else if (isdigit(s[i])) {
                ++i;
            } else if (s[i] == '(') {
                check(s, i);
            }
        }
        return new Node(s[operand], expTree(s.substr(0, operand)), expTree(s.substr(operand + 1)));
    }
};