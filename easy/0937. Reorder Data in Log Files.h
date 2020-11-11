// 937. Reorder Data in Log Files
// https://leetcode.com/problems/reorder-data-in-log-files/

// Runtime: 20 ms, faster than 39.60% of C++ online submissions for Reorder Data in Log Files.
// Memory Usage: 11.3 MB, less than 5.67% of C++ online submissions for Reorder Data in Log Files.

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {            
        unordered_map<string, string> n;
        int d = 'a';
        for (const auto& l : logs) {
            auto p = l.find(' ');
            if (l[p + 1] >= 'a') n[l] = " " + l.substr(p) + " " + l.substr(0, p);
            else n[l] = d++;
            // cout << l << " -> " << n[l] << endl;
        }
        
        sort(begin(logs), end(logs), [&](string& l, string& r){
            return n[l] <= n[r];
        });
        return logs;
    }
};