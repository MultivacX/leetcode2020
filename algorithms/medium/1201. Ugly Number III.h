// 1201. Ugly Number III

// Runtime: 4 ms, faster than 7.05% of C++ online submissions for Ugly Number III.
// Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Ugly Number III.

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int> bases{a, b, c};
        sort(begin(bases), end(bases));
        
        int num = n * bases[0];
        a = bases[0];
        b = bases[1];
        c = bases[2];
        
        int cnt_a = n; // num / a;
        int cnt_b = num / b;
        int cnt_c = num / c;
        
        // cnt_a + cnt_b + cnt_c >= n
        // [a, num] == a * i + b * j + c * k
        // i, j, k >= 1
        // 1 <= i + j + k <= cnt_a + cnt_b + cnt_c
        
        vector<int> nums;
        int j = 1;
        int k = 1;
        while (j <= cnt_b && k <= cnt_c) {
            int bj = b * j;
            if (bj % a == 0) {
                ++j;
                continue;
            }
            
            int ck = c * k;
            if (ck % a == 0 || ck % b == 0) {
                ++k;
                continue;
            }
            
            int minv = min(bj, ck);
            if (minv == bj) ++j;
            if (minv == ck) ++k;
            nums.push_back(minv);
        }
        while (j <= cnt_b) {
            int bj = b * j;
            if (bj % a != 0) nums.push_back(bj);
            ++j;
        }
        while (k <= cnt_c) {
            int ck = c * k;
            if (ck % a != 0 && ck % b != 0) nums.push_back(ck);
            ++k;
        }
        
        int i = n;
        while (i > 0 && i + nums.size() > n) {
            int ai = a * i;
            int v = nums.back();
            int maxv = max(ai, v);
            if (maxv == ai) --i;
            if (maxv == v) nums.pop_back();

            num = max(a * i, nums.empty() ? 0 : nums.back());
        }
        return num;
    }
};

// Memory Limit Exceeded
/*class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<uint64_t> nums{1};
        int ai = 1;
        int bi = 1;
        int ci = 1;
        while (nums.size() <= n) {
            uint64_t an = ai * a;
            uint64_t bn = bi * b;
            uint64_t cn = ci * c;
            uint64_t minv = min(an, min(bn, cn));
            if (minv == an) ++ai;
            if (minv == bn) ++bi;
            if (minv == cn) ++ci;
            nums.push_back(minv);
            // cout << minv << endl;
        }
        return nums[n];
    }
};*/