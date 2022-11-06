// 2131. Longest Palindrome by Concatenating Two Letter Words
// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

// Runtime: 731 ms, faster than 58.08% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.
// Memory Usage: 168.6 MB, less than 10.24% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> m; // w, k
        vector<int> v(26);
        int res = 0;

        for (int i = 0; i < words.size(); ++i)
        {
            const string &t = words[i];
            if (t[0] == t[1])
            {
                ++v[t[0] - 'a'];
            }
            else
            {
                string w(2, t[0]);
                w[0] = t[1];
                if (m.count(w))
                {
                    res += 4;
                    if (--m[w] == 0)
                        m.erase(w);
                }
                else
                {
                    ++m[t];
                }
            }
        }

        int x = 0;
        for (int k : v)
        {
            if (k & 1)
                x = 2, res += (k - 1) * 2;
            else
                res += k * 2;
        }

        return res + x;
    }
};