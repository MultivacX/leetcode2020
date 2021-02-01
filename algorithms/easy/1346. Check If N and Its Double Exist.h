// 1346. Check If N and Its Double Exist

// Runtime: 16 ms, faster than 30.26% of C++ online submissions for Check If N and Its Double Exist.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Check If N and Its Double Exist.

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        const int N = arr.size();
        unordered_set<int> visited{arr.back()};
        for (int i = N - 2; i >= 0; --i) {
            if (visited.count(arr[i] * 2)) return true;
            if (arr[i] % 2 == 0 && visited.count(arr[i] / 2)) return true;
            visited.insert(arr[i]);
        }
        return false;
    }
};