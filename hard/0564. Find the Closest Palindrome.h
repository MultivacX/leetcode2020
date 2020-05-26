// 564. Find the Closest Palindrome

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Closest Palindrome.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Find the Closest Palindrome.

class Solution {
    // a >= b
    // a[0] & b[0] are the lowest digit
    string minus(const string& a, const string& b) {
        const int M = a.length();
        const int N = b.length();
        string ans;
        int carry = 0;
        for (int i = 0; i < N; ++i) {
            int na = a[i] - '0';
            int nb = b[i] - '0';
            if (na - nb - carry >= 0) {
                ans += '0' + na - nb - carry;
                carry = 0;
            } else {
                ans += '0' + 10 + na - nb - carry;
                carry = 1;
            }
        }
        for (int i = N; i < M; ++i) {
            int na = a[i] - '0';
            if (na - carry >= 0) {
                ans += '0' + na - carry;
                carry = 0;
            } else {
                ans += '0' + 10 + na - carry;
                carry = 1;
            }
        }
        while (!ans.empty() && ans.back() == '0') ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
    
    // a[0] & b[0] are the lowest digit
    string add(const string& a, const string& b) {
        const int M = a.length();
        const int N = b.length();
        string ans;
        int carry = 0;
        for (int i = 0; i < N; ++i) {
            int na = a[i] - '0';
            int nb = b[i] - '0';
            int val = a[i] - '0' + b[i] - '0' + carry;
            ans += '0' + val % 10;
            carry = val / 10;
        }
        for (int i = N; i < M; ++i) {
            int val = a[i] - '0' + carry;
            ans += '0' + val % 10;
            carry = val / 10;
        }
        if (carry) ans += '1';
        return ans;
    }

    // a[0] & b[0] are the lowest digit
    // a <  b :  1
    // a == b :  0
    // a >  b : -1
    int equal(const string& a, const string& b) {
        const int M = a.length();
        const int N = b.length();
        if (M < N) return 1;
        if (M > N) return -1;

        for (int i = M - 1; i >= 0; --i) {
            if (a[i] < b[i]) return 1;
            if (a[i] > b[i]) return -1;
        }
        return 0;
    }

    void print(string desc, const string& s) {
        cout << desc << ": ";
        for (int i = s.length() - 1; i >= 0; --i) cout << s[i];
        cout << endl;
    }
    
public:
    string nearestPalindromic(string n) {
        const int N = n.length();
        if (N == 1) {
            n[0] -= 1;
            return n;
        }
        
        string p(n);
        for (int i = 0; i < N / 2; ++i)
            p[N - 1 - i] = p[i];
        
        string half(p.substr(N / 2));
        string half_minus_1 = minus(half, "1");
        string half_add_1 = add(half, "1");
        
        string less(half.length() == half_minus_1.length() ? N : N - 1, '9');
        for (int i = 0, j = less.length() - 1, k = half_minus_1.length() - 1; k >= 0; ++i, --j, --k)
            less[i] = less[j] = half_minus_1[k];
        if (less.back() == '0') less = "9";

        string greater(half.length() == half_add_1.length() ? N : N + 1, '0');
        for (int i = 0, j = greater.length() - 1, k = half_add_1.length() - 1; k >= 0; ++i, --j, --k)
            greater[i] = greater[j] = half_add_1[k];

        reverse(begin(n), end(n));
        
        string diff_l = minus(n, less);
        string diff_g = minus(greater, n);
        int l_g = equal(diff_l, diff_g);
        // |n - less| <= |n - greater|
        string* ans = l_g != -1 ? &less : &greater;

        // print("n", n);
        // print("p", p);
        // print("less", less);
        // print("greater", greater);
        // print("n - less", diff_l);
        // print("greater - n", diff_g);

        int p_n = equal(p, n);
        if (p_n != 0) {
            string diff = p_n == 1 ? minus(n, p) : minus(p, n);
            // print("p - n", diff);
            if (l_g != -1) {
                // |n - less| <= |n - greater|
                // |n - p| <= |n - less|
                if (equal(diff, diff_l) == 1) ans = &p;
            } else {
                // |n - greater| < |n - less|
                // |n - p| <= |n - greater|
                if (equal(diff, diff_g) != -1) ans = &p;
            }
        }
        // cout << endl;
        
        return *ans;
    }
};