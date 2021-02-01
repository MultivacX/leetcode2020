// 670. Maximum Swap
// https://leetcode.com/problems/maximum-swap/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Swap.
// Memory Usage: 6 MB, less than 52.90% of C++ online submissions for Maximum Swap.

class Solution {
public:
    int maximumSwap(int num) {
        vector<vector<int>> v(10);
        string s(to_string(num));
        for (int i = s.length() - 1; i > 0; --i) 
            v[s[i] - '0'].push_back(i);
        
        for (int i = 0; i < s.length() - 1; ++i) {
            int val = s[i] - '0';
            for (int j = 9; j > val; --j) {
                while (!v[j].empty() && v[j].back() <= i) v[j].pop_back();
                if (v[j].empty()) continue;
                swap(s[i], s[v[j].front()]);
                return stoi(s);
            }
        }
        return stoi(s);
    }
};