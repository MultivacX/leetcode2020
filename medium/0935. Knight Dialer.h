// 935. Knight Dialer

// Runtime: 656 ms, faster than 10.57% of C++ online submissions for Knight Dialer.
// Memory Usage: 43.5 MB, less than 14.29% of C++ online submissions for Knight Dialer.

class Solution {
public:
    int knightDialer(int N) {
        static const vector<vector<int>> next_hops{
            {4, 6, },
            {8, 6, },
            {7, 9, },
            {4, 8, },
            {0, 9, 3, },
            {},
            {7, 0, 1, },
            {2, 6, },
            {1, 3, },
            {4, 2, },
        };
        
        vector<uint64_t> phone_nums(10, 1);
        for (int i = 1; i < N; ++i) {
            vector<uint64_t> next_phone_nums(10, 0);
            for (int j = 0; j <= 9; ++j) {
                for (int next : next_hops[j]) {
                    next_phone_nums[next] = (next_phone_nums[next] + phone_nums[j]) % 1000000007;
                }
            }
            phone_nums = next_phone_nums;
        }
        
        int ans = 0;
        for (int i = 0; i <= 9; ++i)
            ans = (ans + phone_nums[i] % 1000000007) % 1000000007;
        return ans;
    }
    
    void prepare() {
        const vector<vector<int>> directions{
            { 1, -2}, { 2, -1}, { 2, 1}, { 1, 2},
            {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
        };
        const vector<vector<int>> pad{
            {1, 2, 3},  
            {4, 5, 6},
            {7, 8, 9},
            {-1, 0, -1}
        };
        vector<vector<int>> next_hops(10, vector<int>());
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                int key = pad[i][j];
                if (key == -1) continue;
                
                for (auto& d : directions) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if (ni < 0 || ni >= 4 || nj < 0 || nj >= 3 || pad[ni][nj] == -1)
                        continue;
                    next_hops[key].push_back(pad[ni][nj]);
                }
            }
        }
        for (int i = 0; i <= 9; ++i) {
            cout << "{";
            for (int next : next_hops[i]) cout << next << ", ";
            cout << "}," << endl;
        }
    }
};