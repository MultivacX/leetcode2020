// 648. Replace Words

// Runtime: 116 ms, faster than 42.72% of C++ online submissions for Replace Words.
// Memory Usage: 19.1 MB, less than 100.00% of C++ online submissions for Replace Words.

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> roots(begin(dict), end(dict));
        string ans;
        int i = 0;
        const int N = sentence.length();
        while (i < N) {
            while (i < N && sentence[i] == ' ') ++i;
            string word;
            while (i < N && sentence[i] != ' ') {
                word += sentence[i++];
                if (roots.count(word)) break;
            }
            while (i < N && sentence[i] != ' ') ++i;
            while (i < N && sentence[i] == ' ') ++i;
            ans += word;
            if (i < N) ans += ' ';
        }
        return ans;
    }
};