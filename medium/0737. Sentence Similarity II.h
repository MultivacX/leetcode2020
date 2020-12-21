// 737. Sentence Similarity II
// https://leetcode.com/problems/sentence-similarity-ii/

// Runtime: 608 ms, faster than 26.09% of C++ online submissions for Sentence Similarity II.
// Memory Usage: 71.6 MB, less than 44.57% of C++ online submissions for Sentence Similarity II.
    
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        unordered_map<string, int> w1; for (auto s : words1) ++w1[s];
        unordered_map<string, int> w2; for (auto s : words2) ++w2[s];
        if (pairs.empty()) return w1 == w2;
        
        unordered_map<string, string> parents;
        for (auto& p : pairs) {
            if (parents.count(p[0]) == 0) {
                if (parents.count(p[1]) == 0) 
                    parents[p[1]] = p[1];
                parents[p[0]] = parents[p[1]];
            } else if (parents.count(p[1]) == 0) {
                if (parents.count(p[0]) == 0) 
                    parents[p[0]] = p[0];
                parents[p[1]] = parents[p[0]];
            } else {
                auto t = parents[p[0]];
                auto s = parents[p[1]];
                for (auto& it : parents) 
                    if (it.second == t)
                        it.second = s;
            }
        }
        
        unordered_map<string, unordered_set<string>> m;
        for (auto it : parents) 
            m[it.second].insert(it.first);
            
        while (!w1.empty() && !w2.empty()) {
            auto s = w1.begin()->first;
            if (w2.count(s)) {
                if (--w1[s] == 0) w1.erase(s);
                if (--w2[s] == 0) w2.erase(s);
                continue;
            }
            
            if (parents.count(s) == 0) 
                return false;
            
            auto& p = parents[s];
            if (m.count(p) == 0)
                return false;
            
            bool found = false;
            for (auto t : m[p]) {
                if (w2.count(t)) {
                    if (--w1[s] == 0) w1.erase(s);
                    if (--w2[t] == 0) w2.erase(t);
                    found = true;
                    break;
                }
            }
            if (!found) 
                return false;
        }
        return w1.empty() && w2.empty();
    }
};