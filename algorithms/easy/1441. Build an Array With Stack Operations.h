// 1441. Build an Array With Stack Operations

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Build an Array With Stack Operations.
// Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for Build an Array With Stack Operations.

// Time Complexity: O(target.back()).
// Space Complexity: O(target.size() + ans.size()).

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        vector<int> s(target.size(), 0);
        int num = 1;
        for (int i = 0; i < target.size(); ++i) {
            while (s[i] != target[i]) {
               if (s[i] != 0) ans.push_back("Pop");
                s[i] = num++; ans.push_back("Push");
            }
        }
        return ans;
    }
};