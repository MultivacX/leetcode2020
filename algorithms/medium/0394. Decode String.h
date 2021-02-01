// 394. Decode String

// Runtime: 4 ms, faster than 55.36% of C++ online submissions for Decode String.
// Memory Usage: 8.9 MB, less than 82.35% of C++ online submissions for Decode String.

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(i, s.length(), s);
    }
    
    string decode(int& i, int size, const string& s) {
        if (i >= size) return "";
        
        bool b = s[i] == '[';
        if (b) ++i;
        
        string ans;
        while (i < size) {
            while (i < size && isalpha(s[i])) ans += s[i++];    
            
            int k = 0;
            while (i < size && isdigit(s[i])) {
                if (k == 0) k = s[i++] - '0';
                else k = k * 10 + s[i++] - '0';
            }
            
            if (k > 0) {
                string x(decode(i, size, s));
                while (k > 0) {
                    ans += x;
                    --k;
                }
            }
            
            if (i < size && s[i] == ']') {
                ++i;
                if (b) break;
            }
        }
        
        return ans;
    }
};