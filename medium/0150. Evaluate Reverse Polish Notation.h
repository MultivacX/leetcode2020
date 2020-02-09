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