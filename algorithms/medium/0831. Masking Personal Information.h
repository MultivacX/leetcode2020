// 831. Masking Personal Information

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Masking Personal Information.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Masking Personal Information.

class Solution {
public:
    string maskPII(string S) {
        auto at_idx = S.find('@');
        if (at_idx != string::npos) {
            string email;
            email += tolower(S[0]);
            email += "*****";
            email += tolower(S[at_idx - 1]);
            email += '@';
            for (int i = at_idx + 1; i < S.length(); ++i)
                email += tolower(S[i]);
            return email;
        } else {
            string phone;
            for (int i = 0; i < S.length(); ++i)
                if (isdigit(S[i])) phone += S[i];
            string ans;
            if (phone.length() == 10) return string("***-***-" + phone.substr(phone.length() - 4));
            return string("+" + string(phone.length() - 10, '*') + "-***-***-" + phone.substr(phone.length() - 4));
        }
    }
};