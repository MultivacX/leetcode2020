// 2024. Maximize the Confusion of an Exam
// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

// Runtime: 67 ms, faster than 26.41% of C++ online submissions for Maximize the Confusion of an Exam.
// Memory Usage: 10 MB, less than 91.71% of C++ online submissions for Maximize the Confusion of an Exam.

class Solution
{
    int consecutive(const string &answerKey, int k, char c)
    {
        const int n = answerKey.length();
        int res = 0;
        for (int i = 0, b = 0, x = k; i < n; ++i)
        {
            if (answerKey[i] != c)
                --x;
            while (x < 0)
            {
                if (answerKey[b] != c)
                    ++x;
                ++b;
            }
            res = max(res, i - b + 1);
        }
        return res;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        return max(consecutive(answerKey, k, 'T'), consecutive(answerKey, k, 'F'));
    }
};