class Solution {
    int distance(vector<vector<int>>& workers, vector<vector<int>>& bikes, int i, int j) {
        return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        const int M = workers.size();
        const int N = bikes.size();
        
        unordered_set<int> visited;
        // cost, i, assigned
        auto cmp = [](array<int, 3>& a, array<int, 3>& b) { return a[0] > b[0]; };
        using Q = priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)>;
		Q* q = new Q(cmp);
        q->push({0, 0, 0});
        int b = 0;
        while (true) {
            Q* p = new Q(cmp);
            while (!q->empty()) {
                int cost = q->top()[0];
                int i = q->top()[1];
                int assigned = q->top()[2];
                if (!visited.insert((b << 10) | assigned).second)
                    continue;
                if (i == M) { delete q; return cost;}
                q->pop();
                for (int j = 0; j < N; ++j) {
                    if (assigned & (1 << j))
                        continue;
                    int nc = cost + distance(workers, bikes, i, j);
                    int ni = i + 1;
                    int na = assigned | (1 << j);
                    p->push({nc, ni, na});
                    
                    cout << bitset<20>((b << 10) | assigned) << ": ";
                    cout << nc << ", " << ni << ", " << bitset<10>(na) << endl;
                }
                cout << endl;
            }
            b = (b << 1) | 1;
            swap(q, p);
            delete p;
        }
        delete q;
        return -1;
    }
};