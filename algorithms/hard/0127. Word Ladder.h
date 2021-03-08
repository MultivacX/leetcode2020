// 127. Word Ladder

// Runtime: 24 ms, faster than 99.61% of C++ online submissions for Word Ladder.
// Memory Usage: 12.8 MB, less than 97.73% of C++ online submissions for Word Ladder.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        unordered_set<string> f, b, *pf, *pb;
        f.insert(beginWord);
        b.insert(endWord);
        
        int wl = beginWord.length();
        
        int len = 2;
        while (!f.empty() && !b.empty()) {
            if (f.size() <= b.size()) {
                pf = &f;
                pb = &b;
            } else {
                pf = &b;
                pb = &f;
            }
            
            unordered_set<string> tmp;
            for (const string& cur : *pf) {
                words.erase(cur);
                
                for (int i = 0; i < wl; ++i) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        string tf(cur);
                        tf[i] = c;
                        
                        if (!words.count(tf)) continue;
                        
                        if (pb->count(tf)) {
                            return len;
                        }
                        
                        tmp.insert(tf);
                    }
                }
            }
            
            pf->swap(tmp);
            ++len;
        }
        
        return 0;
    }

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


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(begin(wordList), end(wordList), endWord) == wordList.end()) return 0;
        
        unordered_set<string> words(begin(wordList), end(wordList));
        
        const int n = beginWord.length();
        
        unordered_set<string> p{beginWord}, q{endWord};
        int level = 2;
        while (!p.empty() && !q.empty()) {
            if (p.size() > q.size()) swap(p, q);
            
            unordered_set<string> t;
            for (string w : p) {
                words.erase(w);
                
                for (int i = 0; i < n; ++i) {
                    char o = w[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        w[i] = c;
                        if (q.count(w)) return level;
                        if (words.count(w) == 0) continue;
                        t.insert(w);
                    }   
                    w[i] = o;
                }
            }
            
            p = move(t);
            ++level;
        }
        
        return 0;
    }
};