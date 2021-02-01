// 1619. Mean of Array After Removing Some Elements
// https://leetcode.com/problems/mean-of-array-after-removing-some-elements/

// Runtime: 72 ms, faster than 89.47% of Swift online submissions for Mean of Array After Removing Some Elements.
// Memory Usage: 15 MB, less than 15.79% of Swift online submissions for Mean of Array After Removing Some Elements.

class Solution {
    func trimMean(_ arr: [Int]) -> Double {
        let cnt = arr.count
        let b = arr.sorted()
        var sum = 0
        for i in cnt * 5 / 100..<cnt * 95 / 100 {
            sum += b[i]
        }
        return (Double)(sum) / (Double)(cnt * 90 / 100)
    }
}