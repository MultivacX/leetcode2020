// 990. Satisfiability of Equality Equations

// Runtime: 4 ms, faster than 96.33% of C++ online submissions for Satisfiability of Equality Equations.
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Satisfiability of Equality Equations.

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> Y(26, 0);
        vector<int> N(26, 0);
        for (auto& e : equations) {
            int i = e[0] - 'a';
            int j = e[3] - 'a';
            
            Y[i] |= 1 << i;
            Y[j] |= 1 << j;
            
            if (e[1] == '=') {
                Y[i] |= 1 << j;
                Y[j] |= 1 << i;
            } else {
                N[i] |= 1 << j;
                N[j] |= 1 << i;
            }
        }
        
        int visited = 0;
        for (int i = 0; i < 26; ++i) {
            if (visited & (1 << i)) continue;
            visited |= 1 << i;
            for (int j = i + 1; j < 26; ++j) {
                if ((Y[i] & Y[j]) == 0) continue; 
                
                Y[i] |= Y[j];
                Y[j] |= Y[i];
                visited |= 1 << j;
            }
        }
        
        // for (int i = 0; i < 26; ++i) 
        //     if (Y[i] || N[i])
        //         cout << i << ":  " << bitset<26>(Y[i]) << "  " << bitset<26>(N[i]) << endl;

        for (int i = 0; i < 26; ++i)
            if (Y[i] & N[i]) return false;
        
        return true;
    }
};