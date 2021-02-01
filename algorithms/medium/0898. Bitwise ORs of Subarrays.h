// 898. Bitwise ORs of Subarrays

// Runtime: 1956 ms, faster than 5.17% of C++ online submissions for Bitwise ORs of Subarrays.
// Memory Usage: 182.8 MB, less than 100.00% of C++ online submissions for Bitwise ORs of Subarrays.

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> ans, cur, nxt;
        for (const int& a : A) {
            nxt = {a};
            for (const int& c : cur) nxt.insert(a | c);
            cur = nxt;
            for (const int& c : cur) ans.insert(c);
        }
        return ans.size();
    }
};

// Time Limit Exceeded
// 83 / 83 test cases passed, but took too long.
/* class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> ans, cur;
        for (const int& a : A) {
            unordered_set<int> tmp;
            for (const int& x : cur) 
                tmp.emplace(x | a);
            tmp.emplace(a);
            swap(cur, tmp);
            ans.insert(cur.begin(), cur.end());
        }
        return ans.size();
    }
}; */