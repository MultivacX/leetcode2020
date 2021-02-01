// 49. Group Anagrams

// Runtime: 40 ms, faster than 78.94% of C++ online submissions for Group Anagrams.
// Memory Usage: 20 MB, less than 53.73% of C++ online submissions for Group Anagrams.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            auto v = s;
            sort(s.begin(), s.end());
            m[s].push_back(v);
        }
        
        vector<vector<string>> ans;
        for_each(m.begin(), m.end(), [&ans](pair<string, vector<string>> element){
			ans.push_back(element.second);
		});
        return ans;
    }
};