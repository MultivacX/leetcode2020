// 1108. Defanging an IP Address
// https://leetcode.com/problems/defanging-an-ip-address/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Defanging an IP Address.
// Memory Usage: 6.3 MB, less than 10.70% of C++ online submissions for Defanging an IP Address.
    
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (char c : address) {
            if (c == '.') ans += "[.]";
            else ans += c;
        }
        return ans;
    }
};