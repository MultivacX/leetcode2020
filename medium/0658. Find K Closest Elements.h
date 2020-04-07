// 658. Find K Closest Elements

// Runtime: 176 ms, faster than 13.36% of C++ online submissions for Find K Closest Elements.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Find K Closest Elements.

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (x <= arr.front()) return vector<int>(arr.begin(), arr.begin() + k);
        if (x >= arr.back()) return vector<int>(arr.end() - k, arr.end());
        
        // arr.front() < x < arr.back()
        int j = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
        // arr[j - 1] < x <= arr[j]
        if (x - arr[j - 1] < arr[j] - x) --j;
        
        int i = j;
        while (j - i + 1 < k) {
            if (i - 1 < 0) ++j;
            else if (j + 1 >= arr.size()) --i;
            else if (abs(x - arr[i - 1]) <= abs(arr[j + 1] - x)) --i;
            else ++j;
        }
        return vector<int>(arr.begin() + i, arr.begin() + j + 1);
    }
};