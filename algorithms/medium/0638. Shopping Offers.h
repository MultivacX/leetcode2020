// 638. Shopping Offers

// Runtime: 8 ms, faster than 94.26% of C++ online submissions for Shopping Offers.
// Memory Usage: 10.5 MB, less than 66.67% of C++ online submissions for Shopping Offers.

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans = 0;
        for (int i = 0; i < price.size(); ++i) ans += price[i] * needs[i];
        
        for (vector<int>& s : special) {
            bool buy = true;
            for (int i = 0; i < price.size(); ++i) {
                if (needs[i] >= s[i]) continue;
                buy = false;
                break;
            }
            if (!buy) continue; 
            
            for (int i = 0; i < price.size(); ++i) needs[i] -= s[i];
            ans = min(ans, s.back() + shoppingOffers(price, special, needs));
            for (int i = 0; i < price.size(); ++i) needs[i] += s[i];
        }
        
        return ans;
    }
};