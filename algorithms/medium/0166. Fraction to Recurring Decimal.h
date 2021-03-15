// 166. Fraction to Recurring Decimal

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fraction to Recurring Decimal.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Fraction to Recurring Decimal.

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string integer_part;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            integer_part += "-";
        
        int64_t dividend = abs((int64_t)numerator);
        int64_t divisor = abs((int64_t)denominator);
        if (dividend < divisor) integer_part += "0";
        
        while (dividend >= divisor) {
            integer_part += to_string(dividend / divisor);
            dividend %= divisor;
            // cout << "integer part: " << integer_part << endl;
        }
        
        if (dividend == 0) return integer_part;
        
        string decimal_part;
        // {dividend, quotient}
        vector<pair<int, int>> dq;
        unordered_set<int> dividends;
        while (true) {
            dividend *= 10;
            int quotient = dividend / divisor;
            int remainder = dividend % divisor;
            
            // printf("%d / %d = %d * %d + %d\n", dividend, divisor, divisor, quotient, remainder);
            
            if (remainder == 0) {
                for (auto& p : dq) 
                    decimal_part += to_string(p.second);
                decimal_part += to_string(quotient);
                break;
            } else if (dividends.count(dividend)) {
                for (auto& p : dq) {
                    if (p.first == dividend)
                        decimal_part += "(";
                    decimal_part += to_string(p.second);
                }
                decimal_part += ")";
                break;
            }
            
            dq.push_back({dividend, quotient});
            dividends.insert(dividend);
            dividend = remainder;
        }
        return integer_part + "." + decimal_part;
    }
};


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int64_t num = numerator, den = denominator;
        if (num % den == 0) return to_string(num / den);
        
        bool positive = (num > 0 && den > 0) || (num < 0 && den < 0);
        string ans;
        if (!positive) ans += '-';
        
        if (num < 0) num = -num;
        if (den < 0) den = -den;
        int k = 0;
        if (num < den) {
            while (num < den) num *= 10, ++k;
            if (k >= 1) ans += "0.";
            if (k > 1) ans += string(k - 1, '0');
        }
        
        if (num % den == 0) {
            ans += to_string(num / den);
        } else {
            if (k == 0) {
                int64_t p = num / den;
                int64_t q = num % den;
                ans += to_string(p);
                ans += '.';
                num = q * 10;
            }
            
            unordered_map<int64_t, int> m;
            vector<int64_t> v;
            while (true) {
                int64_t p = num / den;
                int64_t q = num % den;
                
                m.insert({num, v.size()});
                v.push_back(p);
                
                if (q == 0) {
                    for (int i : v)
                        ans += to_string(i);
                    break;
                }
                
                num = q * 10;
                
                if (m.count(num)) {
                    for (int i = 0; i < m[num]; ++i)
                        ans += to_string(v[i]);
                    
                    ans += '(';
                    for (int i = m[num]; i < v.size(); ++i)
                        ans += to_string(v[i]);
                    ans += ')';
                    
                    break;
                }
            }
        }
        return ans;
    }
};