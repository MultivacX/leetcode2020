// 2232. Minimize Result by Adding Parentheses to Expression
// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/

// Runtime: 2 ms, faster than 43.94% of C++ online submissions for Minimize Result by Adding Parentheses to Expression.
// Memory Usage: 5.9 MB, less than 83.20% of C++ online submissions for Minimize Result by Adding Parentheses to Expression.

class Solution
{
public:
    string minimizeResult(string expression)
    {
        const int n = expression.length();
        int k = 0;
        while (expression[k] != '+')
            ++k;

        string res;
        int min_val = INT_MAX;
        for (int i = 0; i < k; ++i)
        {
            int a, b;
            if (i == k - 1)
            {
                a = 1;
                b = stoi(expression.substr(0, k));
            }
            else
            {
                a = stoi(expression.substr(0, i + 1));
                b = stoi(expression.substr(i + 1, k - i - 1));
            }

            for (int j = k + 1; j < n; ++j)
            {
                int c, d;
                if (j == n - 1)
                {
                    c = stoi(expression.substr(k + 1));
                    d = 1;
                }
                else
                {
                    c = stoi(expression.substr(k + 1, j - k));
                    d = stoi(expression.substr(j + 1));
                }

                int val = a * (b + c) * d;
                if (min_val > val)
                {
                    min_val = val;

                    res = "";
                    if (i == k - 1)
                    {
                        res += "(" + expression.substr(0, k) + "+";
                    }
                    else
                    {
                        res += expression.substr(0, i + 1) + "(" + expression.substr(i + 1, k - i - 1) + "+";
                    }

                    if (j == n - 1)
                    {
                        res += expression.substr(k + 1) + ")";
                    }
                    else
                    {
                        res += expression.substr(k + 1, j - k) + ")" + expression.substr(j + 1);
                    }
                }
            }
        }
        return res;
    }
};