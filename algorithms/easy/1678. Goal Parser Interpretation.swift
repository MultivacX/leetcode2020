// 1678. Goal Parser Interpretation
// https://leetcode.com/problems/goal-parser-interpretation/

// Runtime: 8 ms, faster than 39.89% of Swift online submissions for Goal Parser Interpretation.
// Memory Usage: 14.5 MB, less than 47.75% of Swift online submissions for Goal Parser Interpretation.

class Solution {
    func interpret(_ command: String) -> String {
        let arr = Array(command)
        var s = ""
        var i = 0
        while i < arr.count {
            if arr[i] == "(" && arr[i + 1] == ")" {
                s.append("o")
                i += 1
            } else if arr[i] == "G" || arr[i] == "a" || arr[i] == "l" {
                s.append(arr[i])
            }
            i += 1
        }
        return s
    }
}