// 68. Text Justification

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Text Justification.
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Text Justification.

// Time Complexity: O(N).
// Space Complexity: O(N).

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        const int N = words.size();
        int i = 0;
        while (i < N) {
            vector<int> row;
            int cur_words_len = 0;
            while (i < N) {
                // cur_words + spaces + words[i]
                int next_min_len = cur_words_len + row.size() + words[i].length();
                if (next_min_len > maxWidth) break;
                row.emplace_back(i);
                cur_words_len += words[i].length();
                ++i;
            }
            
            int spaces = maxWidth - cur_words_len;
            const int R = row.size();
            if (R == 1) {
                ans.emplace_back(words[row[0]] + string(spaces, ' '));
            } else if (i == N) {
                string line;
                for (int j = 0; j < R; ++j) {
                    line += words[row[j]];
                    if (spaces > 0) {
                        if (j + 1 == R) line += string(spaces, ' ');
                        else line += " ", --spaces;
                    }
                }
                ans.emplace_back(line);
            } else {
                string line;
                int m = spaces / (R - 1);
                int n = spaces % (R - 1);
                // printf("w:%d, s:%d, %d, %d\n", cur_words_len, spaces, m, n);
                for (int j = 0; j < R; ++j) {
                    line += words[row[j]];
                    if (j + 1 < R) {
                        line += string(m + (n-- > 0 ? 1 : 0), ' ');
                    }
                }   
                ans.emplace_back(line);
            }
        }
        return ans;
    }
};