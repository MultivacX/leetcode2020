// 2079. Watering Plants
// https://leetcode.com/problems/watering-plants/

// Runtime: 16 ms, faster than 5.73% of C++ online submissions for Watering Plants.
// Memory Usage: 8.3 MB, less than 98.83% of C++ online submissions for Watering Plants.

class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        const int n = plants.size();
        int res = 0, cur = capacity;
        for (int i = 0; i < n; ++i)
        {
            if (cur < plants[i])
            {
                res += i;     // refill
                res += i + 1; // water i
                cur = capacity - plants[i];
            }
            else
            {
                res += 1; // water i
                cur -= plants[i];
            }
        }
        return res;
    }
};