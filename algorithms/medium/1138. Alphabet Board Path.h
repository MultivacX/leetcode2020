// 1138. Alphabet Board Path

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Alphabet Board Path.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Alphabet Board Path.

class Solution {
public:
    string alphabetBoardPath(string target) {
        static unordered_map<char, pair<int, int>> m{
            {'a', {0, 0}}, {'b', {0, 1}}, {'c', {0, 2}}, {'d', {0, 3}}, {'e', {0, 4}}, 
            {'f', {1, 0}}, {'g', {1, 1}}, {'h', {1, 2}}, {'i', {1, 3}}, {'j', {1, 4}}, 
            {'k', {2, 0}}, {'l', {2, 1}}, {'m', {2, 2}}, {'n', {2, 3}}, {'o', {2, 4}}, 
            {'p', {3, 0}}, {'q', {3, 1}}, {'r', {3, 2}}, {'s', {3, 3}}, {'t', {3, 4}}, 
            {'u', {4, 0}}, {'v', {4, 1}}, {'w', {4, 2}}, {'x', {4, 3}}, {'y', {4, 4}}, 
            {'z', {5, 0}},
        };
        
        // for (int i = 0; i < 5; ++i) {
        //     for (int j = 0; j < 5; ++j) {
        //         printf("{'%c', {%d, %d}}, ", 'a' + i * 5 + j, i, j);
        //     }
        //     cout << endl;
        // }
        
        string ans;
        char s = 'a';
        for (int i = 0; i < target.length(); ++i) {
            int si = m[s].first;
            int sj = m[s].second;
            
            char t = target[i];
            int ti = m[t].first;
            int tj = m[t].second;
            
            if (s == t) {
                
            } else if (s == 'z') {
                if (si - ti > 0) ans += string(si - ti, 'U');
                if (tj - sj > 0) ans += string(tj - sj, 'R');
            } else if (t == 'z') {
                if (sj - tj > 0) ans += string(sj - tj, 'L');
                if (ti - si > 0) ans += string(ti - si, 'D');
            } else {
                if (si - ti > 0) ans += string(si - ti, 'U');
                else if (ti - si > 0) ans += string(ti - si, 'D');
                if (tj - sj > 0) ans += string(tj - sj, 'R');
                else if (sj - tj > 0) ans += string(sj - tj, 'L');
            }
            
            s = t;
            ans += '!';
        }
        return ans;
    }
};