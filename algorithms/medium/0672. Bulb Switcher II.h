// 672. Bulb Switcher II
// https://leetcode.com/problems/bulb-switcher-ii/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Bulb Switcher II.
// Memory Usage: 6.2 MB, less than 80.39% of C++ online submissions for Bulb Switcher II.

class Solution {
public:
    int flipLights(int n, int m) {
        // fa : Flip all the lights.
        // fe : Flip lights with even numbers.
        // fo : Flip lights with odd numbers.
        // fk : Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
        
        // fa(fa(S)) = fe(fe(S)) = fo(fo(S)) = fk(fk(S)) = S
        // fe(fo(S)) = fo(fe(S)) = fa(S)
        // fe(fa(S)) = fo(S)
        // fo(fa(S)) = fe(S)
        // fa(fk(S)) = fk(fa(S))
        // fe(fk(S)) = fk(fe(S))
        // fo(fk(S)) = fk(fo(S))

        // 0*F : S
        // 2*F : S = f*(f*(S))
        // 3*F : S = fa(fe(fo(S)))
        // x*F
        // ^^^,                      x*F + 1*F,                       x*F + 2*F
        // S,                        fa(S), fe(S), fo(S), fk(S),      fa(fk(S)), fe(fk(S)), fo(fk(S))
        
        if (m <= 0) return 1; // all lights on
        if (n == 1) return 2; // one light: 1 & 0
        if (n == 2 && m == 1) return 3; // 00, 10, 01
        if (n == 2) return 4; // 11, 00, 10, 01
        if (m == 1) return 4;
        if (m == 2) return 7;
        return 8;
    }
};