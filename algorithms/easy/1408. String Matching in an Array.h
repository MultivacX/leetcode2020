// 1408. String Matching in an Array
// https://leetcode.com/problems/string-matching-in-an-array/

// Runtime: 4 ms, faster than 95.93% of C++ online submissions for String Matching in an Array.
// Memory Usage: 8.3 MB, less than 98.64% of C++ online submissions for String Matching in an Array.
    
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> ans;
        for (int i = 0; i + 1 < words.size(); ++i) {
            int M = words[i].length();
            for (int j = i + 1; j < words.size(); ++j) {
                int N = words[j].length();
                if (M >= N && words[i].find(words[j]) != string::npos)
                    ans.insert(words[j]);
                else if (M < N && words[j].find(words[i]) != string::npos)
                    ans.insert(words[i]);
            }    
        }
        return vector<string>(begin(ans), end(ans));
    }
};