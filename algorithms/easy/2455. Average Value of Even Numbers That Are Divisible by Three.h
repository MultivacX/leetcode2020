// 2455. Average Value of Even Numbers That Are Divisible by Three

class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int sum = 0, k = 0;
        for (int i : nums)
        {
            if (i & 1)
                continue;
            if (i % 3)
                continue;
            sum += i;
            ++k;
        }
        return k == 0 ? 0 : sum / k;
    }
};