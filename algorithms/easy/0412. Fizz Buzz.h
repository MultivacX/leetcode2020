// 412. Fizz Buzz
// https://leetcode.com/problems/fizz-buzz/

// Runtime: 4 ms, faster than 84.78% of C++ online submissions for Fizz Buzz.
// Memory Usage: 8.3 MB, less than 19.28% of C++ online submissions for Fizz Buzz.
    
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i)
            if (i % 15 == 0) ans.push_back("FizzBuzz");
            else if (i % 5 == 0) ans.push_back("Buzz");
            else if (i % 3 == 0) ans.push_back("Fizz");
            else ans.push_back(to_string(i));
        return ans;
    }
};


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            bool a = i % 5, b = i % 3;
            if (a + b == 0) ans.push_back("FizzBuzz");
            else if (a == 0) ans.push_back("Buzz");
            else if (b == 0) ans.push_back("Fizz");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for (int i = 1; i <= n; ++i) {
            bool a = i % 5, b = i % 3;
            if (a + b == 0) ans[i - 1] = "FizzBuzz";
            else if (a == 0) ans[i - 1] = "Buzz";
            else if (b == 0) ans[i - 1] = "Fizz";
            else ans[i - 1] = to_string(i);
        }
        return ans;
    }
};