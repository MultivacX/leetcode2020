// 1736. Latest Time by Replacing Hidden Digits
// https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/

// Runtime: 4 ms, faster than 100.00% of Swift online submissions for Latest Time by Replacing Hidden Digits.
// Memory Usage: 14 MB, less than 100.00% of Swift online submissions for Latest Time by Replacing Hidden Digits.

class Solution {
    func maximumTime(_ time: String) -> String {
        var arr = Array(time)
        if arr[0] == "?" {
            if arr[1] == "?" {
                arr[0] = "2"
                arr[1] = "3"
            } else if ["0", "1", "2", "3"].contains(arr[1]) {
                arr[0] = "2"
            } else {
                arr[0] = "1"
            }
        } else if arr[1] == "?" {
            if arr[0] != "2" { arr[1] = "9" }
            else { arr[1] = "3" }
        }
        
        if arr[3] == "?" { arr[3] = "5" }
        if arr[4] == "?" { arr[4] = "9" }
        
        return String(arr)
    }
}