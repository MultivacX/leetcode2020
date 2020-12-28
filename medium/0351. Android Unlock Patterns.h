// 351. Android Unlock Patterns

// WRONG: 4
class Solution {
    void connect(int i, int j, int used, int l, int L, int& cnt) {
        if (l == L) {
            ++cnt;
            return;
        }
        
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                int v = r * 3 + c;
                if (used & (1 << v)) continue;
                
                int w = -1;
                if (i == r && abs(j - c) == 2) {
                    w = r * 3 + (j + c) / 2;
                } else if (j == c && abs(i - r) == 2) {
                    w = (i + r) / 2 * 3 + c;
                } else if (abs(i - r) == 2 && abs(j - c) == 2) {
                    w = 4;
                } 
                if (w >= 0 && (used & (1 << w)) == 0) continue;
                
                connect(r, c, used & (1 << v), l + 1, L, cnt);
            }
        }
    }
    
public:
    int numberOfPatterns(int m, int n) {
        // start from: 
        // 1:  1/3/7/9
        // 2:  2/4/6/8
        // 3:  5
        
        int ans = 0;
        for (int L = m; L <= n; ++L) {
            if (L == 1) {
                ans += 9;
                continue;
            }
            
            int cur = 0;
            
            // 1->2/4
            int cnt = 0;
            connect(0, 1, 0b11, 2, L, cnt);
            cur += 4 * 2 * cnt;
            
            // 1->6/8
            cnt = 0;
            connect(1, 2, 0b100001, 2, L, cnt);
            cur += 4 * 2 * cnt;
            
            // 1->5
            cnt = 0;
            connect(1, 1, 0b10001, 2, L, cnt);
            cur += 4 * cnt;
            
            // 2->1/3
            cnt = 0;
            connect(0, 0, 0b11, 2, L, cnt);
            cur += 4 * 2 * cnt;
            
            // 2->4/6
            cnt = 0;
            connect(1, 0, 0b1010, 2, L, cnt);
            cur += 4 * 2 * cnt;
            
            // 2->7/9
            cnt = 0;
            connect(2, 0, 0b1000010, 2, L, cnt);
            cur += 4 * 2 * cnt;
            
            // 2->5
            cnt = 0;
            connect(1, 1, 0b10010, 2, L, cnt);
            cur += 4 * cnt;
            
            // 5->2/4/6/8
            cnt = 0;
            connect(0, 1, 0b10010, 2, L, cnt);
            cur += 4 * cnt;
            
            // 5->1/3/7/9
            cnt = 0;
            connect(0, 0, 0b10001, 2, L, cnt);
            cur += 4 * cnt;
            
            ans += cur;
        }
        return ans;
    }
};