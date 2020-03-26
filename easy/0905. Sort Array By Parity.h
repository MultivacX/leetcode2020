// 905. Sort Array By Parity

// Runtime: 28 ms, faster than 69.63% of C++ online submissions for Sort Array By Parity.
// Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for Sort Array By Parity.

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> a;
        vector<int> b;
        for (int i : A) (i & 1) ? b.push_back(i) : a.push_back(i);
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};