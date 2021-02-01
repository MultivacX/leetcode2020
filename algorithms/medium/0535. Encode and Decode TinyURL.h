// 535. Encode and Decode TinyURL

// Runtime: 8 ms, faster than 35.48% of C++ online submissions for Encode and Decode TinyURL.
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Encode and Decode TinyURL.

class Solution {
    unordered_map<string, string> l2s;
    unordered_map<string, string> s2l;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        static const unordered_map<char, int> C2I{{'1', 0}, {'2', 1}, {'3', 2}, {'4', 3}, {'5', 4}, {'6', 5}, {'7', 6}, {'8', 7}, {'9', 8}, {'0', 9}, {'q', 10}, {'w', 11}, {'e', 12}, {'r', 13}, {'t', 14}, {'y', 15}, {'u', 16}, {'i', 17}, {'o', 18}, {'p', 19}, {'a', 20}, {'s', 21}, {'d', 22}, {'f', 23}, {'g', 24}, {'h', 25}, {'j', 26}, {'k', 27}, {'l', 28}, {'z', 29}, {'x', 30}, {'c', 31}, {'v', 32}, {'b', 33}, {'n', 34}, {'m', 35}, {'Q', 36}, {'W', 37}, {'E', 38}, {'R', 39}, {'T', 40}, {'Y', 41}, {'U', 42}, {'I', 43}, {'O', 44}, {'P', 45}, {'A', 46}, {'S', 47}, {'D', 48}, {'F', 49}, {'G', 50}, {'H', 51}, {'J', 52}, {'K', 53}, {'L', 54}, {'Z', 55}, {'X', 56}, {'C', 57}, {'V', 58}, {'B', 59}, {'N', 60}, {'M', 61}};
        static const unordered_map<int, char> I2C{{0, '1'}, {1, '2'}, {2, '3'}, {3, '4'}, {4, '5'}, {5, '6'}, {6, '7'}, {7, '8'}, {8, '9'}, {9, '0'}, {10, 'q'}, {11, 'w'}, {12, 'e'}, {13, 'r'}, {14, 't'}, {15, 'y'}, {16, 'u'}, {17, 'i'}, {18, 'o'}, {19, 'p'}, {20, 'a'}, {21, 's'}, {22, 'd'}, {23, 'f'}, {24, 'g'}, {25, 'h'}, {26, 'j'}, {27, 'k'}, {28, 'l'}, {29, 'z'}, {30, 'x'}, {31, 'c'}, {32, 'v'}, {33, 'b'}, {34, 'n'}, {35, 'm'}, {36, 'Q'}, {37, 'W'}, {38, 'E'}, {39, 'R'}, {40, 'T'}, {41, 'Y'}, {42, 'U'}, {43, 'I'}, {44, 'O'}, {45, 'P'}, {46, 'A'}, {47, 'S'}, {48, 'D'}, {49, 'F'}, {50, 'G'}, {51, 'H'}, {52, 'J'}, {53, 'K'}, {54, 'L'}, {55, 'Z'}, {56, 'X'}, {57, 'C'}, {58, 'V'}, {59, 'B'}, {60, 'N'}, {61, 'M'}};
        static const string T("http://tinyurl.com/");
        
        if (l2s.count(longUrl)) return l2s[longUrl];
        
        vector<int> v(6, 0);
        const int N = longUrl.length();
        for (int i = 0, j = 0; i < 6; ++i) {
            int val = 0;
            for (int k = 0; k < N / 6  && j < N; ++k, ++j) {
                val += longUrl[j] * 7;
            }
            v[i] = val % 62;
        }
        
        string shortUrl(T);
        for (int i = 0; i < 6; ++i) shortUrl += I2C.at(v[i]);
        
        int i = 0;
        int j = v[i];
        while (s2l.count(shortUrl) && i < 6) {
            shortUrl[i + T.length()] = I2C.at(++j);
            if (j == v[i]) ++i;
        }
        
        // cout << longUrl << endl << shortUrl << endl << endl;
        l2s[longUrl] = shortUrl;
        s2l[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (s2l.count(shortUrl)) return s2l[shortUrl];
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));