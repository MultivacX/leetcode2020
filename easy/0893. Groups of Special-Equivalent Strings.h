// 893. Groups of Special-Equivalent Strings
// https://leetcode.com/problems/groups-of-special-equivalent-strings/

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Groups of Special-Equivalent Strings.
// Memory Usage: 8.6 MB, less than 99.01% of C++ online submissions for Groups of Special-Equivalent Strings.
    
class Solution {
    string get_se(const string& a, int i) {
        string x; 
        for (; i < a.length(); i += 2) 
            x += a[i];
        sort(begin(x), end(x));
        return x;
    }
    
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for (const string& a : A)
            s.insert(get_se(a, 0) + get_se(a, 1));
        return s.size();
    }
};