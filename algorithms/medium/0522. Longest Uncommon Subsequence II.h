// 522. Longest Uncommon Subsequence II

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Uncommon Subsequence II.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Longest Uncommon Subsequence II.

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        const int n = strs.size();
        if (n == 0) return -1;
        if (n == 1) return strs[0].length();
        
        sort(begin(strs), end(strs), [](string& l, string& r) { return l.length() > r.length(); });
        vector<int> lens;
        for (const auto& s : strs) 
            if (lens.empty() || lens.back() != s.length())
                lens.push_back(s.length());
        
        int j = 0;
        vector<unordered_map<string, int>> strings;
        for (int i = 0; i < lens.size(); ++i) {
            strings.push_back(unordered_map<string, int>());
            while (j < n && strs[j].length() == lens[i]) 
                ++strings[i][strs[j++]];
            
            for (const auto& cur : strings[i]) {
                if (cur.second > 1) 
                    continue;
                
                bool isSubsequence = false;
                for (int k = i - 1; k >= 0 && !isSubsequence; --k) {
                    for (const auto& pre : strings[k]) {
                        if (!common(pre.first, cur.first)) 
                            continue;
                        isSubsequence = true;
                        break;
                    }
                }
                if (!isSubsequence) 
                    return lens[i];
            }
         }
        return -1;
    }
    
    bool common(const string& a, const string& b) {
        int i = 0;
        int j = 0;
        while (i < a.length() && j < b.length())
            if (a[i++] == b[j]) ++j;
        return j == b.length();
    }
};