class Solution {
public:
    int minMaxDifference(int num) {
        auto s = to_string(num);
        int a = s[0] - '0';
        int b = a;
        int min_v = 0;
        int max_v = 0;
        for (int i = 0; i < s.length(); ++i) {
            int c = s[i] - '0';
            if (c == a) c = 0;
            min_v = min_v * 10 + c;

            c = s[i] - '0';
            if (9 == b && c != b) { b = c; c = 9; }
            else if (c == b) c = 9;
            max_v = max_v * 10 + c;
        }
        // cout << min_v << ", " << max_v << endl;
        return max_v - min_v;
    }
};