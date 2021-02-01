// 1044. Longest Duplicate Substring

// Runtime: 1736 ms, faster than 61.16% of C++ online submissions for Longest Duplicate Substring.
// Memory Usage: 183.4 MB, less than 100.00% of C++ online submissions for Longest Duplicate Substring.

class Solution {
    static const int M = 7919;
    static const int BASE = 26;
    
    int N;
    
    bool check(const vector<int>& V, const int length, int i, int j){
        for (int k = 0; k < length; ++k) {
            if (V[i] != V[j]) return false;
            ++i;
            ++j;
        }
        return true;
    }
    
    int find(const string& S, const vector<int>& V, const vector<int>& P, const int length){
        int hash = 0;
        for (int j = 0; j < length; ++j)
            hash = (hash * BASE % M + V[j]) % M; 

        // cout << length << endl;

        // {hash, {substring start index}}
        unordered_map<int, vector<int>> m{{hash, {0}}};

        for (int i = 1; i <= N - length; ++i) {
            hash = (hash - V[i - 1] * P[length - 1] % M + M) % M;
            hash = (hash * BASE % M + V[i + length - 1]) % M;
            
            // hash = 0;
            // for (int j = 0; j < length; ++j)
            //     hash = (hash * BASE % M + V[j + i]) % M; 

            if (m.count(hash))
                for (int j : m[hash])
                    if (check(V, length, i, j)) return i;

            m[hash].push_back(i);
        }

        return -1;
    }
    
public:
    string longestDupSubstring(string S) {
        N = S.size();
        
        vector<int> V(N, 0);
        for (int i = 0; i < N; ++i) V[i] = S[i] - 'a';
        
        vector<int> P(N, 1);
        for (int i = 1; i < N; ++i) P[i] = P[i - 1] * 26 % M;
        
        int ans_begin = -1;
        int ans_length = -1;
        
        int begin = 1;
        int end = N;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            int idx = find(S, V, P, mid);
            
            if (idx != -1) {
                ans_begin = idx;
                ans_length = mid;
                
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        
        return ans_length <= 0 ? "" : S.substr(ans_begin, ans_length);
    }
};