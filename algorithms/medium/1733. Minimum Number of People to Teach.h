// 1733. Minimum Number of People to Teach
// https://leetcode.com/problems/minimum-number-of-people-to-teach/

// Runtime: 956 ms, faster than 15.62% of C++ online submissions for Minimum Number of People to Teach.
// Memory Usage: 265.9 MB, less than 5.03% of C++ online submissions for Minimum Number of People to Teach.
    
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        const int m = languages.size();
        vector<unordered_set<int>> L(n + 1);
        for (int i = 0; i < m; ++i) 
            for (int l : languages[i])
                L[l].insert(i + 1);
        
        vector<vector<int>> F;
        for (const auto& f : friendships) {
            const auto& u = languages[f[0] - 1];
            const auto& v = languages[f[1] - 1];
            unordered_set<int> s(begin(u), end(u));
            copy(begin(v), end(v), inserter(s, s.end()));
            if (s.size() == u.size() + v.size())
                F.push_back(f);
        }
        
        int ans = m;
        for (int l = 1; l <= n; ++l) {
            unordered_set<int> students;
            for (const auto& f : F) {
                if (L[l].count(f[0]) == 0) 
                    students.insert(f[0]);
                if (L[l].count(f[1]) == 0)
                    students.insert(f[1]);
            }
            ans = min(ans, (int)students.size());
        }
        return ans;
    }
};