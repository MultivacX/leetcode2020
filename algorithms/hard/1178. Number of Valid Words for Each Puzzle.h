// 1178. Number of Valid Words for Each Puzzle
// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/

// Runtime: 172 ms, faster than 47.15% of C++ online submissions for Number of Valid Words for Each Puzzle.
// Memory Usage: 35 MB, less than 88.08% of C++ online submissions for Number of Valid Words for Each Puzzle.
    
class Solution {
    int getBits(const string& word) {
        int bits = 0;
        for (char c : word)
            bits |= 1 << (c - 'a');
        return bits;
    }
    
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freqs;
        for (int i = 0; i < words.size(); ++i) 
            ++freqs[getBits(words[i])];
        
        const int n = puzzles.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int first = 1 << (puzzles[i][0] - 'a');
            int mask = getBits(puzzles[i]);
            int curr = mask;
            while (curr) {
                if (curr & first) {
                    auto it = freqs.find(curr);
                    if (it != end(freqs)) 
                        ans[i] += it->second;
                }
                curr = (curr - 1) & mask;
            }
        }
        return ans;
    }
};


// TLE
// 9 / 10 test cases passed.
class Solution {
    int getBits(const string& word) {
        int bits = 0;
        for (char c : word)
            bits |= 1 << (c - 'a');
        return bits;
    }
    
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // words[i] = "aade", words[j] = "ddae"
        //     'a': {10011, {i, j}}
        //     'd': {10011, {i, j}}
        //     'e': {10011, {i, j}}
        
        vector<unordered_set<int>> wordLetters2Bits(26);
        unordered_map<int, unordered_set<int>> wordBits2Idx;
        for (int i = 0; i < words.size(); ++i) {
            int bits = getBits(words[i]);
            for (char c : words[i])
                wordLetters2Bits[c - 'a'].insert(bits);
            wordBits2Idx[bits].insert(i);
        }
        
        const int n = puzzles.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int j = puzzles[i][0] - 'a';
            int mask = getBits(puzzles[i]);
            unordered_set<int> cnt;
            for (int bits : wordLetters2Bits[j]) {
                if ((mask & bits) != bits)
                    continue;
                
                cnt.insert(begin(wordBits2Idx[bits]), end(wordBits2Idx[bits]));
            }
            ans[i] = cnt.size();
        }
        return ans;
    }
};