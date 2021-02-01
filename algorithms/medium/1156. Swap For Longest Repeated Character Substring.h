// 1156. Swap For Longest Repeated Character Substring
// https://leetcode.com/problems/swap-for-longest-repeated-character-substring/

// Runtime: 4 ms, faster than 97.22% of C++ online submissions for Swap For Longest Repeated Character Substring.
// Memory Usage: 8.5 MB, less than 17.13% of C++ online submissions for Swap For Longest Repeated Character Substring.

class Solution {
public:
    int maxRepOpt1(string text) {
        const int N = text.length();
        int ans = 1;
        vector<vector<int>> v(26);
        v[text[0] - 'a'].push_back(0);
        for (int i = 1; i < N; ++i) {
            if (text[i - 1] != text[i]) {
                int j = text[i - 1] - 'a';
                v[text[i - 1] - 'a'].push_back(i - 1);
                v[text[i] - 'a'].push_back(i);
            } 
            if (i == N - 1) {
                v[text[i] - 'a'].push_back(i);
            }
        }
        // int k = -1; for (auto& c : v) {
        //     ++k; if (c.empty()) continue;
        //     cout << (char)('a' + k) << ": ";
        //     for (int i = 0; i < c.size(); i += 2) 
        //         cout << '[' << c[i] << ',' << c[i+1] << ']' << ", ";
        //     cout << endl;
        // }
        for (auto& c : v) {
            if (c.empty()) continue;
            const int M = c.size();
            for (int i = 0; i < M; i += 2) {
                int a = c[i + 1] - c[i] + 1;
                if (a > ans) ans = a;
                if (M > 2 && a + 1 > ans) ans = a + 1;
                if (i + 2 < M && c[i + 1] + 2 == c[i + 2]) {
                    int b = c[i + 3] - c[i + 2] + 1;
                    int k = M > 4 ? 1 : 0;
                    if (a + k + b > ans) ans = a + k + b;
                }
            }
        }
        return ans;
    }
};