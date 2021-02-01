// 842. Split Array into Fibonacci Sequence

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split Array into Fibonacci Sequence.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Split Array into Fibonacci Sequence.

class Solution {
    vector<int> seq;
    
public:
    vector<int> splitIntoFibonacci(string S) {
        const int N = S.length();
        for (int la = 1; la <= (N + 1) / 3; ++la) {
            if (S[0] == '0' && la > 1) break;
            
            int64_t a = stoll(S.substr(0, la));
            if (a > (int64_t)INT_MAX) break;
            
            seq.push_back(a);
            for (int lb = 1; lb <= (N + 1) / 3; ++lb) {
                if (S[la] == '0' && lb > 1) break;
                
                int64_t b = stoll(S.substr(la, lb));
                if (b > (int64_t)INT_MAX) break;
                
                seq.push_back(b);
                if (split(S, la + lb, a, b, la, lb)) return seq;
                seq.pop_back();    
            }
            seq.pop_back();
        }
        return seq.size() >= 3 ? seq : vector<int>();
    }
    
    bool split(const string& S, int idx, int64_t a, int64_t b, int la, int lb) {
        const int N = S.length();
        if (idx >= N) return seq.size() >= 3;
        int lc = max(la, lb);
        if (lc > N - idx) return false;
        
        if (S[idx] == '0') {
            if (a + b != 0) return false;
            
            seq.push_back(0); 
            if (split(S, idx + 1, b, 0, lb, 1)) return true;
            seq.pop_back();
        } else {
            int64_t c = stoll(S.substr(idx, lc));
            if (c != a + b) {
                lc += 1;
                c = stoll(S.substr(idx, lc));
            }
            if (c != a + b || c > (int64_t)INT_MAX) return false;
            
            seq.push_back(c);
            if (split(S, idx + lc, b, c, lb, lc)) return true;
            seq.pop_back();
        }
        
        return false;
    }
};