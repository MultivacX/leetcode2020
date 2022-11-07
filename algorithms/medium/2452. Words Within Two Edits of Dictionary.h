// 2452. Words Within Two Edits of Dictionary
// https://leetcode.com/problems/words-within-two-edits-of-dictionary/

// Runtime: 11 ms, faster than 97.08% of C++ online submissions for Words Within Two Edits of Dictionary.
// Memory Usage: 9.2 MB, less than 68.89% of C++ online submissions for Words Within Two Edits of Dictionary.

class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> res;
        for (const auto &q : queries)
        {
            for (const auto &d : dictionary)
            {
                int e = 0;
                for (int i = 0; i < q.length() && e < 3; ++i)
                    e += q[i] != d[i];
                if (e < 3)
                {
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};