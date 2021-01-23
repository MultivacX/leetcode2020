// 1460. Make Two Arrays Equal by Reversing Sub-arrays
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

// Runtime: 72 ms, faster than 54.55% of Swift online submissions for Make Two Arrays Equal by Reversing Sub-arrays.
// Memory Usage: 13.9 MB, less than 97.73% of Swift online submissions for Make Two Arrays Equal by Reversing Sub-arrays.

class Solution {
    func canBeEqual(_ target: [Int], _ arr: [Int]) -> Bool {
        var m: [Int: Int] = [:]
        for i in arr {
            if m[i] == nil {
                m[i] = 1
            } else {
                m.updateValue(m[i]! + 1, forKey: i)
            }
        }
        for i in target {
            // print(m[i])
            if m[i] == nil || m[i] == 0 {
                return false
            }
            m.updateValue(m[i]! - 1, forKey: i)
            if m[i] == 0 {
                m[i] = nil
            }
        }
        return m.isEmpty
    }
}