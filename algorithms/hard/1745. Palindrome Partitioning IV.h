// 1745. Palindrome Partitioning IV
// https://leetcode.com/problems/palindrome-partitioning-iv/

// Runtime: 12 ms, faster than 99.89% of C++ online submissions for Palindrome Partitioning IV.
// Memory Usage: 6.5 MB, less than 98.88% of C++ online submissions for Palindrome Partitioning IV.
    
class Solution {
    bool isPalindromic(const string& s, int i, int j) {
        while (i < j && s[i] == s[j])
            ++i, --j;
        return i >= j;
    }
    
public:
    bool checkPartitioning(string s) {
        const int N = s.length();
        // s[0...left[i]] is palindromic
        vector<int> left{0};
        for (int i = 1; i < N - 2; ++i) 
            if (isPalindromic(s, 0, i))
                left.push_back(i);
        
        // s[right[i]...N-1] is palindromic
        vector<int> right{N - 1};
        for (int i = N - 2; i > 1; --i) 
            if (isPalindromic(s, i, N - 1))
                right.push_back(i);
        reverse(begin(right), end(right));
        
        int j = 0;
        for (int l : left) {
            while (j < right.size() && l + 2 > right[j]) ++j;
            if (j >= right.size()) break;
            int r = right[j];
            // cout << s.substr(0, l + 1) << " " << s.substr(r) << endl;
            if (isPalindromic(s, l + 1, r - 1)) return true;
        }
        return false;
    }
};