// 932. Beautiful Array
// https://leetcode.com/problems/beautiful-array/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Beautiful Array.
// Memory Usage: 8.4 MB, less than 5.82% of C++ online submissions for Beautiful Array.

class Solution {
    unordered_map<int, vector<int>> m;
    
public:
    vector<int> beautifulArray(int N) {
        if (N == 1) return {1};
        if (m.count(N)) return m[N];
        
        vector<int> arr(N);
        int j = 0;
        auto odd = beautifulArray((N + 1) / 2);
        for (int i = 0; i < odd.size(); ++i)
            arr[j++] = odd[i] * 2 - 1;
        auto even = beautifulArray(N - (N + 1) / 2);
        for (int i = 0; i < even.size(); ++i)
            arr[j++] = even[i] * 2;
        m[N] = arr;
        return arr;
    }
};

// Runtime: 16 ms, faster than 23.97% of C++ online submissions for Beautiful Array.
// Memory Usage: 16.2 MB, less than 5.82% of C++ online submissions for Beautiful Array.

class Solution {
public:
    vector<int> beautifulArray(int N) {
        if (N == 1) return {1};
        
        vector<int> arr(N);
        int j = 0;
        auto odd = beautifulArray((N + 1) / 2);
        for (int i = 0; i < odd.size(); ++i)
            arr[j++] = odd[i] * 2 - 1;
        auto even = beautifulArray(N - (N + 1) / 2);
        for (int i = 0; i < even.size(); ++i)
            arr[j++] = even[i] * 2;
        return arr;
    }
};