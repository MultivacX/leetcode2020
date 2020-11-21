// 1333. Filter Restaurants by Vegan-Friendly, Price and Distance
// https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/

// Runtime: 144 ms, faster than 98.40% of C++ online submissions for Filter Restaurants by Vegan-Friendly, Price and Distance.
// Memory Usage: 28.1 MB, less than 88.53% of C++ online submissions for Filter Restaurants by Vegan-Friendly, Price and Distance.
    
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> index;
        for (int i = 0; i < restaurants.size(); ++i) {
            if (veganFriendly > restaurants[i][2]) continue;
            if (maxPrice < restaurants[i][3]) continue;
            if (maxDistance < restaurants[i][4]) continue;
            index.push_back(i);
        }
        sort(begin(index), end(index), [&](int i, int j){
           return restaurants[i][1] > restaurants[j][1] ||
                  (restaurants[i][1] == restaurants[j][1] && restaurants[i][0] > restaurants[j][0]);
        });
        for (auto& i : index) i = restaurants[i][0];
        return index;
    }
};