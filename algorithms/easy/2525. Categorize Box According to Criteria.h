// 2525. Categorize Box According to Criteria

class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        uint64_t v = length;
        v *= width;
        v *= height;

        bool Bulky = length >= 10000 || width >= 10000 || height >= 10000 || v >= 1000000000;
        bool Heavy = mass >= 100;

        if (Bulky && Heavy)
            return "Both";
        if (!Bulky && !Heavy)
            return "Neither";
        if (Bulky && !Heavy)
            return "Bulky";
        return "Heavy";
    }
};