// 1899. Merge Triplets to Form Target Triplet
// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

// Runtime: 444 ms, faster than 98.63% of C++ online submissions for Merge Triplets to Form Target Triplet.
// Memory Usage: 146.4 MB, less than 85.92% of C++ online submissions for Merge Triplets to Form Target Triplet.
    
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int i = 0;
        int a = 0, b = 0, c = 0;
        while (i < triplets.size()) {
            if (triplets[i][0] > target[0] ||
                triplets[i][1] > target[1] ||
                triplets[i][2] > target[2]) {
                triplets[i][0] = triplets.back()[0];
                triplets[i][1] = triplets.back()[1];
                triplets[i][2] = triplets.back()[2];
                triplets.pop_back();
            } else {
                a = max(a, triplets[i][0]);
                b = max(b, triplets[i][1]);
                c = max(c, triplets[i][2]);
                ++i;
            }
        }
        return a == target[0] && b == target[1] && c == target[2];
    }
};