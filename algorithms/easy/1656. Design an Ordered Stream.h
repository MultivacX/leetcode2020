// 1656. Design an Ordered Stream
// https://leetcode.com/problems/design-an-ordered-stream/

// Runtime: 112 ms, faster than 94.75% of C++ online submissions for Design an Ordered Stream.
// Memory Usage: 83.6 MB, less than 92.08% of C++ online submissions for Design an Ordered Stream.

class OrderedStream {
    vector<string> s;
    int ptr;
    
public:
    OrderedStream(int n) : s(n), ptr(0) {
        
    }
    
    vector<string> insert(int id, string value) {
        s[id - 1] = value;
        vector<string> ans;
        while (ptr < s.size() && !s[ptr].empty())
            ans.push_back(s[ptr++]);
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */