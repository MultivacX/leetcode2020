// 870. Advantage Shuffle

// Runtime: 220 ms, faster than 55.38% of C++ online submissions for Advantage Shuffle.
// Memory Usage: 18.5 MB, less than 75.00% of C++ online submissions for Advantage Shuffle.

// Time Complexity: O(N*lgN), where N is the length of A.
// Space Complexity: O(N).

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        map<int, int> M;
        for (int a : A) ++M[a];
        
        vector<int> C(A.size());
        for (int i = 0; i < A.size(); ++i) {
            auto it = M.upper_bound(B[i]);
            if (it == M.end()) it = M.begin();
            C[i] = it->first;
            --it->second;
            if (it->second == 0) M.erase(it);
        }
        return C;
    }
};