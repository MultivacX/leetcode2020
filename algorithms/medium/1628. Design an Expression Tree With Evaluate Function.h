// 1628. Design an Expression Tree With Evaluate Function
// https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Design an Expression Tree With Evaluate Function.
// Memory Usage: 10.7 MB, less than 17.41% of C++ online submissions for Design an Expression Tree With Evaluate Function.
    
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};

class Exp : public Node {
public:
    Exp(const string& v) : val(v) {}
    string val;
    Node* left;
    Node* right;
    
    int evaluate() const {
        if (val == "+") return left->evaluate() + right->evaluate();
        if (val == "-") return left->evaluate() - right->evaluate();
        if (val == "*") return left->evaluate() * right->evaluate();
        if (val == "/") return left->evaluate() / right->evaluate();
        return stoi(val);
    }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
    Node* buildTree(const vector<string>& postfix, int& i) {
        if (i < 0) return nullptr;
        
        Exp* node = new Exp(postfix[i--]);
        if (node->val == "+" || node->val == "-" || node->val == "*" || node->val == "/") {
            node->right = buildTree(postfix, i);
            node->left = buildTree(postfix, i);
        }
        return node;
    }
    
public:
    Node* buildTree(vector<string>& postfix) {
        int i = postfix.size() - 1;
        return buildTree(postfix, i);
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */