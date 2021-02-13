// 5. Longest Palindromic Substring

// Runtime: 36 ms, faster than 84.10% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Longest Palindromic Substring.

// Time Complexity: O(N * N).
// Space Complexity: O(1).

class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.length();
        int L = 0;
        int R = 0;
        for (int i = 0; i < s.length(); ++i) {
            int l = i;
            int r = i;
            while (l >= 0 && r < N && s[l] == s[r]) --l, ++r;
            if (r - l - 2 > R - L) L = l + 1, R = r - 1;
            
            l = i;
            r = i;
            while (l >= 0 && r + 1 < N && s[l] == s[r + 1]) --l, ++r;
            if (r > l && r + 1 - l - 2 > R - L) L = l + 1, R = r;
        }
        // cout << L << ", " << R << endl;
        return s.substr(L, R - L + 1);
    }
};

class Solution {
    string manacher(string s) {
        const int N = s.length();
        if (N <= 1) return s;

        vector<char> arr(2 * N + 1, '\0');
        for (int i = 0; i < N; ++i)
            arr[2 * i + 1] = s[i];
        vector<int> len(2 * N + 1, 0);

        // max-len palindrome
        // \0, arr[1], \0
        int center_max = 1;
        len[center_max] = 1;
        // right-most palindrome
        int center = 1;
        len[center] = 1;
        for (int i = 2; i < 2 * N + 1 - len[center_max]; ++i) {
            // mirror
            // __ j ... center ... i __
            int j = center - (i - center);
            if (j >= 0) len[i] = min(len[j], len[center] - (i - center));

            int l = i - len[i] - 1;
            int r = i + len[i] + 1;
            while (l >= 0 && r <= 2 * N && arr[l] == arr[r]) {
                ++len[i];
                l = i - len[i] - 1;
                r = i + len[i] + 1;
            }

            // update right-most palindrome
            if (i + len[i] > center + len[center])
                center = i;

            // update max-len palindrome
            if (len[i] > len[center_max]) 
                center_max = i;
        }

        string ans;
        for (int i = center_max - len[center_max]; i <= center_max + len[center_max]; ++i)
            if (arr[i] != '\0') ans += arr[i];
        return ans;
    }
    
public:
    string longestPalindrome(string s) {
        return manacher(s);
    }
};