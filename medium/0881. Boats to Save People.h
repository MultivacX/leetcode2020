// 881. Boats to Save People
// https://leetcode.com/problems/boats-to-save-people/

// Runtime: 412 ms, faster than 14.64% of C++ online submissions for Boats to Save People.
// Memory Usage: 42.1 MB, less than 34.87% of C++ online submissions for Boats to Save People.

// Time Complexity: O(N * logN), where N is the length of people.
// Space Complexity: O(N).

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(begin(people), end(people));
        int i = 0;
        int j = people.size() - 1;
        while (i < j) {
            if (people[i] + people[j] <= limit) {
                ++i;
                --j;
                ++ans;
            } else if (people[i] * 2 > limit && people[j] * 2 > limit) {
                return ans + j - i + 1;
            } else {
                --j;
                ++ans;
            }
        }
        return ans + (i == j ? 1 : 0);
    }
};