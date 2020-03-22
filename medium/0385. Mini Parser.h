// 385. Mini Parser

// Runtime: 20 ms, faster than 49.77% of C++ online submissions for Mini Parser.
// Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Mini Parser.

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        return deserialize(s, i);
    }
    
    NestedInteger deserialize(const string& s, int& i) {
        NestedInteger ni;
        
        if (s[i] == '[') {
            ++i;
            if (s[i] == ']') {
                ++i;
            } else {
                while (i < s.length() && s[i] != ']')
                    ni.add(deserialize(s, i));
                if (i < s.length() && s[i] == ']') ++i;
            }
        } else if (isdigit(s[i]) || s[i] == '-') {
            int positive = s[i] != '-' ? 1 : -1;
            if (s[i] == '-') ++i;
            int num = 0;
            while (i < s.length() && s[i] != ']' && s[i] != ',') 
                num = num * 10 + s[i++] - '0';
            ni.setInteger(num * positive);
        }
        
        if (i < s.length() && s[i] == ',') ++i;
         
        return ni;
    }
};