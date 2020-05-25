// 1227. Airplane Seat Assignment Probability

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Airplane Seat Assignment Probability.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Airplane Seat Assignment Probability.

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // 1. passenger-1 takes seat-k
        // 2. [2, k-1] take their own seat
        // for passenger-k whose seat not available
        // he has 2 choices to end this Solution
        // a. takes seat-1 -> probability(passenger-n takes seat-n)
        // b. takes seat-n -> probability(passenger-n can NOT take seat-n)
        return n == 1 ? 1 : 0.5;
    }
};

// ERROR
/*class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double ans = 1.0 / n; // the 1st passenger takes seat 1
        for (int i = n - 1; i > 1; --i) {
            double p = 1.0 / n; // the 1st passenger takes seat i
            // after the (i-1)th passenger takes seat
            int seats = n - (i - 1);
            string s("1/" + to_string(n));
            while (seats > 1) {
                s += " * 1/" + to_string(seats);
                cout << s << " + ";
                p *= 1.0 / seats;
                ans += p;
                --seats;
            }
            cout << endl;
        }
        return ans;
    }
};*/