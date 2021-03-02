// 833. Find And Replace in String

// Runtime: 8 ms, faster than 65.00% of C++ online submissions for Find And Replace in String.
// Memory Usage: 11.1 MB, less than 11.11% of C++ online submissions for Find And Replace in String.

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, int> m;
        for (int i = 0; i < indexes.size(); ++i) m[indexes[i]] = i;
        
        const int L = S.length();
        string ans;
        for (int i = 0, j = 0; i < L;) {
            if (m.count(i)) {
                int j = m[i];
                int k = 0;
                for (; k < sources[j].length(); ++k) 
                    if (i + k >= L || S[i + k] != sources[j][k]) break;
                if (k == sources[j].length()) {
                    ans += targets[j];
                    i += sources[j].length();
                } else {
                    ans += S[i++];
                }
            } else {
                ans += S[i++];
            }
        }
        return ans;
    }
};


class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        const int n = S.length();
        const int m = indexes.size();
        
        vector<vector<int>> I(m, {0, 0});
        for (int i = 0; i < m; ++i) {
            I[i][0] = indexes[i];
            I[i][1] = i;
        }
        sort(begin(I), end(I));
        
        string T;
        int i = 0, j = 0;
        while (i < n) {
            if (j >= m) {
                T += S.substr(i);
                break;
            }
            
            if (i == I[j][0]) {
                int k = I[j][1];
                const int l = sources[k].size();
                if (S.substr(i, l) == sources[k]) {
                    T += targets[k];
                    i += l;
                } else {
                    T += S[i++];
                }
                ++j;
            } else {
                T += S[i++];
            }
        }
        return T;
    }
};