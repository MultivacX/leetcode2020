// 126. Word Ladder II

// Runtime: 452 ms, faster than 46.76% of C++ online submissions for Word Ladder II.
// Memory Usage: 24.7 MB, less than 85.00% of C++ online submissions for Word Ladder II.

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return ans;
        
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> q{{beginWord}};
        int level = 0;
        vector<vector<int>> m{{-1}};
        
        while (!words.empty() && !q.back().empty()) {
            for (const string& cur : q[level]) words.erase(cur);
            
            bool found = false;
            vector<string> children;
            vector<int> parents;
            for (int j = 0; j < q[level].size(); ++j) {
                bool f = nextLevel(endWord, q[level][j], words, children, parents, j);
                if (f) found = true;
            }
            q.push_back(children);
            m.push_back(parents);
            ++level;
            
            if (found) {
                for (int j = 0; j < q[level].size(); ++j) {
                    if (q[level][j] == endWord) {
                        vector<string> path{endWord};
                        build(q, m, level, j, path);
                        reverse(path.begin(), path.end());
                        ans.push_back(path);
                    }
                }
                break;
            }
        }
        
        return ans;
    }
    
    bool nextLevel(const string& endWord, 
                   const string& cur, 
                   unordered_set<string>& words, 
                   vector<string>& children, 
                   vector<int>& parents,
                   int j) {
        bool found = false;
        for (int i = 0; i < cur.length(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                string tf(cur);
                tf[i] = c;
                if (!words.count(tf)) continue;
                if (!found && tf == endWord) found = true;
                children.push_back(tf);
                parents.push_back(j);
            }
        }
        return found;
    }
    
    void build(vector<vector<string>>& q, vector<vector<int>>& m, int level, int j, vector<string>& path) {
        if (level <= 0) return;
        int idx = m[level][j];
        path.push_back(q[level - 1][idx]);
        build(q, m, level - 1, idx, path);
    }

	// WRONG
    /*vector<vector<string>> ans;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return ans;
        
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<string> list;
        f(beginWord, endWord, words, list);
        return ans;
    }
    
    void f(string beginWord, 
           string endWord, 
           unordered_set<string>& words, 
           vector<string>& list) {
        
        if (beginWord == endWord) {
            list.push_back(beginWord);
            ans.push_back(list);
            list.pop_back();
            return;
        }
        
        list.push_back(beginWord);
        
        unordered_set<string> tmp;
        for (int i = 0; i < beginWord.length(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                string tf(beginWord);
                tf[i] = c;

                if (tf == endWord) {
                    f(tf, endWord, words, list);
                    list.pop_back();
                    return;
                }
                if (!words.count(tf)) continue;
                
                words.erase(tf);
                tmp.insert(tf);
            }
        }
        
        for (const string& tf : tmp) {
            f(tf, endWord, words, list);
        }
        
        list.pop_back();
    }*/
};