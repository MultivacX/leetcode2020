// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Runtime: 12 ms, faster than 49.24% of C++ online submissions for Two Sum II - Input array is sorted.
// Memory Usage: 10 MB, less than 99.96% of C++ online submissions for Two Sum II - Input array is sorted.

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = lower_bound(begin(numbers) + i + 1, end(numbers), target - numbers[i]) - begin(numbers);
        while (numbers[i] + numbers[j] != target) {
            ++i;
            j = lower_bound(begin(numbers) + i + 1, begin(numbers) + j, target - numbers[i]) - begin(numbers);
        }
        return {i + 1, j + 1};
    }
};