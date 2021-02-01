// 1130. Minimum Cost Tree From Leaf Values

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Cost Tree From Leaf Values.
// Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Minimum Cost Tree From Leaf Values.

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        const int n = arr.size();
        if (n == 2) return arr[0] * arr[1];
        
        auto it = min_element(arr.begin(), arr.end());
        
        int p = (*it);
        if (it == arr.begin()) p *= *(it + 1);
        else if (it == arr.end() - 1) p *= *(it - 1);
        else p *= min(*(it - 1), *(it + 1));
        
        arr.erase(it);
        return p + mctFromLeafValues(arr);
    }
};