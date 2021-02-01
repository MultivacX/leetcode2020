// 756. Pyramid Transition Matrix

// Runtime: 4 ms, faster than 92.64% of C++ online submissions for Pyramid Transition Matrix.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Pyramid Transition Matrix.

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<bitset<7>>> m(7, vector<bitset<7>>(7, bitset<7>(0)));
        for (const auto& s : allowed) {
            int a = s[0] - 'A';
            int b = s[1] - 'A';
            int c = s[2] - 'A';
            m[a][b].set(c);
        }
        
        vector<bitset<7>> level;
        for (int i = 1; i < bottom.size(); ++i) {
            int a = bottom[i - 1] - 'A';
            int b = bottom[i] - 'A';
            if (!m[a][b].any()) return false;
            level.push_back(m[a][b]);
        }
        while (level.size() > 1) {
            vector<bitset<7>> next_level;
            for (int i = 1; i < level.size(); ++i) {
                const bitset<7>& A = level[i - 1];
                const bitset<7>& B = level[i];
                bitset<7> C;
                for (int a = 0; a < 7; ++a)
                    for (int b = 0; b < 7; ++b)
                        if (A[a] && B[b] && m[a][b].any()) 
                            C |= m[a][b];
                if (!C.any()) return false;
                next_level.push_back(C);
            }
            level = next_level;
        }
        return level.size() == 1;
    }
};