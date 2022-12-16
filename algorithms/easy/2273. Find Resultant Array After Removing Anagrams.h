// 2273. Find Resultant Array After Removing Anagrams

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> res;
        vector<int> pre(26);
        for (int i = 0; i < words.size(); ++i)
        {
            vector<int> cur(26);
            for (char c : words[i])
                ++cur[c - 'a'];

            for (int j = 0; j < 26; ++j)
            {
                if (pre[j] != cur[j])
                {
                    res.push_back(words[i]);
                    swap(pre, cur);
                    break;
                }
            }
        }
        return res;
    }
};