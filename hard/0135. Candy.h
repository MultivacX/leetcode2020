// 135. Candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        vector<int> candies(N, 1);
        int ans = N;
        for (int i = 0; i < N; ++i) {
            int cnt = candies[i];
            if (i - 1 >= 0 && ratings[i - 1] < ratings[i] && candies[i - 1] >= candies[i]) {
                cnt = candies[i - 1] + 1;
                ans += cnt - candies[i];
            }
            candies[i] = cnt;
            
            int j = i;
            while (j - 1 >= 0 && ratings[j - 1] > ratings[j] && candies[j - 1] <= candies[j]) {
                candies[j - 1] = candies[j] + 1;
                ++ans;
                --j;
            }
        }
        // for (int i : ratings) cout << i << " "; cout << endl;
        // for (int i : candies) cout << i << " "; cout << endl;
        return ans;
    }
};