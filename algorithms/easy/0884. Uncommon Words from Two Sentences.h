// 884. Uncommon Words from Two Sentences
// https://leetcode.com/problems/uncommon-words-from-two-sentences/

// Runtime: 4 ms, faster than 62.50% of C++ online submissions for Uncommon Words from Two Sentences.
// Memory Usage: 7.1 MB, less than 94.96% of C++ online submissions for Uncommon Words from Two Sentences.
    
class Solution {
    void split(const string& s, char delimiter, unordered_map<string, int>& m) {
   		string token;
   		istringstream tokenStream(s);
   		while (getline(tokenStream, token, delimiter)) 
      		++m[token];
	}
    
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> m;
        split(A, ' ', m);
        split(B, ' ', m);
        vector<string> ans;
        for (auto it : m) if (it.second == 1) ans.push_back(it.first);
        return ans;
    }
};