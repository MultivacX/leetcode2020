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


// WA: ["abc","ab"]
class Solution {
    unordered_map<char, unordered_set<char>> parents;
    unordered_map<char, unordered_set<char>> children;
    
    void visit(const vector<string>& words, int i, int j, int k) {
        while (i <= j && words[i].length() <= k) ++i;
        while (i <= j && words[j].length() <= k) --j;
        if (i >= j) return;
        
        for (int x = i, p = -1; x <= j; ++x) {
            if (words[x].length() <= k) p = -1;
            else if (p == -1) p = x;
            else if (words[p][k] != words[x][k]) {
                children[words[p][k]].insert(words[x][k]);
                parents[words[x][k]].insert(words[p][k]);
                p = x;
            }
        }
        
        for (int x = i, p = i; x <= j; ++x) {
            if (words[x].length() <= k) {
                if (x - p > 1) visit(words, p, x - 1, k + 1);
                p = x + 1;
            } else if (words[p][k] != words[x][k]) {
                if (x - p > 1) visit(words, p, x - 1, k + 1);
                p = x;
            } else if (x == j) {
                if (x > p) visit(words, p, x, k + 1);
            }
        }
    }
    
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> letters;
        for (const auto& w : words) for (char c : w) letters.insert(c);
        
        visit(words, 0, words.size() - 1, 0);
        
        // for (char c : letters) cout << c; cout << endl;
        // for (const auto& it : children) {
        //     cout << it.first << ": ";
        //     for (char c : it.second) cout << c; cout << endl;
        // }
        
        queue<char> q;
        for (char c : letters) if (parents.count(c) == 0) q.push(c);
        
        string ans;
        
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                char cur = q.front(); q.pop();
                ans += cur;
                
                if (children.count(cur) == 0) 
                    continue;
                
                for (char nxt : children[cur]) {
                    parents[nxt].erase(cur);
                    if (parents[nxt].empty()) {
                        parents.erase(nxt);
                        q.push(nxt);
                    }
                }
                children.erase(cur);
            }
        }
        
        return ans.length() == letters.size() ? ans : "";
    }
};


class Solution {
    unordered_map<char, unordered_set<char>> parents;
    unordered_map<char, unordered_set<char>> children;
    
    bool visit(const vector<string>& words, int i, int j, int k) {
        while (i <= j && words[i].length() <= k) ++i;
        while (i <= j && words[j].length() <= k) --j;
        if (i >= j) return true;
        
        for (int x = i, p = -1; x <= j; ++x) {
            if (words[x].length() <= k) {
                p = -1;
            } else if (p == -1) {
                p = x;
            } else if (words[p][k] != words[x][k]) {
                children[words[p][k]].insert(words[x][k]);
                parents[words[x][k]].insert(words[p][k]);
                p = x;
            } else if (words[x - 1].length() > words[x].length() && words[x].length() == k + 1) {
                return false;
            }
        }
        
        for (int x = i, p = i; x <= j; ++x) {
            if (words[x].length() <= k) {
                if (x - p > 1 && !visit(words, p, x - 1, k + 1))
                    return false;
                p = x + 1;
            } else if (words[p][k] != words[x][k]) {
                if (x - p > 1 && !visit(words, p, x - 1, k + 1))
                    return false;
                p = x;
            } else if (x == j) {
                if (x > p && !visit(words, p, x, k + 1))
                    return false;
            }
        }
        
        return true;
    }
    
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> letters;
        for (const auto& w : words) for (char c : w) letters.insert(c);
        
        if (!visit(words, 0, words.size() - 1, 0)) return "";
        
        // for (char c : letters) cout << c; cout << endl;
        // for (const auto& it : children) {
        //     cout << it.first << ": ";
        //     for (char c : it.second) cout << c; cout << endl;
        // }
        
        queue<char> q;
        for (char c : letters) if (parents.count(c) == 0) q.push(c);
        
        string ans;
        
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                char cur = q.front(); q.pop();
                ans += cur;
                
                if (children.count(cur) == 0) 
                    continue;
                
                for (char nxt : children[cur]) {
                    parents[nxt].erase(cur);
                    if (parents[nxt].empty()) {
                        parents.erase(nxt);
                        q.push(nxt);
                    }
                }
                children.erase(cur);
            }
        }
        
        return ans.length() == letters.size() ? ans : "";
    }
};