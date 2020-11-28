// 249. Group Shifted Strings
// https://leetcode.com/problems/group-shifted-strings/

// Runtime: 8 ms, faster than 45.52% of C++ online submissions for Group Shifted Strings.
// Memory Usage: 8.7 MB, less than 24.76% of C++ online submissions for Group Shifted Strings.
    
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (const auto& val : strings) {
            if (val[0] == 'a') {
                m[val].push_back(val);
            } else {
                int offset = 'z' - val[0] + 1;
                string key(val);
                for (char& c : key) c = (c - 'a' + offset + 26) % 26 + 'a';
                m[key].push_back(val);
                // cout << key << ":" << val << endl;
            }
        }
        vector<vector<string>> ans;
        for (auto it : m) ans.push_back(it.second);
        return ans;
    }
};