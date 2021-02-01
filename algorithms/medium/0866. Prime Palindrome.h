// 866. Prime Palindrome

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Prime Palindrome.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Prime Palindrome.

class Solution {
    bool isPrime(int num) {
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) 
            if (num % i == 0) return false;
        return true;
    }
    
    string findGEPalindrome(int N) {
        string s(to_string(N));
        int L = s.length();
        if ((s[0] - '0') % 2 == 0) { 
            s.back() = ++s[0];
            for (int i = 1; i < L - 1; ++i) s[i] = '0';
            return s;
        } 

        int i = 0;
        int j = L - 1;
        while (i <= j) s[j--] = s[i++];
        
        if (L & 1) i = j = L >> 1;
        else i = (L - 1) >> 1, j = L >> 1;

        while (s[0] != '0' && stoi(s) < N) {
            if (s[i] == '9') {
                s[j] = s[i] = '0';
                int carry = 1;
                int l = i - 1;
                int r = j + 1;
                while (carry && l >= 0) {
                    if (s[l] == '9') {
                        s[r++] = s[l--] = '0'; 
                    } else {
                        s[r++] = ++s[l--];
                        carry = 0;
                    }
                }
            } else {
                s[j] = ++s[i];
            }
        }
        if (s[0] == '0') {
            s = "1" + string(L - 1, '0') + "1";
        } else if ((s[0] - '0') % 2 == 0) { 
            s.back() = ++s[0];
            for (int i = 1; i < L - 1; ++i) s[i] = '0';
        }
        
        // cout << s << endl;
        return s;
    }
    
    int findGEPrimePalindrome(int N) {
        string s(findGEPalindrome(N));
        int L = s.length();
        int i;
        int j;
        if (L & 1) i = j = L >> 1;
        else i = (L - 1) >> 1, j = L >> 1;
        int num = stoi(s);

        while (!isPrime(num)) {
            if (s[i] == '9') {
                s[j] = s[i] = '0';
                int carry = 1;
                int l = i - 1;
                int r = j + 1;
                while (carry && l >= 0) {
                    if (s[l] == '9') {
                        s[r++] = s[l--] = '0'; 
                    } else {
                        s[r++] = ++s[l--];
                        carry = 0;
                    }
                }
            } else {
                s[j] = ++s[i];
            }

            if (s[0] == '0') {
                s = "1" + string(L - 1, '0') + "1";
                ++L;
                if (L & 1) i = j = L >> 1;
                else i = (L - 1) >> 1, j = L >> 1;
            } else if ((s[0] - '0') % 2 == 0) { 
                s.back() = ++s[0];
                for (int k = 1; k < L - 1; ++k) s[k] = '0';
                if (L & 1) i = j = L >> 1;
                else i = (L - 1) >> 1, j = L >> 1;
            }
            // cout << s << endl;
            num = stoi(s);
        }

        return num;
    }
    
public:
    int primePalindrome(int N) {
        static vector<int> prime_palindromes{2, 3, 5, 7, 11, 101};
        if (N <= 101) return *lower_bound(begin(prime_palindromes), end(prime_palindromes), N);
        return findGEPrimePalindrome(N);
    }
};