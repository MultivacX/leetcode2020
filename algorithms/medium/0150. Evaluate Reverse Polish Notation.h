// 150. Evaluate Reverse Polish Notation

// Runtime: 16 ms, faster than 58.81% of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage: 11.5 MB, less than 100.00% of C++ online submissions for Evaluate Reverse Polish Notation.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = nums.top();
                nums.pop();
                if (token == "+") nums.top() += right;
                else if (token == "-") nums.top() -= right;
                else if (token == "*") nums.top() *= right;
                else nums.top() /= right;
            } else {
                nums.push(stoi(token));
            } 
        }
        return nums.top();
    }
};


class Solution {
    enum class EvalType { num, opt };
    
    struct EvalNode {
        virtual ~EvalNode() {}
        virtual int eval() = 0;
        
        EvalType et = EvalType::opt;
        EvalNode* left = nullptr;
        EvalNode* right = nullptr;
    };
    
    struct Num : public EvalNode {
        Num(const string& str) : num(stoi(str)) { et = EvalType::num; }
        virtual int eval() { return num; }
        int num;
    };
    
    struct Add : public EvalNode {
        // Add(EvalNode* l, EvalNode* r) : left(l), right(r) {}
        virtual int eval() { return left->eval() + right->eval(); }
    };
    
    struct Sub : public EvalNode {
        // Sub(EvalNode* l, EvalNode* r) : left(l), right(r) {}
        virtual int eval() { return left->eval() - right->eval(); }
    };
    
    struct Pdt : public EvalNode {
        // Pdt(EvalNode* l, EvalNode* r) : left(l), right(r) {}
        virtual int eval() { return left->eval() * right->eval(); }
    };
    
    struct Div : public EvalNode {
        // Div(EvalNode* l, EvalNode* r) : left(l), right(r) {}
        virtual int eval() { return left->eval() / right->eval(); }
    };
    
    EvalNode* create(const string& str) {
        if (str == "+") return new Add();
        if (str == "-") return new Sub();
        if (str == "*") return new Pdt();
        if (str == "/") return new Div();
        return new Num(str);
    }
    
    EvalNode* build(const vector<string>& tokens, int& i) {
        if (i < 0) return nullptr;
        
        auto root = create(tokens[i--]);
        if (root->et == EvalType::num) return root;
        
        root->right = build(tokens, i);
        root->left = build(tokens, i);
        
        return root;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        // 1 <= tokens.length
        int i = tokens.size() - 1;
        return build(tokens, i)->eval();
    }
};