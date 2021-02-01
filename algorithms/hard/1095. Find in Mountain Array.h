// 1095. Find in Mountain Array

// Runtime: 8 ms, faster than 51.31% of C++ online submissions for Find in Mountain Array.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Find in Mountain Array.

// Time Complexity: O(lg(n)).
// Space Complexity: O(1).

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peek_id = findPeek(mountainArr);
        if (mountainArr.get(peek_id) == target) return peek_id;
        
        int l = findLeft(mountainArr, target, 0, peek_id);
        if (l != -1) return l;
        
        int r = findRight(mountainArr, target, peek_id + 1, mountainArr.length());
        if (r != -1) return r;
        
        return -1;
    }
    
    int findPeek(MountainArray &mountainArr) {
        int begin = 0;
        int end = mountainArr.length();
        while (true) {
            int mid = begin + (end - begin) / 2;
            int m = mountainArr.get(mid);
            
            int l = mountainArr.get(mid - 1);
            if (l > m) { end = mid; continue; }
            
            int r = mountainArr.get(mid + 1);
            if (r > m) { begin = mid + 1; continue; }
            
            if (l < m && m > r) return mid;
        }
        return begin;
    }
    
    int findLeft(MountainArray &mountainArr, int target, int begin, int end) {
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            int m = mountainArr.get(mid);
            if (target == m) return mid;
            else if (target < m) end = mid;
            else begin = mid + 1;
        }
        return -1;
    }
    
    int findRight(MountainArray &mountainArr, int target, int begin, int end) {
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            int m = mountainArr.get(mid);
            if (target == m) return mid;
            else if (target > m) end = mid;
            else begin = mid + 1;
        }
        return -1;
    }
};