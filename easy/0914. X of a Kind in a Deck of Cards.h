// 914. X of a Kind in a Deck of Cards

// Runtime: 48 ms, faster than 6.11% of C++ online submissions for X of a Kind in a Deck of Cards.
// Memory Usage: 17.9 MB, less than 8.33% of C++ online submissions for X of a Kind in a Deck of Cards.

// Time Complexity: O(N*gcd).
// Space Complexity: O(N).

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        const int N = deck.size();
        if (N <= 1) return false;
        
        unordered_map<int, int> m;
        for (int i : deck) ++m[i];
        if (m.size() == 1) return true;
        
        // gcd(m[i]) >= 2
        
        auto i = m.begin();
        int X = i->second;
        while (++i != m.end()) {
            // printf("%d:%d\n", i->first, i->second);
            X = gcd(X, i->second);
            if (X == 1) return false;
        }
        return true;
    }
};