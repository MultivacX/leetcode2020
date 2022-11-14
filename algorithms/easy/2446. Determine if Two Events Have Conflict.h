// 2446. Determine if Two Events Have Conflict
// https://leetcode.com/problems/determine-if-two-events-have-conflict/

// Runtime: 4 ms, faster than 59.03% of C++ online submissions for Determine if Two Events Have Conflict.
// Memory Usage: 11.4 MB, less than 23.36% of C++ online submissions for Determine if Two Events Have Conflict.

class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        int t1s = ((event1[0][0] - '0') * 10 + event1[0][1] - '0') * 60 + (event1[0][3] - '0') * 10 + event1[0][4] - '0';
        int t1e = ((event1[1][0] - '0') * 10 + event1[1][1] - '0') * 60 + (event1[1][3] - '0') * 10 + event1[1][4] - '0';

        int t2s = ((event2[0][0] - '0') * 10 + event2[0][1] - '0') * 60 + (event2[0][3] - '0') * 10 + event2[0][4] - '0';
        int t2e = ((event2[1][0] - '0') * 10 + event2[1][1] - '0') * 60 + (event2[1][3] - '0') * 10 + event2[1][4] - '0';

        int s = max(t1s, t2s);
        int e = min(t1e, t2e);
        return s <= e;
    }
};