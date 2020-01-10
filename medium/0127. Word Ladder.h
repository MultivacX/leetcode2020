// 127. Word Ladder

class Solution {
public:
	// Time Limit Exceeded
    /*int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
        unordered_map<string, unordered_set<string>> words;
        
        for (int i = 0; i < beginWord.length(); ++i) {
            string w(beginWord);
            w[i] = '*';
            words[beginWord].insert(w);
            words[w].insert(beginWord);
        }
        
        for (const string& word : wordList) {
            for (int i = 0; i < word.length(); ++i) {
                string w(word);
                w[i] = '*';
                words[word].insert(w);
                words[w].insert(word);
            }
        }
        
        int edges = INT_MAX;
        unordered_set<string> visited;
        f(beginWord, endWord, 0, edges, words, visited);
        
        return edges == INT_MAX ? 0 : (edges + 2) / 2;
    }
    
    void f(string beginWord, 
           string endWord, 
           int level,
           int& edges,
           unordered_map<string, unordered_set<string>>& words,
           unordered_set<string>& visited) {
        if (visited.count(beginWord)) return;
        if (beginWord == endWord) {
            edges = min(edges, level);
            return;
        }
        
        visited.insert(beginWord);
        for (const string& word : words[beginWord]) {
            f(word, endWord, level + 1, edges, words, visited);
        }
        visited.erase(beginWord);
    }*/
};