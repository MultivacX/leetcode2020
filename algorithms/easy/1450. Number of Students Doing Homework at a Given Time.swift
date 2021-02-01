// 1450. Number of Students Doing Homework at a Given Time
// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/

// Runtime: 8 ms, faster than 100.00% of Swift online submissions for Number of Students Doing Homework at a Given Time.
// Memory Usage: 14.3 MB, less than 16.28% of Swift online submissions for Number of Students Doing Homework at a Given Time.

class Solution {
    func busyStudent(_ startTime: [Int], _ endTime: [Int], _ queryTime: Int) -> Int {
        var arr = Array(repeating: 0, count: 1002)
        for i in 0..<startTime.count {
            arr[startTime[i]] += 1
            arr[endTime[i] + 1] -= 1
        }
        // print(arr)
        
        for i in 1...queryTime {
            arr[i] += arr[i - 1]
        }
        return arr[queryTime] > 0 ? arr[queryTime] : 0
    }
}