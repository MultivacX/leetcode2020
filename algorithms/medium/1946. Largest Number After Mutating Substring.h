// 1946. Largest Number After Mutating Substring
// https://leetcode.com/problems/largest-number-after-mutating-substring/

// Runtime: 72 ms, faster than 58.99% of C++ online submissions for Largest Number After Mutating Substring.
// Memory Usage: 28.6 MB, less than 94.69% of C++ online submissions for Largest Number After Mutating Substring.
    
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool mutate = false;
        int i = 0;
        while (!mutate && i < num.length()) {
            int v = num[i] - '0';
            if (v >= change[v]) {
                ++i;    
            } else {
                while (v <= change[v]) {
                    mutate = true;

                    num[i] = change[v] + '0';
                    if (++i == num.length()) break;
                    v = num[i] - '0';
                }
            }
        }
        return num;
    }
};