// 1432. Max Difference You Can Get From Changing an Integer
// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Max Difference You Can Get From Changing an Integer.
// Memory Usage: 6.1 MB, less than 8.18% of C++ online submissions for Max Difference You Can Get From Changing an Integer.

class Solution {
public:
    int maxDiff(int num) {
        if (num < 10) return 8;
        
        string sb(to_string(num));
        
        string sa(sb); 
        char x = sa[0];
        int i = 0;
        while (i < sa.length()) {
            if (sa[i] != '9') {
                x = sa[i];
                break;
            }
            ++i;
        }
        char y = '9';
        for (char& c : sa) {
            if (c != x) continue;
            c = y;
        }
        // cout << x << ' ' << y << ' ' << sa << endl;
        
        if (sb[0] == '1') {
            x = sb[1] == '1' ? '1' : sb[1];
            i = 1;
            while (i < sb.length()) {
                if (sb[i] != '0' && sb[i] != '1') {
                    x = sb[i];
                    break;
                }
                ++i;
            }
            y = x == '1' ? '1' : '0';
        } else {
            x = sb[0];
            y = '1';
        }
        for (char& c : sb) {
            if (c != x) continue;
            c = y;
        }
        // cout << x << ' ' << y << ' ' << sb << endl;
        
        return stoi(sa) - stoi(sb);
    }
};