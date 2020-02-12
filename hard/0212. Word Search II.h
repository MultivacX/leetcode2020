// 212. Word Search II

// Runtime: 48 ms, faster than 84.93% of C++ online submissions for Word Search II.
// Memory Usage: 35.9 MB, less than 25.00% of C++ online submissions for Word Search II.

class Trie {
public:
    Trie(int i = -1, Trie* p = nullptr) : idx(i), parent(p) {}
    
    int idx;
    Trie* parent;
    Trie* children[26] = {nullptr};
    int count = 0;
    string word;
    
    static void buildTrie(const string& s, int idx, Trie* root) {
        if (s.empty()) 
            return;
        if (idx == s.length()) {
            root->word = s;
            return;
        }
        
        int i = s[idx] - 'a';
        if (!root->children[i]) {
            ++root->count;
            root->children[i] = new Trie(i, root);   
        }
        buildTrie(s, idx + 1, root->children[i]);
    }
    
    static void eraseTrie(Trie* node) {
        node->word.clear();
        while (node && node->idx > -1) {
            auto parent = node->parent;
            if (node->count == 0) {
                if (parent) --parent->count;
            } else {
                break;
            }
            node = parent;
        }
    }
};

class Solution {
public:
    int m;
    int n;
    Trie* root = new Trie;
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.empty()) return {};
        m = board.size();
        if (m == 0) return {};
        n = board[0].size();
        if (n == 0) return {};
        
        for (const string& word : words)
            Trie::buildTrie(word, 0, root);
        
        vector<string> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                find(board, i, j, root, ans);
            }
        }
        return ans;
    }
    
    void find(vector<vector<char>>& board, int i, int j, Trie* root, vector<string>& ans) {
        if (i < 0 || i >= m || j < 0 || j >= n || !root || root->count <= 0 || board[i][j] == '#') return;
        
        char c = board[i][j];
        int idx = c - 'a';
        auto node = root->children[idx];
        if (!node) return;
        if (!node->word.empty()) {
            ans.push_back(node->word);
            Trie::eraseTrie(node);
        }

        board[i][j] = '#';
        
        find(board, i - 1, j, node, ans);
        find(board, i + 1, j, node, ans);
        find(board, i, j - 1, node, ans);
        find(board, i, j + 1, node, ans);
        
        board[i][j] = c;
    }
};

// Time Limit Exceeded
// 34 / 36 test cases passed.
/*class Solution {
public:	
    int m;
    int n;
    array<unordered_set<int>, 26> a;
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.empty()) return {};
        m = board.size();
        if (m == 0) return {};
        n = board[0].size();
        if (n == 0) return {};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a[board[i][j] - 'a'].insert(i * n + j);
            }
        }
        
        vector<string> ans;
        for (const string& word : words) {
            if (word.empty()) 
                continue;
            
            int w0 = word[0] - 'a';
            if (a[w0].empty()) 
                continue;
            
            for (int rc : a[w0]) {
                unordered_set<int> visited;
                if (find(visited, board, word, 1, rc)) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
    
    bool find(unordered_set<int>& visited, vector<vector<char>>& board, const string& word, int i, int rc) {
        if (visited.count(rc))
            return false;
        if (i >= word.length())
            return true;
        visited.insert(rc);
        
        int r = rc / n;
        int c = rc % n;
        
        if (r - 1 >= 0 && board[r - 1][c] == word[i] && find(visited, board, word, i + 1, (r - 1) * n + c)) return true;
        if (r + 1 <  m && board[r + 1][c] == word[i] && find(visited, board, word, i + 1, (r + 1) * n + c)) return true;
        if (c - 1 >= 0 && board[r][c - 1] == word[i] && find(visited, board, word, i + 1, r * n + (c - 1))) return true;
        if (c + 1 <  n && board[r][c + 1] == word[i] && find(visited, board, word, i + 1, r * n + (c + 1))) return true;
        
        visited.erase(rc);
        return false;
    }
};*/