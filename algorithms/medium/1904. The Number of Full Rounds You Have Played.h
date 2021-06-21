// 1904. The Number of Full Rounds You Have Played
// https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for The Number of Full Rounds You Have Played.
// Memory Usage: 6 MB, less than 57.14% of C++ online submissions for The Number of Full Rounds You Have Played.
    
class Solution {
    int H(const string& s) {
        return (s[0] - '0') * 10 + (s[1] - '0');
    }
    
    int M(const string& s) {
        return (s[3] - '0') * 10 + (s[4] - '0');
    }
    
public:
    int numberOfRounds(string startTime, string finishTime) {
        int sh = H(startTime);
        int sm = M(startTime);
        if (0 < sm && sm < 15) {
            sm = 15;
        } else if (15 < sm && sm < 30) {
            sm = 30;
        } else if (30 < sm && sm < 45) {
            sm = 45;
        } else if (45 < sm && sm <= 59) {
            sh += 1;
            sm = 0;
        }
        int st = sh * 60 + sm;
        
        int fh = H(finishTime);
        int fm = M(finishTime);
        int ft = fh * 60 + fm;
        if (st <= ft && ft - st < 15)
            return 0;
        if (st > ft) 
            fh += 24;
        
        if (0 < fm && fm < 15) {
            fm = 0;
        } else if (15 < fm && fm < 30) {
            fm = 15;
        } else if (30 < fm && fm < 45) {
            fm = 30;
        } else if (45 < fm && fm <= 59) {
            fm = 45;
        }
        ft = fh * 60 + fm;
        
        return (ft - st) / 15;
    }
};