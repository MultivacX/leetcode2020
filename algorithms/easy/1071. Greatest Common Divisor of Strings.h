// 1071. Greatest Common Divisor of Strings
// https://leetcode.com/problems/greatest-common-divisor-of-strings/

// Runtime: 4 ms, faster than 82.66% of C++ online submissions for Greatest Common Divisor of Strings.
// Memory Usage: 7.1 MB, less than 5.02% of C++ online submissions for Greatest Common Divisor of Strings.

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int M = str1.length();
        int N = str2.length();
        if (M > N) swap(str1, str2);
        M = str1.length();
        N = str2.length();
        
        string t(str1);
        while (!t.empty()) {
            const int L = t.length();
            if (M % L == 0 && N % L == 0) {
                if (str2.substr(0, L) != t) return "";
                
                int p0 = L;
                while (p0 < M && str1.substr(p0, L) == t) p0 += L;
                if (p0 != M) { t.pop_back(); continue; }
                
                int p1 = L;
                while (p1 < N && str2.substr(p1, L) == t) p1 += L;
                if (p1 != N) { t.pop_back(); continue; }
                
                return t;
            }
            t.pop_back();
        }
        return "";
    }
};