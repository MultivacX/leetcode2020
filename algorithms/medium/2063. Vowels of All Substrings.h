// 2063. Vowels of All Substrings
// https://leetcode.com/problems/vowels-of-all-substrings/

// Runtime: 42 ms, faster than 25.68% of C++ online submissions for Vowels of All Substrings.
// Memory Usage: 10.9 MB, less than 98.34% of C++ online submissions for Vowels of All Substrings.

class Solution
{
public:
    long long countVowels(string word)
    {
        auto n = word.length();
        long long ans = 0;
        for (long long i = 0; i < n; ++i)
        {
            static const string vowels = "aeiou";
            if (vowels.find(word[i]) == string::npos)
            {
                continue;
            }
            long long l = i, r = n - i - 1;
            ans += 1 + l + r + l * r;
        }
        return ans;
    }
};