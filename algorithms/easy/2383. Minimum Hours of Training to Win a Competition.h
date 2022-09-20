// 2383. Minimum Hours of Training to Win a Competition
// https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/

// Runtime: 7 ms, faster than 44.96% of C++ online submissions for Minimum Hours of Training to Win a Competition.
// Memory Usage: 11.3 MB, less than 33.02% of C++ online submissions for Minimum Hours of Training to Win a Competition.

class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int res = 0;

        for (int i = 0; i < energy.size(); ++i)
        {
            if (initialEnergy <= energy[i])
            {
                int offset = energy[i] - initialEnergy + 1;
                initialEnergy += offset;
                res += offset;
            }
            initialEnergy -= energy[i];

            if (initialExperience <= experience[i])
            {
                int offset = experience[i] - initialExperience + 1;
                initialExperience += offset;
                res += offset;
            }
            initialExperience += experience[i];
        }

        return res;
    }
};