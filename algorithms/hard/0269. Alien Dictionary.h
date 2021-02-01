// 269. Alien Dictionary
// https://leetcode.com/problems/alien-dictionary/

// Runtime: 8 ms, faster than 55.75% of C++ online submissions for Alien Dictionary.
// Memory Usage: 10.3 MB, less than 14.17% of C++ online submissions for Alien Dictionary.
    
class Solution {
    // a < {b}
    unordered_map<char, unordered_set<char>> m;
    unordered_set<char> used;
    
    bool compare(const string& l, const string& r) {
        const int M = l.size();
        const int N = r.size();
        int i = 0;
        while (i < M && i < N) {
            if (l[i] != r[i]) {
                m[l[i]].insert(r[i]);
                return true;
            }
            ++i;
        }
        return M <= N;
    }
    
    bool dfs(int& cnt, char root, char c, int& visited) {
        if (root == c) return false;
        
        int i = 1 << (c - 'a');
        if (visited & i) return true;
        visited |= i;
        
        // cout << c << ' ';
        
        ++cnt;
        if (m.count(c))
        for (char cc : m[c]) {
            if (!dfs(cnt, root, cc, visited))
                return false;
        }
        return true;
    }
    
public:
    string alienOrder(vector<string>& words) {
        const int N = words.size();
        for (int i = 0; i < N; ++i) {
            for (char c : words[i])
                used.insert(c);
            if (i + 1 < N && !compare(words[i], words[i + 1]))
                return "";
        }
        
        // for (char c : used) cout << c << ' '; cout << endl << endl;
        // for (auto it : m) {
        //     cout << it.first << " < " << " ";
        //     for (char c : it.second) cout << c << ' '; 
        //     cout << endl;
        // } cout << endl;
        
        map<int, unordered_set<char>> sucs;
        for (auto it : m) {
            char root = it.first;
            int cnt = 0;
            int visited = 0;
            // cout << root << " < " << " ";
            for (char c : it.second)
                if (!dfs(cnt, root, c, visited)) 
                   return "";
            sucs[cnt].insert(root);
            // cout << endl;
        }
        for (char c : used) if (m.count(c) == 0) sucs[0].insert(c);
        string ans;
        for (auto it = sucs.rbegin(); it != sucs.rend(); ++it) 
            for (char c : it->second) ans += c;   
        return ans;
    }
};
