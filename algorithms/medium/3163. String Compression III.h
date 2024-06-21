// 3163. String Compression III

class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string res;
        for (int i = 0, k = '0', pre = '*'; i < n; ++i) {
            if (k == '0') {
                pre = word[i];
            }

            if (pre == word[i]) {
                ++k;
            } else {
                res += k;
                res += pre;

                k = '1';
                pre = word[i];
            }

            if (k == '9') {
                res += k;
                res += pre;
                
                k = '0';
            } else if (i == n - 1) {
                res += k;
                res += pre;
            }
        }
        return res;
    }
};