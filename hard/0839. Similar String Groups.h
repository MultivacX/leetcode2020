// 839. Similar String Groups
// https://leetcode.com/problems/similar-string-groups/

// Runtime: 32 ms, faster than 86.94% of C++ online submissions for Similar String Groups.
// Memory Usage: 13.2 MB, less than 64.41% of C++ online submissions for Similar String Groups.
    
class Solution {
    bool anagram(const string& a, const string& b) {
        const int N = a.length();
        char ca = 0, cb = 0;
        int diff = 0;
        for (int i = 0; i < N; ++i) {
            if (a[i] == b[i]) continue;
            if (ca == 0) ca = a[i], cb = b[i];
            else if (ca != b[i] || cb != a[i]) return false;
            if (++diff > 2) return false;
        }
        return diff == 0 || diff == 2;
    }
    
    int find(vector<int>& parents, int i) {
        if (parents[i] != i) parents[i] = find(parents, parents[i]);
        return parents[i];
    }
    
    void connect(vector<int>& parents, int i, int j) {
        parents[find(parents, i)] = parents[find(parents, j)];
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        unordered_set<string> s(begin(strs), end(strs));
        vector<string> strs_(begin(s), end(s));
        
        const int N = strs_.size();
        vector<int> parents(N);
        for (int i = 0; i < N; ++i)
            parents[i] = i;
        
            
        for (int i = 0; i + 1 < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (anagram(strs[i], strs[j])) {
                    connect(parents, i, j);
                }
            }
        }
        // for (int i = 0; i < N; ++i) cout << i << " -> " << find(parents, i) << endl;
        
        unordered_set<int> ans;
        for (int i = 0; i < N; ++i) ans.insert(find(parents, i));
        return ans.size();
    }
};