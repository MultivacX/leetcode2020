// 989. Add to Array-Form of Integer
// https://leetcode.com/problems/add-to-array-form-of-integer/

// Runtime: 72 ms, faster than 28.18% of C++ online submissions for Add to Array-Form of Integer.
// Memory Usage: 29.3 MB, less than 6.97% of C++ online submissions for Add to Array-Form of Integer.

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        const int N = A.size();
        vector<int> B;
        int carry = 0;
        for (int i = N - 1; i >= 0; --i) {
            int a = A[i] + carry;
            if (K > 0) {
                int b = K % 10;
                a += b;
                K /= 10;
            }
            B.push_back(a % 10);
            carry = a / 10;
        }
        while (K > 0) {
            int b = K % 10 + carry;
            B.push_back(b % 10);
            carry = b / 10;
            K /= 10;
        }
        if (carry > 0) B.push_back(carry);
        reverse(begin(B), end(B));
        return B;
    }
};