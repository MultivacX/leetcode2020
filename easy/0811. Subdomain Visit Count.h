// 811. Subdomain Visit Count
// https://leetcode.com/problems/subdomain-visit-count/

// Runtime: 20 ms, faster than 63.57% of C++ online submissions for Subdomain Visit Count.
// Memory Usage: 11.9 MB, less than 74.96% of C++ online submissions for Subdomain Visit Count.
    
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (auto& s : cpdomains) {
            const int n = s.length();
            int cnt = 0;
            for (int i = 0; i < n && s[i] != ' '; ++i) 
                cnt = cnt * 10 + s[i] - '0';
            string k;
            for (int i = n - 1; i >= 0; --i) {
                if (s[i] == '.' || s[i] == ' ') {
                    m[k] += cnt;
                    if (s[i] == ' ') break;
                }
                k += s[i];
            }
        }
        
        vector<string> ans;
        for (auto it : m) {
            string k(it.first);
            reverse(begin(k), end(k));
            ans.push_back(to_string(it.second) + ' ' + k);
        }
        return ans;
    }
};