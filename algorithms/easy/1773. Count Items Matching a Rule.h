// 1773. Count Items Matching a Rule
// https://leetcode.com/problems/count-items-matching-a-rule/

// Runtime: 64 ms, faster than 100.00% of C++ online submissions for Count Items Matching a Rule.
// Memory Usage: 31.1 MB, less than 25.00% of C++ online submissions for Count Items Matching a Rule.
    
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        static const unordered_map<string, int> keys{
            {"type", 0}, {"color", 1}, {"name", 2}
        };
        
        int i = keys.at(ruleKey);
        int cnt = 0;
        for (const auto& item : items)
            if (item[i] == ruleValue)
                ++cnt;
        return cnt;
    }
};