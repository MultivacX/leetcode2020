// 781. Rabbits in Forest

// Runtime: 12 ms, faster than 13.90% of C++ online submissions for Rabbits in Forest.
// Memory Usage: 8.9 MB, less than 50.00% of C++ online submissions for Rabbits in Forest.

// Time Complexity: O(answers.size()).
// Space Complexity: O(answers.size()).

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int i : answers) ++m[i];
        for (auto& it : m) {
            int num = it.first + 1;
            ans += it.second / num * num + (it.second % num == 0 ? 0 : num);
        }
        return ans;
    }
};