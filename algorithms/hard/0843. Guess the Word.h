// 843. Guess the Word
// https://leetcode.com/problems/guess-the-word/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Guess the Word.
// Memory Usage: 6.6 MB, less than 71.08% of C++ online submissions for Guess the Word.
    
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    int matches(const string& a, const string& b) {
        int m = 0;
        for (int i = 0; i < 6; ++i)
            if (a[i] == b[i])
                ++m;
        return m;
    }
    
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while (!wordlist.empty()) {
            int i = rand() % wordlist.size();
            int m = master.guess(wordlist[i]);
            if (m == 6) return;
            
            vector<string> wl;
            for (int j = 0; j < wordlist.size(); ++j) {
                if (i == j || matches(wordlist[i], wordlist[j]) != m) continue;
                wl.push_back(wordlist[j]);
            }
            wordlist = move(wl);
        }
    }
};