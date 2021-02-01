// 604. Design Compressed String Iterator
// https://leetcode.com/problems/design-compressed-string-iterator/

// Runtime: 16 ms, faster than 46.96% of C++ online submissions for Design Compressed String Iterator.
// Memory Usage: 14 MB, less than 41.74% of C++ online submissions for Design Compressed String Iterator.
    
class StringIterator {
    const string s;
    const int N;
    int idx = 0;
    int cnt = 0;
    int i = 0;
    
    void getCount() {
        if (cnt > 0) return;
        
        cnt = 0;
        i = idx + 1;
        while (i < N && isdigit(s[i]))
            cnt = cnt * 10 + s[i++] - '0';
    }
    
public:
    StringIterator(string compressedString) 
    : s(compressedString)
    , N(compressedString.length())
    , idx(0) {
        getCount();
    }
    
    char next() {
        if (idx >= N) return ' ';
        getCount();
        char ans = s[idx];
        if (--cnt == 0) idx = i;
        return ans;
    }
    
    bool hasNext() {
        return idx < N;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */