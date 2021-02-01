// 1165. Single-Row Keyboard
// https://leetcode.com/problems/single-row-keyboard/

// Runtime: 20 ms, faster than 90.91% of Swift online submissions for Single-Row Keyboard.
// Memory Usage: 14.8 MB, less than 40.91% of Swift online submissions for Single-Row Keyboard.

class Solution {
    func calculateTime(_ keyboard: String, _ word: String) -> Int {
        var chars: [Character:Int] = [:]
        var i = 0
        for c in keyboard {
            chars[c] = i
            i += 1
        }
        
        var ans = 0
        i = 0
        for c in word {
            ans += abs(chars[c]! - i)
            i = chars[c]!
        }
        return ans
    }
}