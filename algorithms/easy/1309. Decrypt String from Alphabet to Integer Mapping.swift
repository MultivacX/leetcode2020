// 1309. Decrypt String from Alphabet to Integer Mapping
// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

// Runtime: 84 ms, faster than 12.00% of Swift online submissions for Decrypt String from Alphabet to Integer Mapping.
// Memory Usage: 14.4 MB, less than 60.00% of Swift online submissions for Decrypt String from Alphabet to Integer Mapping.

class Solution {
    func freqAlphabets(_ s: String) -> String {
        let m = " abcdefghijklmnopqrstuvwxyz"
        let n = s.indices.count
        var t = ""
        var i = 0
        while i < n {
            var c = s[s.index(s.startIndex, offsetBy: i)]
            if i + 2 < n && s[s.index(s.startIndex, offsetBy: i + 2)] == "#" {
                let val = Int(String(c))! * 10 + Int(String(s[s.index(s.startIndex, offsetBy: i + 1)]))!
                t.append(m[m.index(m.startIndex, offsetBy: val)])
                i += 3
            } else {
                let val = Int(String(c))!
                t.append(m[m.index(m.startIndex, offsetBy: val)])
                i += 1
            }
        }
        return t
    }
}