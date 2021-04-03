// 488. Zuma Game
// https://leetcode.com/problems/zuma-game/

// Runtime: 48 ms, faster than 83.46% of C++ online submissions for Zuma Game.
// Memory Usage: 8.3 MB, less than 84.96% of C++ online submissions for Zuma Game.
    
class Solution {
    string h;
    
    string update(string board) {
        while (board.length() >= 3) {
            const int n = board.length();
            int i = 0;
            while (i < board.length()) {
                int j = i + 1;
                const int color = board[i];
                while (j < board.length() && color == board[j]) ++j;
                const int count = j - i;
                if (count >= 3) board = board.substr(0, i) + board.substr(j);
                i = j;
            }
            if (n == board.length()) break;
        }
        return board;
    } 
    
    int dfs(string board, string& hand, int k) {
        int ans = 6;
        for (int i = k; i < hand.length(); ++i) {
            if (i > k && hand[i - 1] == hand[i]) continue;
            
            for (int j = 0; j < board.length(); ++j) {
                if (j > 0 && board[j - 1] == hand[i]) continue;
                string nb(update(board.substr(0, j) + hand[i] + board.substr(j)));
                if (nb.empty()) return 1;
                if (i + 1 == hand.length()) continue;
                int r = 1 + dfs(nb, hand, i + 1);
                if (r < ans) ans = r;
            }
        }
        return ans;
    }
    
public:
    int findMinStep(string board, string hand) {
        sort(begin(hand), end(hand));
        int ans = dfs(board, hand, 0);
        return ans == 6 ? -1 : ans;
    }
};


// WA
// "RRWWRRBBRR"
// "WB"
class Solution {
    vector<int> h = vector<int>(1 + 'Z');
    
    string update(string board) {
        while (board.length() >= 3) {
            const int n = board.length();
            int i = 0;
            while (i < n) {
                int j = i + 1;
                const int color = board[i];
                while (j < n && color == board[j]) ++j;
                const int count = j - i;
                if (count >= 3) board = board.substr(0, i) + board.substr(j);
                i = j;
            }
            if (n == board.length()) break;
        }
        return board;
    } 
    
    int dfs(string board) {
        const int n = board.length();
        int ans = 6;
        int i = 0;
        while (i < n) {
            const int color = board[i];
            int j = i + 1;
            while (j < n && color == board[j]) ++j;
            const int count = 3 - (j - i);
            if (h[color] >= count) {
                h[color] -= count;
                string nb = update(board.substr(0, i) + board.substr(j));
                if (nb.empty()) return count;
                int r = count + dfs(nb);
                if (r < ans) ans = r;
                h[color] += count;
            }
            i = j;
        }
        return ans;
    }
    
public:
    int findMinStep(string board, string hand) {
        for (char c : hand) ++h[c];
        int ans = dfs(board);
        return ans == 6 ? -1 : ans;
    }
};