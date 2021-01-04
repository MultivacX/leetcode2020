// 804. Unique Morse Code Words
// https://leetcode.com/problems/unique-morse-code-words/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Morse Code Words.
// Memory Usage: 8.9 MB, less than 94.57% of C++ online submissions for Unique Morse Code Words.

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static const vector<string> m{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for (const auto& w : words) {
            string t;
            for (char c : w) 
                t += m[c - 'a'];
            s.insert(t);
        }
        return s.size();
    }
};