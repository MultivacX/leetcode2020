// Google | Onsite | Substrings that don't have every character in an alphabet

/*
Suppose you have a string, haystack, and a set of characters which may or may not appear in that string, 
alphabet. (No characters appear in alphabet more than once, because it's a set.) How many non-empty sub-strings 
of haystack do not contain every character in alphabet? Write a function that accepts haystack and alphabet as 
input and returns an answer to this question as an integer.

Example:

Input: haystack = "cab", alphabet = ['a', 'c']
Output: 4
Explanation:
    We can enumerate all 6 non-empty substrings of `cab`:
    "c" - this does not have `a`.
    "a" - this does not have `c`.
    "ca" - this has every entry in `alphabet`.
    "b" - this does not have `a` or `c`.
    "ab" - this does not have `c`.
    "cab" - this has every entry in `alphabet`.
    4 of these substrings don't have every answer, so the function should return 4.
*/

// TODO: misunderstand
int count(string haystack, vector<char> alphabet) {
    const int m = alphabet.size();
    const int n = haystack.length();
    if (m > n) return false;

    int cnt1[26] = {0};
    for (const char& c : alphabet)
        ++cnt1[c - 'a'];
    int cnt2[26] = {0};

    int ans = 0;
    int start = -1;
    for (int i = 0; i < n; ++i) {
        int idx = haystack[i] - 'a';
        if (cnt1[idx] == 0) {
            memset(cnt2, 0, 26 * sizeof(int));
            start = -1;
            continue;
        }

        if (start < 0) start = i;
        ++cnt2[idx];
        while (cnt2[idx] > cnt1[idx] && start < i)
            --cnt2[haystack[start++] - 'a'];

        if (i - start + 1 == m) {
            ++ans;
            --cnt2[haystack[start++] - 'a'];
        }
    }
    return (n + 1) * n / 2 - ans;
}