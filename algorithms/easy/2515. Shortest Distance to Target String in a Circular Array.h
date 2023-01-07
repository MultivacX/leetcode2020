class Solution
{
public:
    int closetTarget(vector<string> &words, string target, int startIndex)
    {
        int res = INT_MAX, n = words.size();
        for (int i = 0; i < n; ++i)
        {
            if (words[i] != target)
                continue;

            int d = abs(i - startIndex);
            res = min(res, d);

            if (i < startIndex)
                d = i + n - startIndex;
            else
                d = startIndex + n - i;
            res = min(res, d);
        }
        return res == INT_MAX ? -1 : res;
    }
};