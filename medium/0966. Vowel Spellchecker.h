// 966. Vowel Spellchecker

// Runtime: 192 ms, faster than 29.29% of C++ online submissions for Vowel Spellchecker.
// Memory Usage: 35 MB, less than 100.00% of C++ online submissions for Vowel Spellchecker.

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        static const unordered_set<char> vowels{'A', 'E', 'I', 'O', 'U'};
        unordered_set<string> words(begin(wordlist), end(wordlist));
        unordered_map<string, string> capitlizations;
        unordered_map<string, string> vowel_errors;
        for (const string& word : wordlist) {
            string w(word);
            for (auto& c: w) c = toupper(c);
            if (capitlizations.count(w)) continue;
            
            capitlizations.emplace(w, word);
            for (auto& c: w) if (vowels.count(c)) c = '*';
            vowel_errors.emplace(w, word);
        }
        
        vector<string> ans;
        for (const string& word : queries) {
            if (words.count(word)) {
                ans.emplace_back(word);
                continue;
            }
            
            string w(word);
            for (auto& c: w) c = toupper(c);
            if (capitlizations.count(w)) {
                ans.emplace_back(capitlizations[w]);
                continue;
            }
            
            for (auto& c: w) if (vowels.count(c)) c = '*';
            if (vowel_errors.count(w)) {
                ans.emplace_back(vowel_errors[w]);
                continue;
            }
            
            ans.emplace_back("");
        }
        return ans;
    }
};