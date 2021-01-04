// 760. Find Anagram Mappings
// https://leetcode.com/problems/find-anagram-mappings/

// Runtime: 4 ms, faster than 70.56% of C++ online submissions for Find Anagram Mappings.
// Memory Usage: 9.2 MB, less than 21.32% of C++ online submissions for Find Anagram Mappings.
    
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < N; ++i) m[B[i]].push_back(i);
        
        vector<int> ans(N);
        for (int i = 0; i < N; ++i) {
            ans[i] = m[A[i]].back();
            m[A[i]].pop_back();
        }
        return ans;
    }
};