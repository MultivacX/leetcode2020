// 761. Special Binary String
// https://leetcode.com/problems/special-binary-string/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Special Binary String.
// Memory Usage: 6.4 MB, less than 80.70% of C++ online submissions for Special Binary String.
    
class Solution {
public:
    string makeLargestSpecial(string S) {
        // "1010" -> f"10" f"10"
        // "110010" -> f"1100" f"10"
        // "11011000" -> "1" f"101100" "0" 
        //            -> "1" f(f"10" f"1100") "0"
        //            -> "1" "1100" "10" "0"
        const int n = S.length();
        vector<string> strs;
        for (int i = 0, j = 0, k = 0; j < n; ++j) {
            S[j] == '1' ? ++k : --k;
            if (k == 0) {
                int l = i + 1, r = j - 1;
                strs.emplace_back("1" + makeLargestSpecial(S.substr(l, r - l + 1)) + "0");
                i = j + 1;
            }
        }
        sort(rbegin(strs), rend(strs));
        string T;
        for (const auto& s : strs)
            T.append(s);
        return T;
    }
};


// WA
class Solution {
public:
    string makeLargestSpecial(string S) {
        const int N = S.length();
        bool swapped = true;
        while (swapped) {
            swapped = false;
            int i = 0; 
            while (i < N - 2 && !swapped) {
                if (S[i] == '0') { ++i; continue; }

                string a; int a1 = 0; int a0 = 0; int j = i;
                while (j < N - 2 && !swapped) {
                    a += S[j]; S[j] == '1' ? ++a1 : ++a0;
                    if (a1 < a0) break; ++j;
                    a += S[j]; S[j] == '1' ? ++a1 : ++a0;
                    if (a1 < a0) break; ++j;
                    if (a1 != a0) continue;
                    
                    const int La = a.length();
                    // a         b
                    // S[i, j-1] S[j, k-1]
                    
                    string b; int b1 = 0; int b0 = 0; int k = j;
                    while (k < N - 1 && !swapped) {
                        b += S[k]; S[k] == '1' ? ++b1 : ++b0;
                        if (b1 < b0) break; ++k;
                        b += S[k]; S[k] == '1' ? ++b1 : ++b0;
                        if (b1 < b0) break; ++k;
                        
                        int Lb = b.length();
                        // printf("%d:%c%c %d:%c%c\n", i + Lb - 2, S[i + Lb - 2], S[i + Lb - 1], k - 2, b[Lb - 2], b[Lb - 1]);
                        if (La >= Lb && (S[i + Lb - 2] > b[Lb - 2] || S[i + Lb - 1] > b[Lb - 1])) break;
                        if (b1 != b0) continue;
                        
                        if (La == Lb) {
                            if (a < b) swapped = true;
                        } else if (La < Lb) {
                            a += S[j++];
                            a += S[j++];
                            if (a > b) break;
                            if (a < b) swapped = true;
                        }
                    }
                    
                    if (swapped) {
                        int tail = i + La + b.length();
                        S = S.substr(0, i) + b + S.substr(i, La) + (tail < N ? S.substr(tail) : "");
                    }
                }
                ++i;
            }
        }
        return S;
    }
};
