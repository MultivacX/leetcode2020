// 927. Three Equal Parts

// Runtime: 48 ms, faster than 19.61% of C++ online submissions for Three Equal Parts.
// Memory Usage: 11.1 MB, less than 100.00% of C++ online submissions for Three Equal Parts.

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        // all zero: [0, ..., 0]
        // count(1) % 3 == 0
        // remove 0 from left
        // last bit is A[N - 1]
        
        const int N = A.size();
        int cnt1 = 0;
        for (int a : A) cnt1 += a;
        if (cnt1 == 0) return {0, 2};
        if (cnt1 % 3) return {-1, -1};
        
        cnt1 /= 3;
        int rightest_cnt0 = 0;
        for (int i = N - 1; i >= 0 && A[i] == 0; --i) ++rightest_cnt0;
        
        // the same binary value: has cnt1 1 s, and end with rightest_cnt0 0 s
        
        int i = 0;
        string left;
        if (!check_count(A, i, left, cnt1, rightest_cnt0)) return {-1, -1};
        int l = i;
        
        string mid;
        if (!check_count(A, i, mid, cnt1, rightest_cnt0)) return {-1, -1};
        if (left != mid) return {-1, -1};
        int r = i;
        
        string right;
        if (!check_count(A, i, right, cnt1, rightest_cnt0)) return {-1, -1};
        if (mid != right) return {-1, -1};
        
        return {l - 1, r};
    }
    
    bool check_count(const vector<int>& A, int& i, string& value, int cnt1, int rightest_cnt0) {
        while (i < A.size()) {
            if (A[i] == 1) {
                if (cnt1 == 0) return rightest_cnt0 == 0;
                value += '1';
                --cnt1;
            } else if (value.empty()) {
                // 
            } else if (cnt1 > 0) {
                value += '0';
            } else if (rightest_cnt0 > 0) {
                value += '0';
                --rightest_cnt0;
            } else {
                break;
            }
            
            ++i;
        }
        return true;
    }
};