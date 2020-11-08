// 796. Rotate String
// https://leetcode.com/problems/rotate-string/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate String.
// Memory Usage: 6.6 MB, less than 36.14% of C++ online submissions for Rotate String.

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A == B) return true;
        const int N = A.length();
        for (int l = 1; l < N; ++l) {
            // cout << A.substr(0, l) << " " << B.substr(N - l) << " " 
            //      << A.substr(l) << " " << B.substr(0, N - l) << endl;
            if (A.substr(0, l) == B.substr(N - l) && A.substr(l) == B.substr(0, N - l))
                return true;
        }
        return false;
    }
};