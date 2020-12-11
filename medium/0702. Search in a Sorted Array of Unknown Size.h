// 702. Search in a Sorted Array of Unknown Size
// https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/

// Runtime: 28 ms, faster than 80.33% of C++ online submissions for Search in a Sorted Array of Unknown Size.
// Memory Usage: 10.4 MB, less than 34.23% of C++ online submissions for Search in a Sorted Array of Unknown Size.
    
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 10000;
        while (l < r) {
            int m = l + (r - l) / 2;
            int v = reader.get(m);
            if (v == target) return m;
            if (v < target) l = m + 1;
            else r = m;
        }
        return -1;
    }
};