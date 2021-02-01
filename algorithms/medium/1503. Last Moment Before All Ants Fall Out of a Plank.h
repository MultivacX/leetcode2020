// 1503. Last Moment Before All Ants Fall Out of a Plank
// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

// Runtime: 44 ms, faster than 81.16% of C++ online submissions for Last Moment Before All Ants Fall Out of a Plank.
// Memory Usage: 23.2 MB, less than 10.96% of C++ online submissions for Last Moment Before All Ants Fall Out of a Plank.
    
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // When two ants moving in two different directions 
        // meet at some point,
        // swap two ants
        int maxv = left.empty() ? 0 : *max_element(begin(left), end(left));
        int minv = right.empty() ? n : *min_element(begin(right), end(right));
        return max(maxv, n - minv);
    }
};