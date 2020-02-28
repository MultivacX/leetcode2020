// 383. Ransom Note

// Runtime: 20 ms, faster than 91.38% of C++ online submissions for Ransom Note.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Ransom Note.

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt = ransomNote.length();
        vector<int> note(26, 0);
        for (const char& c : ransomNote)
            ++note[c - 'a'];
        for (const char& c : magazine) {
            if (note[c - 'a'] == 0)
                continue;
            --note[c - 'a'];
            --cnt;
        }
        return cnt == 0;
    }
};