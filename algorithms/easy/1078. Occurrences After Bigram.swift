// 1078. Occurrences After Bigram
// https://leetcode.com/problems/occurrences-after-bigram/

// Runtime: 4 ms, faster than 77.78% of Swift online submissions for Occurrences After Bigram.
// Memory Usage: 14.7 MB, less than 55.56% of Swift online submissions for Occurrences After Bigram.

class Solution {
    func findOcurrences(_ text: String, _ first: String, _ second: String) -> [String] {
        var words = text.components(separatedBy: " ")
        var thirds: [String] = []
        for i in 0...words.count - 3 {
            if words[i] == first && words[i + 1] == second {
                thirds.append(words[i + 2])
            }
        }
        return thirds
    }
}