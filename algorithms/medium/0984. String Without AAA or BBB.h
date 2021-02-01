// 984. String Without AAA or BBB

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for String Without AAA or BBB.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for String Without AAA or BBB.

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string aa_("aa");
        char a_ = 'a';
        char b_ = 'b';
        if (A < B) {
            swap(A, B);
            aa_ = "bb";
            swap(a_, b_);
        }
        
        string a;
        while (A > 0) {
            if (A >= 2) A -= 2, a += aa_;
            else A -= 1, a += a_;
            if (B > 0) B -= 1, a += b_;
        }
        // cout << a << endl;
        if (B == 0) return a;
        
        string b;
        int i = (int)a.length() - 1;
        while (i >= 0) {
            b += a[i];
            if (B > 0 && a[i] == a_) --B, b += b_;
            --i;
        }
        return b;
    }
};