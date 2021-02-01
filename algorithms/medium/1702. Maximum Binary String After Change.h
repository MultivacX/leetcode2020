// 1702. Maximum Binary String After Change
// https://leetcode.com/problems/maximum-binary-string-after-change/

// Runtime: 192 ms, faster than 65.20% of C++ online submissions for Maximum Binary String After Change.
// Memory Usage: 54.7 MB, less than 12.80% of C++ online submissions for Maximum Binary String After Change.
    
class Solution {
public:
    string maximumBinaryString(string binary) {
        const int N = binary.length();
        int zero = 0;
        for (char b : binary) if (b == '0') ++zero;
        
        int i = 0;
        while (i < N) {
            if (binary[i] == '1') { 
                ++i; 
            } else if (i + 1 < N && binary[i + 1] == '0') {
                // [1...1][00***]
                binary[i++] = '1';
                if (--zero == 0) break;
            } else {
                if (zero <= 1) break;
                // [1...1][0[1***]]
                return binary.substr(0, i) + string(zero - 1, '1') + "0" + string(N - i - zero, '1');
            }
        }
        return binary;
    }
};

// TLE
class Solution {
public:
    string maximumBinaryString(string binary) {
        const int N = binary.length();
        int zero = 0;
        for (char b : binary) if (b == '0') ++zero;
        
        int i = 0;
        while (i < N) {
            if (binary[i] == '1') { 
                ++i; 
            } else if (i + 1 < N && binary[i + 1] == '0') {
                // [1...1][00...]
                binary[i++] = '1';
                if (--zero == 0) break;
            } else {
                if (zero <= 1) break;
                // [1...1][0[1...]]
                for (int j = N - 1; j > i; --j) 
                    if (binary[j - 1] == '1' && binary[j] == '0')
                        swap(binary[j - 1], binary[j]);
            }
        }
        return binary;
    }
};