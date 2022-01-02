// 2114. Maximum Number of Words Found in Sentences
// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

// Runtime: 12 ms, faster than 79.16% of C++ online submissions for Maximum Number of Words Found in Sentences.
// Memory Usage: 9.6 MB, less than 99.83% of C++ online submissions for Maximum Number of Words Found in Sentences.

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int n = 0;
        for_each(cbegin(sentences), cend(sentences), [&n](const string &s)
                 { n = max(n, (int)count(cbegin(s), cend(s), ' ')); });
        return 1 + n;
    }
};