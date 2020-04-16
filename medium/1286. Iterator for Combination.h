// 1286. Iterator for Combination

// Runtime: 20 ms, faster than 50.78% of C++ online submissions for Iterator for Combination.
// Memory Usage: 11.1 MB, less than 100.00% of C++ online submissions for Iterator for Combination.

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength)
    : C(characters)
    , L(combinationLength)
    , N(characters.length())
    , S(characters.substr(0, combinationLength))
    , F(characters.substr(characters.length() - combinationLength))
    , I(combinationLength, 0) {
        for (int i = 0; i < L; ++i) I[i] = i;
    }
    
    string next() {
        string ans(S);
        if (S == F) F.clear();
        if (hasNext()) {
            for (int i = L - 1; i >= 0; --i) {
                // I[i] => [i, i + N - L]
                ++I[i];
                if (I[i] <= i + N - L) {
                    S[i] = C[I[i]];
                    for (int j = i + 1; j < L; ++j) {
                        I[j] = j + I[i] - i;
                        S[j] = C[I[j]];
                    }
                    break;
                }
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return !F.empty();
    }
    
    const string C;
    const int L;
    const int N;
    string S;
    string F;
    vector<int> I;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */