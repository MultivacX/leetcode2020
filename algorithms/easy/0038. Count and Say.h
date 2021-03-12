// 38. Count and Say
// https://leetcode.com/problems/count-and-say/

// Runtime: 4 ms, faster than 81.00% of C++ online submissions for Count and Say.
// Memory Usage: 7 MB, less than 5.02% of C++ online submissions for Count and Say.

class Solution {
public:
    string countAndSay(int n) {
        string ans("1");
        for (int i = 2; i <= n; ++i) {
            string tmp;
            const int N = ans.length();
            for (int j = 0, cnt = 0, c = ans[0]; j < N; ++j) {
                if (j == 0 || ans[j] == c) {
                    ++cnt;
                } else {
                    tmp += to_string(cnt);
                    tmp += c;
                    cnt = 1;
                    c = ans[j];
                }
                if (j + 1 == N) {
                    tmp += to_string(cnt);
                    tmp += c;
                }
            }
            ans = tmp;
        }
        return ans;
    }
};


class Solution {
public:
    string countAndSay(int n) {
        string cur("1");
        for (int i = 2; i <= n; ++i) {
            const int m = cur.length();
            string tmp;
            int j = 0, k = 1;
            while (j < m) {
                if (j + 1 == m || cur[j] != cur[j + 1]) {
                    tmp += to_string(k) + cur[j];
                    k = 1;
                } else {
                    ++k;
                }
                ++j;
            }
            cur = move(tmp);
        }
        return cur;
    }
};