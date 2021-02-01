// 915. Partition Array into Disjoint Intervals

// Runtime: 44 ms, faster than 46.53% of C++ online submissions for Partition Array into Disjoint Intervals.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Partition Array into Disjoint Intervals.

// Time Complexity: O(N), where N is the length of A.
// Space Complexity: O(1).

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int max_a = A[0];
        int min_l = A[0];
        int max_l = A[0];
        int idx = 0;
        for (int i = 1; i < A.size(); ++i) {
            max_a = max(max_a, A[i]);
            
            if (A[i] < min_l) {
                min_l = A[i];
                max_l = max_a;
                idx = i;
            } else if (A[i] < max_l) {
                max_l = max_a;
                idx = i;
            }
        }
        return idx + 1;
    }
};