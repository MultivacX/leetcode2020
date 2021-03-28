// 1805. Number of Different Integers in a String
// https://leetcode.com/problems/number-of-different-integers-in-a-string/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Different Integers in a String.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Number of Different Integers in a String.
    
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> nums;
        string cur;
        for (int i = 0; i < word.length(); ++i) {
            bool b = isdigit(word[i]);
            if (b) cur.push_back(word[i]);
            
            if ((!b || i + 1 == word.length()) && !cur.empty()) {
                int j = 0;
                while (j < cur.length() && cur[j] == '0')
                    ++j;
                if (j == cur.length()) nums.insert("0");
                else nums.insert(cur.substr(j));
                cur.clear();
            }
        }
        return nums.size();
    }
};