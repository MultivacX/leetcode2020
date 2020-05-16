// 135. Candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        vector<int> candies(N, 1);
        int ans = 0;
        int max_idx = 0;
        int pre_candies = 1;
        for (int i = 0; i < N; ++i) {
            int cnt = candies[i];
            if (i - 1 >= 0 && ratings[i - 1] < ratings[i] && candies[i - 1] >= candies[i])
                cnt = candies[i - 1] + 1;
            if (i + 1 < N && ratings[i + 1] < ratings[i] && candies[i + 1] >= candies[i])
                cnt = max(cnt, candies[i + 1] + 1);
            candies[i] = cnt;
            
            int j = i;
            if (j - 1 >= 0 && ratings[j - 1] > ratings[j] && candies[j - 1] <= candies[j]) {
                candies[j - 1] = candies[j] + 1;
                if (j - 1 - max_idx > 0) ans += j - 1 - max_idx;
            }
            
            /*int j = i;
            while (j - 1 >= 0 && ratings[j - 1] > ratings[j] && candies[j - 1] <= candies[j]) {
                candies[j - 1] = candies[j] + 1;
                --j;
            }*/
            j = i;
            while (j + 1 < N && ratings[j + 1] > ratings[j] && candies[j + 1] <= candies[j]) {
                candies[j + 1] = candies[j] + 1;
                ++j;
            }
            
            if (i - 1 >= 0 && ratings[i - 1] <= ratings[i]) max_idx = i;
            pre_candies = candies[i];
        }
        // for (int i : ratings) cout << i << " "; cout << endl;
        // for (int i : candies) cout << i << " "; cout << endl;
        return accumulate(begin(candies), end(candies), ans);
    }
};

// Time Limit Exceeded
// 47 / 48 test cases passed.
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        vector<int> candies(N, 1);
        for (int i = 0; i < N; ++i) {
            int cnt = candies[i];
            if (i - 1 >= 0 && ratings[i - 1] < ratings[i] && candies[i - 1] >= candies[i])
                cnt = candies[i - 1] + 1;
            if (i + 1 < N && ratings[i + 1] < ratings[i] && candies[i + 1] >= candies[i])
                cnt = max(cnt, candies[i + 1] + 1);
            candies[i] = cnt;
            
            int j = i;
            while (j - 1 >= 0 && ratings[j - 1] > ratings[j] && candies[j - 1] <= candies[j]) {
                candies[j - 1] = candies[j] + 1;
                --j;
            }
            
            j = i;
            while (j + 1 < N && ratings[j + 1] > ratings[j] && candies[j + 1] <= candies[j]) {
                candies[j + 1] = candies[j] + 1;
                ++j;
            }
        }
        // for (int i : ratings) cout << i << " "; cout << endl;
        // for (int i : candies) cout << i << " "; cout << endl;
        return accumulate(begin(candies), end(candies), 0);
    }
};

// [1,2,3,1,0]
/*class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        int candies = N;
        // candies[i-1]
        int pre_candies = 1;
        // candies[max_idx, ..., i-1] is strictly decreasing array
        int max_idx = 0;
        for (int i = 1; i < N; ++i) {
            if (ratings[i - 1] < ratings[i]) {
                // candies[i-1] is pre_candies
                // candies[i] is 1
                // so child i needs pre_candies candies
                // then candies[i] = 1 + pre_candies
                candies += pre_candies;
                pre_candies += 1;
                max_idx = i;
            } else if (ratings[i - 1] == ratings[i]) {
                pre_candies = 1;
                max_idx = i;
            } else if (pre_candies <= 1) {
                // candies[max_idx, ..., i-1] + one candy
                candies += i - max_idx;
            } else {
                // ratings[i-2] < ratings[i-1] > ratings[i]
                // candies[i-2]:1, candies[i-1]:2, candies[i]:1
                pre_candies = 1;
            }
        }
        return candies;
    }
};*/