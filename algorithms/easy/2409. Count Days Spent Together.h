// 2409. Count Days Spent Together
// https://leetcode.com/problems/count-days-spent-together/

// Runtime: 2 ms, faster than 65.00% of C++ online submissions for Count Days Spent Together.
// Memory Usage: 6.1 MB, less than 15.00% of C++ online submissions for Count Days Spent Together.
    
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int a[] = {
            (arriveAlice[0] - '0') * 10 + arriveAlice[1] - '0' - 1, 
            (arriveAlice[3] - '0') * 10 + arriveAlice[4] - '0',
            (leaveAlice[0] - '0') * 10 + leaveAlice[1] - '0' - 1, 
            (leaveAlice[3] - '0') * 10 + leaveAlice[4] - '0',
        };
        
        int b[] = {
            (arriveBob[0] - '0') * 10 + arriveBob[1] - '0' - 1, 
            (arriveBob[3] - '0') * 10 + arriveBob[4] - '0',
            (leaveBob[0] - '0') * 10 + leaveBob[1] - '0' - 1, 
            (leaveBob[3] - '0') * 10 + leaveBob[4] - '0',
        };
        
        int lm, ld;
        if (a[0] == b[0]) {
            lm = a[0];
            ld = max(a[1], b[1]);
        } else if (a[0] < b[0]) {
            lm = b[0];
            ld = b[1];
        } else {
            lm = a[0];
            ld = a[1];
        }
        
        int rm, rd;
        if (a[2] == b[2]) {
            rm = a[2];
            rd = min(a[3], b[3]);
        } else if (a[2] < b[2]) {
            rm = a[2];
            rd = a[3];
        } else {
            rm = b[2];
            rd = b[3];
        }
        
        if (lm == rm) {
            return ld <= rd ? rd - ld + 1 : 0;
        } else if (lm > rm) {
            return 0;
        } else {
            int res = days[lm] - ld + 1;
            for (int m = lm + 1; m < rm; ++m) {
                res += days[m];
            }
            res += rd;
            return res;
        }
    }
};