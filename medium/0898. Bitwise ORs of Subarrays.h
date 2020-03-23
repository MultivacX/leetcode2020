// 898. Bitwise ORs of Subarrays

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