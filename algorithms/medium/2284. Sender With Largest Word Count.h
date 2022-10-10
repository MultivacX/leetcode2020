// 2284. Sender With Largest Word Count
// https://leetcode.com/problems/sender-with-largest-word-count/

// Runtime: 189 ms, faster than 99.35% of C++ online submissions for Sender With Largest Word Count.
// Memory Usage: 72.1 MB, less than 59.48% of C++ online submissions for Sender With Largest Word Count.

class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        unordered_map<string, int> m;
        int largest = 0;
        for (int i = 0; i < messages.size(); ++i)
        {
            const int k = std::count(messages[i].cbegin(), messages[i].cend(), ' ') + 1;
            m[senders[i]] += k;
            largest = max(largest, m[senders[i]]);
        }

        string res;
        for (auto it : m)
            if (it.second == largest && (res.empty() || res < it.first))
                res = it.first;
        return res;
    }
};