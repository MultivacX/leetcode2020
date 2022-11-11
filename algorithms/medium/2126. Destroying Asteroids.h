// 2126. Destroying Asteroids
// https://leetcode.com/problems/destroying-asteroids/

// Runtime: 504 ms, faster than 46.06% of C++ online submissions for Destroying Asteroids.
// Memory Usage: 102.8 MB, less than 49.49% of C++ online submissions for Destroying Asteroids.

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());
        for (int a : asteroids)
        {
            if (mass < a)
                return false;
            if (mass < asteroids.back())
                mass += a;
            else
                return true;
        }
        return true;
    }
};