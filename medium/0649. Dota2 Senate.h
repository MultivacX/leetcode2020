// 649. Dota2 Senate
// https://leetcode.com/problems/dota2-senate/

// Runtime: 352 ms, faster than 5.33% of C++ online submissions for Dota2 Senate.
// Memory Usage: 17.9 MB, less than 6.00% of C++ online submissions for Dota2 Senate.

class Solution {
public:
    string predictPartyVictory(string senate) {
        list<char> l;
        int r = 0;
        int d = 0;
        for (char c : senate) {
            l.push_back(c);
            c == 'R' ? ++r : ++d;
        }
        
        auto i = l.begin();
        auto j = l.begin(); ++j;
        while (r > 0 && d > 0) {
            if (j == l.end()) {
                i = l.begin();
                j = l.begin(); ++j;
            }
            
            if (*i == *j) {
                ++j;
            } else {
                *j == 'R' ? --r : --d;
                l.push_back(*i);
                l.erase(i);
                l.erase(j);
                j = l.end();
            }
        }

        return r ? "Radiant" : "Dire";
    }
};