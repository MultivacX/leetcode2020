// 929. Unique Email Addresses
// https://leetcode.com/problems/unique-email-addresses/

// Runtime: 24 ms, faster than 96.80% of C++ online submissions for Unique Email Addresses.
// Memory Usage: 13.6 MB, less than 94.57% of C++ online submissions for Unique Email Addresses.
    
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (const auto& e : emails) {
            string t;
            bool foundPlus = false;
            for (int i = 0; i < e.length(); ++i) {
                if (e[i] == '@') {
                    t += e.substr(i);
                    break;
                }
                if (e[i] == '+' || foundPlus) { 
                    foundPlus = true; 
                    continue;
                }
                if (e[i] == '.') continue;
                t += e[i];
            }
            s.insert(t);
        }
        return s.size();
    }
};


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (const auto& e : emails) {
            string t;
            const int n = e.length();
            int i = 0;
            while (e[i] != '@') {
                if (e[i] == '+') break;
                if (e[i] == '.') { ++i; continue; }
                t += e[i++];
            }
            while (e[i] != '@') ++i;
            t += e.substr(i);
            s.insert(t);
        }
        return s.size();
    }
};