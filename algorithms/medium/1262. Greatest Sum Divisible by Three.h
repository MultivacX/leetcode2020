// 1262. Greatest Sum Divisible by Three

// Runtime: 48 ms, faster than 90.75% of C++ online submissions for Greatest Sum Divisible by Three.
// Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for Greatest Sum Divisible by Three.

class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
        /*
        if sum % 3 == 1, sum -= min(A + B, C), when A % 3 == 2, B % 3 == 2, and C % 3 == 1
        if sum % 3 == 2, sum -= min(A + B, C), when A % 3 == 1, B % 3 == 1, and C % 3 == 2
        */
        int sum = 0;
        int left1 = 0;
        int left2 = 0;
        for (int i : nums) {
            sum += i;
            if (i % 3 == 1) {
                if (left1 == 0) {
                    left1 = i;
                } else {
                    left2 = left2 == 0 ? left1 + i : min(left2, left1 + i);
                    left1 = min(left1, i);
                }
            } else if (i % 3 == 2) {
                if (left2 == 0) {
                    left2 = i;
                } else {
                    left1 = left1 == 0 ? left2 + i :  min(left1, left2 + i);
                    left2 = min(left2, i);
                }
            }
        }
        if (sum % 3 == 1) sum -= left1;
        else if (sum % 3 == 2) sum -= left2;
        return sum % 3 == 0 ? sum : 0;
    }

	// ERROR: 36 / 40 test cases passed.
	// [2,19,6,16,5,10,7,4,11,6]
    /*int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> _1;
        vector<int> _2;
        for (int i : nums) {
            int x = i % 3;
            if (x == 0) sum += i;
            else if (x == 1) _1.push_back(i);
            else _2.push_back(i);
        }
        sort(_1.begin(), _1.end());
        sort(_2.begin(), _2.end());
        int i = _1.size() - 1;
        int j = _2.size() - 1;
        while (i >= 0 && j >= 0) {
            int _111 = i >= 2 ? (_1[i] + _1[i - 1] + _1[i - 2]) : 0;
            int _222 = j >= 2 ? (_2[j] + _2[j - 1] + _2[j - 2]) : 0;
            int _12 = _1[i] + _2[j];
            if (_12 >= _111 + _222) {
                sum += _12;
                --i;
                --j;
            } else {
                if (_111 > 0) {
                    sum += _111;
                    i -= 3;
                }
                if (_222 > 0) {
                    sum += _222;
                    j -= 3;
                }
            }
        }
        while (i >= 2) {
            sum += _1[i] + _1[i - 1] + _1[i - 2];
            i -= 3;
        }
        while (j >= 2) {
            sum += _2[j] + _2[j - 1] + _2[j - 2];
            j -= 3;
        }
        return sum;
    }*/
};