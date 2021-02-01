// 341. Flatten Nested List Iterator

// Runtime: 28 ms, faster than 13.03% of C++ online submissions for Flatten Nested List Iterator.
// Memory Usage: 12.2 MB, less than 100.00% of C++ online submissions for Flatten Nested List Iterator.

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    int next() {
        return elements[idx++];
    }

    bool hasNext() {
        return idx < elements.size();
    }
    
    void flatten(const vector<NestedInteger> &nestedList) {
        for (const auto& ni : nestedList) {
            if (ni.isInteger()) elements.push_back(ni.getInteger());
            else flatten(ni.getList());
        }
    }
    
    vector<int> elements;
    int idx{0};
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */