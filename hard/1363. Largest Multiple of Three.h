// 1363. Largest Multiple of Three

// Runtime: 8 ms, faster than 96.50% of C++ online submissions for Largest Multiple of Three.
// Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Largest Multiple of Three.

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        if (digits.empty()) return "";
        
        vector<int> m(10, 0);
        int n0 = 0; // 0, 3, 6, 9
        int n1 = 0; // 1, 4, 7
        int n2 = 0; // 2, 5, 8
        for (int d : digits) {
            ++m[d];
            int n = d % 3;
            if (n == 0) ++n0;
            else if (n == 1) ++n1;
            else ++n2;
        }
        
        int n = abs(n1 - n2) % 3;
        if (n == 0) {
            return append_all(m);
        } else {
            int pairs = min(n1 %3, n2 % 3);
            int x1 = (n1 / 3) * 3 + pairs;
            int x2 = (n2 / 3) * 3 + pairs;
            
            pairs = min(n1, n2);
            int y1 = pairs + ((max(n1, n2) - min(n1, n2)) / 3) * 3;
            int y2 = pairs;
            
            if (x1 + x2 > y1 + y2) {
                return append(m, x1, x2);
            } else if (x1 + x2 < y1 + y2) {
                return n1 > n2 ? append(m, y1, y2) : append(m, y2, y1);
            } else {
                string s1 = append(m, x1, x2);
                string s2 = n1 > n2 ? append(m, y1, y2) : append(m, y2, y1);
                return s1 > s2 ? s1 : s2;
            }
        }
    }
    
    string append_all(vector<int>& m) {
        string ans;
        for (int i = 9; i >= 0; --i) {
            if (m[i] == 0) continue;
            if (i == 0 && ans.empty()) return "0";
            ans.append(m[i], i + '0');
        }
        return ans;
    }
    
    string append(vector<int>& m, int x1, int x2) {
        string ans;
        for (int i = 9; i >= 0; --i) {
            if (m[i] == 0) continue;
            int n = i % 3;
            if (n == 0) {
                ans.append(m[i], i + '0');
            } else if (n == 1) {
                if (x1 <= 0) continue;
                ans.append(min(m[i], x1), i + '0');
                x1 -= min(m[i], x1);
            } else {
                if (x2 <= 0) continue;
                ans.append(min(m[i], x2), i + '0');
                x2 -= min(m[i], x2);
            }
        }
        return ans;
    }
};