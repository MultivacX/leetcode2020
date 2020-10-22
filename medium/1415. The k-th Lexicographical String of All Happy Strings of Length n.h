// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for The k-th Lexicographical String of All Happy Strings of Length n.
// Memory Usage: 6.2 MB, less than 7.56% of C++ online submissions for The k-th Lexicographical String of All Happy Strings of Length n.

class Solution {
public:
    string getHappyString(int n, int k) {
        int N = 3 * (1 << (n - 1));
        if (k > N) return "";
        
        static const unordered_map<char, array<char, 2>> M{
            {'a', array<char, 2>{'b', 'c'}},  
            {'b', array<char, 2>{'a', 'c'}},  
            {'c', array<char, 2>{'a', 'b'}},  
        };
        string s;
        if (0 < k && k <= N / 3) k -= 0, s += 'a';
        else if (N / 3 < k && k <= N * 2 / 3) k -= N / 3, s += 'b';
        else k -= N * 2 / 3, s += 'c';
        N /= 3;
        while (s.length() < n) {
            if (0 < k && k <= N / 2) k -= 0, s += M.at(s.back())[0];
            else k -= N / 2, s += M.at(s.back())[1];
            N /= 2;
        }
        return s;
    }
};