// 925. Long Pressed Name
// https://leetcode.com/problems/long-pressed-name/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Long Pressed Name.
// Memory Usage: 6.7 MB, less than 50.19% of C++ online submissions for Long Pressed Name.

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        const int M = name.length();
        const int N = typed.length();
        if (M > N) return false;
        if (M == N) return name == typed;
        int i = 0;
        int j = 0;
        while (i < M && j < N) {
            if (name[i] == typed[j])  ++i, ++j;
            else if (j > 0 && typed[j] == typed[j - 1]) ++j;
            else return false;
        }
        if (i < M) return false;
        while (j < N && typed[j] == name[M - 1]) ++j;
        return j == N;
    }
};