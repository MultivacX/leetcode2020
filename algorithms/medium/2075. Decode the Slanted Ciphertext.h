// 2075. Decode the Slanted Ciphertext
// https://leetcode.com/problems/decode-the-slanted-ciphertext/

// Runtime: 446 ms, faster than 14.28% of C++ online submissions for Decode the Slanted Ciphertext.
// Memory Usage: 34.7 MB, less than 94.29% of C++ online submissions for Decode the Slanted Ciphertext.

class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        const int n = encodedText.length();
        int cnt = count_if(encodedText.begin(), encodedText.end(), [](char i)
                           { return i != ' '; });
        int cols = n / rows;
        // cout << cols << endl;

        string s;
        int c = 0;
        while (cnt)
        {
            for (int i = 0, j = c; i<rows, cnt> 0; ++i, ++j)
            {
                int k = i * cols + j;
                if (k >= n)
                    break;
                if (encodedText[k] != ' ')
                    --cnt;
                s += encodedText[k];
            }
            c += 1;
        }
        return s;
    }
};