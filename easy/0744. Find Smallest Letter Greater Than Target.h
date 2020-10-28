// 744. Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

// Runtime: 28 ms, faster than 62.12% of C++ online submissions for Find Smallest Letter Greater Than Target.
// Memory Usage: 16.3 MB, less than 100.00% of C++ online submissions for Find Smallest Letter Greater Than Target.

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans;
        int diff = 0;
        for (char c : letters) {
            int d = 0;
            if (c > target) d = c - target;
            else if (c < target) d = c - target + 26;
            else continue;
                
            if (diff == 0 || diff > d) {
                ans = c;
                diff = d;
            }
        }
        return ans;
    }
};