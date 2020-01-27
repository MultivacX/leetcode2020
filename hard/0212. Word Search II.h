// 212. Word Search II

class Solution {
public:
	// Time Limit Exceeded
	// 34 / 36 test cases passed.
    /*int m;
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
    }*/
};