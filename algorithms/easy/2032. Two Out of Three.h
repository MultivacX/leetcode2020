// 2032. Two Out of Three
// https://leetcode.com/problems/two-out-of-three/

// Runtime: 3 ms, faster than 100.00% of C++ online submissions for Two Out of Three.
// Memory Usage: 25.5 MB, less than 82.04% of C++ online submissions for Two Out of Three.

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        vector<int> arr(101);

        for (int i : nums1)
            arr[i] = 1;
        for (int i : nums2)
            arr[i] |= 2;
        for (int i : nums3)
            arr[i] |= 4;

        // for (int i = 1; i <= 100; ++i) cout << arr[i] << " "; cout << endl;

        vector<int> res;
        for (int i = 1; i <= 100; ++i)
            if (arr[i] == 3 || arr[i] == 5 || arr[i] == 6 || arr[i] == 7)
                res.push_back(i);
        return res;
    }
};