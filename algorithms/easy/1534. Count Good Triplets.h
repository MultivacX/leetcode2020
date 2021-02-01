// 1534. Count Good Triplets
// https://leetcode.com/problems/count-good-triplets/

// Runtime: 20 ms, faster than 98.20% of C++ online submissions for Count Good Triplets.
// Memory Usage: 8.4 MB, less than 98.35% of C++ online submissions for Count Good Triplets.
    
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        const int N = arr.size();
        int cnt = 0;
        for (int i = 0; i + 2 < N; ++i) {
            for (int j = i + 1; j + 1 < N; ++j) {
                if (abs(arr[i] - arr[j]) > a)
                    continue;
                for (int k = j + 1; k < N; ++k) {
                    if (abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c)
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};