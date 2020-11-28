// 271. Encode and Decode Strings
// https://leetcode.com/problems/encode-and-decode-strings/

// Runtime: 60 ms, faster than 16.51% of C++ online submissions for Encode and Decode Strings.
// Memory Usage: 27.2 MB, less than 38.53% of C++ online submissions for Encode and Decode Strings.

// optim : [length_i][str_i]
    
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for (const auto& s : strs)
            encoded += "<##>" + s;
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        auto i = s.find("<##>", 0);
        auto j = s.find("<##>", i + 4);
        while (i != string::npos) {
            decoded.push_back(s.substr(i + 4, j != string::npos ? (j - i - 4) : s.length() - i - 4));
            i = s.find("<##>", j);
            j = s.find("<##>", i + 4);
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));