// 364. Nested List Weight Sum II
// https://leetcode.com/problems/nested-list-weight-sum-ii/

// Runtime: 4 ms, faster than 63.96% of C++ online submissions for Nested List Weight Sum II.
// Memory Usage: 8.1 MB, less than 90.99% of C++ online submissions for Nested List Weight Sum II.
    
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
    vector<pair<int, int>> v;
    int depth = 0;
    
    void dfs(NestedInteger& node, int d) {
        if (d > depth) depth = d;
        if (node.isInteger()) v.emplace_back(node.getInteger(), d);
        else for (auto& x : node.getList()) dfs(x, d + 1);
    }
    
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        for (auto& node : nestedList) dfs(node, 1);
        int sum = 0;
        for (const auto& p : v) sum += p.first * (depth + 1 - p.second);
        return sum;
    }
};