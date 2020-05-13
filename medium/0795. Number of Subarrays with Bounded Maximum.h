// 795. Number of Subarrays with Bounded Maximum

// Runtime: 84 ms, faster than 24.07% of C++ online submissions for Number of Subarrays with Bounded Maximum.
// Memory Usage: 32.5 MB, less than 16.67% of C++ online submissions for Number of Subarrays with Bounded Maximum.

// Time Complexity: O(A.size()).
// Space Complexity: O(1).

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        // for (int a : A) {
        //     if (a > R) cout << "*";
        //     else if (L <= a && a <= R) cout << "!";
        //     cout << a;
        //     if (a > R) cout << "*";
        //     else if (L <= a && a <= R) cout << "!";
        //     cout <<", ";
        // } cout << endl;
        
        int ans = 0;
        // when A[l, ..., i, ... , r) <= R
        // i is the right-most index (i < r) while L <= A[i] <= R
        int l = 0;
        int r = 0;
        int i = -1;
        while (r < A.size()) {
            ++r;
            if (A[r - 1] > R) i = -1;
            else if (i < 0 || L <= A[r - 1] && A[r - 1] <= R) i = r - 1; 
            if (i >= 0) {
                if (L <= A[i] && A[i] <= R) {
                    // for (int j = l; j < r; ++j) cout << A[j] << " "; cout << endl;
                    ans += i + 1 - l;
                }
            } else {
                l = r;
                i = -1;
            }
        }
        return ans;
    }
};