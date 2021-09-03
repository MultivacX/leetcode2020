// 1989. Maximum Number of People That Can Be Caught in Tag
// https://leetcode.com/problems/maximum-number-of-people-that-can-be-caught-in-tag/

// Runtime: 166 ms, faster than 100.00% of C++ online submissions for Maximum Number of People That Can Be Caught in Tag.
// Memory Usage: 80.8 MB, less than 100.00% of C++ online submissions for Maximum Number of People That Can Be Caught in Tag.
    
class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        const int n = team.size();
        
        int caught = 0;
        
        queue<int> its, nts;
        for (int i = 0; i < n; ++i) {
            team[i] == 0 ? nts.push(i) : its.push(i);
            
            while (!its.empty() && !nts.empty()) {
                int it = its.front();
                int nt = nts.front();
                if (it < nt) {
                    its.pop();
                    if (nt - it <= dist) {
                        ++caught;
                        nts.pop();
                    }
                } else {
                    nts.pop();
                    if (it - nt <= dist) {
                        ++caught;
                        its.pop();
                    }
                }
            }
        }
        
        return caught;
    }
};