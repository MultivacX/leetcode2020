// 869. Reordered Power of 2

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reordered Power of 2.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Reordered Power of 2.

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        static const unordered_set<string> p2{"1","2","4","8","16","23","46","128","256","125","0124","0248","0469","1289","13468","23678","35566","011237","122446","224588","0145678","0122579","0134449","0368888","11266777","23334455","01466788","112234778","234455668","012356789"};
        // for (int i = 0; i < 31; ++i) {
        //     int v = 1 << i;
        //     if (v <= 1000000000) {
        //         string s(to_string(v));
        //         sort(s.begin(), s.end());
        //         cout << "\"" << s << "\",";
        //     }
        // }
        string s(to_string(N));
        sort(s.begin(), s.end());
        return p2.count(s);
    }
};