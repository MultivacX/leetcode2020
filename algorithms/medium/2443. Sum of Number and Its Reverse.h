// 2443. Sum of Number and Its Reverse
// https://leetcode.com/problems/sum-of-number-and-its-reverse/

class Solution
{
    int reverse(int a)
    {
        int b = 0;
        while (a)
        {
            b = b * 10 + a % 10;
            a /= 10;
        }
        return b;
    }

public:
    bool sumOfNumberAndReverse(int num)
    {
        int a = num;
        int b = reverse(a);
        int hi = b % 10;
        while (a)
        {
            // cout << a << "  " << b << endl;
            if (a + b == num)
                return true;

            --a;
            b = reverse(a);

            int t = b % 10;
            if (t * 2 + 1 < hi)
                return false;
        }
        return num == 0;
    }
};