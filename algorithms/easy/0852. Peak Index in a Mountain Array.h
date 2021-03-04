// 852. Peak Index in a Mountain Array

// Runtime: 16 ms, faster than 67.35% of C++ online submissions for Peak Index in a Mountain Array.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Peak Index in a Mountain Array.

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (int i = 1; i < A.size() - 1; ++i) {
            if (A[i - 1] < A[i] && A[i] > A[i + 1])
                return i;
        }
        return -1;
    }
};


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr[m - 1] < arr[m] && arr[m] > arr[m + 1]) 
                return m;
            arr[m - 1] < arr[m] ? l = m : r = m;
        }
        return l;
    }
};