// 1153. String Transforms Into Another String
// https://leetcode.com/problems/string-transforms-into-another-string/

// Runtime: 8 ms, faster than 31.16% of C++ online submissions for String Transforms Into Another String.
// Memory Usage: 7.7 MB, less than 51.76% of C++ online submissions for String Transforms Into Another String.
    
class Solution {
public:
    bool canConvert(string str1, string str2) {
        unordered_map<char, char> m;
        int b2 = 0;
        for (int i = 0; i < str1.length(); ++i) {
            auto it = m.find(str1[i]);
            if (it == m.end()) m.insert({str1[i], str2[i]});
            // 1 -> more
            else if (it->second != str2[i]) return false;
            b2 |= 1 << (str2[i] - 'a');
        }
        // 26 -> 26
        if (b2 == 0b11111111111111111111111111) {
            // return str1 == str2;
            for (auto it : m)
                if (it.first != it.second)
                    return false;
            return true;
        }
        // for (auto it : m) cout << it.first << "->" << it.second << endl;
        return true;
    }
};