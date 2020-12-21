// 734. Sentence Similarity
// https://leetcode.com/problems/sentence-similarity/

// Runtime: 12 ms, faster than 87.20% of C++ online submissions for Sentence Similarity.
// Memory Usage: 11.4 MB, less than 89.57% of C++ online submissions for Sentence Similarity.
    
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        if (similarPairs.empty()) return sentence1 == sentence2;
        
        unordered_set<string> s;
        for (auto& p : similarPairs) 
            s.insert(p[0] + "#" + p[1]);
        
        for (int i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i]) continue;
            if (s.count(sentence1[i] + "#" + sentence2[i])) continue;
            if (s.count(sentence2[i] + "#" + sentence1[i])) continue;
            return false;
        }
        return true;
    }
};