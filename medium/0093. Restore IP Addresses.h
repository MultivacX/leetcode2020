// 93. Restore IP Addresses

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Restore IP Addresses.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Restore IP Addresses.

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> cur;
        restore(s, ans, 0, cur);
        return ans;
    }
    
    void restore(const string& s, vector<string>& ans, int i, vector<string>& cur) {
        const int N = s.length();
        const int parts = cur.size();
        
        if (i >= N && parts == 4) {
            string ip;
            for (int j = 0; j < 4; ++j) {
                ip += cur[j];
                if (j != 3) ip += '.';
            }
            ans.push_back(ip);
            return;
        }
        
        const int L = s[i] == '0' ? 1 : 3;
        int n = 0;
        for (int j = i; j < i + L && j < N; ++j) {
            n = n * 10 + s[j] - '0';
            if (n > 255) break;
            if (N - j - 1 > (3 - parts) * 3) continue;
            // cout << parts << ": " << s.substr(i, j - i + 1) << endl;
            cur.push_back(s.substr(i, j - i + 1));
            restore(s, ans, j + 1, cur);
            cur.pop_back();
        }
    }
};