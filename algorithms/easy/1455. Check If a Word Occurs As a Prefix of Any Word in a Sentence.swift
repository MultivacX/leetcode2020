// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

// Runtime: 4 ms, faster than 71.43% of Swift online submissions for Check If a Word Occurs As a Prefix of Any Word in a Sentence.
// Memory Usage: 15.3 MB, less than 28.57% of Swift online submissions for Check If a Word Occurs As a Prefix of Any Word in a Sentence.

class Solution {
    func isPrefixOfWord(_ sentence: String, _ searchWord: String) -> Int {
        let words = sentence.components(separatedBy: " ")
        var i = 1
        for w in words {
            if w.hasPrefix(searchWord) {
                return i
            }
            i += 1
        }
        return -1
    }
}