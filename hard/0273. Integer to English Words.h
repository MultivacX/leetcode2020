// 273. Integer to English Words

// Runtime: 4 ms, faster than 82.09% of C++ online submissions for Integer to English Words.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Integer to English Words.

class Solution {
public:
    string numberToWords(int num) {
        static const unordered_map<int, string> m{
            {0, "Zero"}, {1, "One",}, {2, "Two"}, {3, "Three"}, {4, "Four"}, 
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, 
            {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
            {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
        };
        
        if (m.count(num)) return m.at(num);
        
        string s(to_string(num));
        vector<string> v;
        const int N = s.length();
        for (int i = N - 1; i >= 0; i -= 3) {
            int x = i >= 2 ? s[i - 2] - '0' : 0;
            string cur(x > 0 ? m.at(x) + " Hundred" : "");
            
            int y = i >= 1 ? s[i - 1] - '0' : 0;
            int z = s[i] - '0';
            
            // cout << x << y << z << endl;
            
            if (y > 0) {
                if (!cur.empty()) cur += " ";
                if (m.count(y * 10 + z)) cur += m.at(y * 10 + z);
                else if (z > 0) cur += m.at(y * 10) + " " + m.at(z);
            } else if (z > 0) {
                if (!cur.empty()) cur += " ";
                cur += m.at(z);
            }
            
            if (cur.empty()) continue;
            v.emplace_back(cur);
            
            // 2 147 483 647
            if (N - 1 - i == 3) v.back() += " Thousand";
            else if (N - 1 - i == 6) v.back() += " Million";
            else if (N - 1 - i == 9) v.back() += " Billion";
        }
            
        string ans;
        for (int i = v.size() - 1; i >= 0; --i)
            ans += v[i] + (i > 0 ? " " : "");
        return ans;
    }
};