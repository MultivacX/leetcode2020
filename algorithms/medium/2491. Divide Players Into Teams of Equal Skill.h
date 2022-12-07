// 2491. Divide Players Into Teams of Equal Skill
// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        /*if (skill.size() & 1)
            return -1;*/

        sort(skill.begin(), skill.end());
        int i = 0, j = skill.size() - 1;
        int sum = skill[i] + skill[j];
        long long res = skill[i++] * skill[j--];
        while (i < j)
        {
            if (sum != skill[i] + skill[j])
                return -1;
            res += skill[i++] * skill[j--];
        }
        return res;
    }
};

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int cnt[1001] = {0};
        for (int s : skill)
            ++cnt[s];

        int i = 1, j = 1000;
        while (cnt[i] == 0)
            ++i;
        while (cnt[j] == 0)
            --j;

        int sk = i + j;
        long long sum = i * j;
        --cnt[i];
        --cnt[j];

        while (i <= j)
        {
            if (cnt[i] == 0)
            {
                ++i;
                continue;
            }
            if (cnt[j] == 0)
            {
                --j;
                continue;
            }

            if (i == j && (cnt[i] & 1))
                return -1;
            if (sk != i + j)
                return -1;

            sum += i * j;

            --cnt[i];
            --cnt[j];
        }
        return sum;
    }
};