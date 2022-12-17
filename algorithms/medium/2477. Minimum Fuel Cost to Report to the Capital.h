// 2477. Minimum Fuel Cost to Report to the Capital

class Solution
{
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        int n = 0;
        unordered_map<int, vector<int>> m;
        for (auto &r : roads)
            m[r[0]].push_back(r[1]),
                m[r[1]].push_back(r[0]),
                n = max({n, r[0], r[1]});
        ++n;

        vector<array<int, 3>> cities(n); // {dist_to_0, idx, representatives}
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int i = q.front();
                q.pop();

                for (int j : m[i])
                {
                    if (j == 0 || cities[j][1] != 0)
                        continue;

                    cities[j][0] = cities[i][0] + 1;
                    cities[j][1] = j;
                    q.push(j);
                }
            }
        }
        sort(cities.begin(), cities.end());

        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            int idx = cities[i][1];
            v[idx] = i;
        }

        // for (auto& p : cities) cout << '[' << p[1] << "]:  " << p[0] << endl;

        long long res = 0;
        int i = n - 1;
        while (i > 0)
        {
            int j = i, dist = cities[i][0];
            // cout << "dist: " <<  dist << endl;
            while (j >= 0 && cities[j][0] == dist)
            {
                // add representative of j
                cities[j][2] += 1;

                int city_j = cities[j][1];

                // move from j to k
                for (int city_k : m[city_j])
                {
                    int k = v[city_k];
                    if (cities[k][0] < dist)
                    {
                        res += cities[j][2] / seats + min(cities[j][2] % seats, 1);
                        cities[k][2] += cities[j][2];
                    }
                }

                --j;
            }
            i = j;
        }
        return res;
    }
};