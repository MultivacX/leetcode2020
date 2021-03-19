// 600. Non-negative Integers without Consecutive Ones
// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Non-negative Integers without Consecutive Ones.
// Memory Usage: 6.1 MB, less than 66.33% of C++ online submissions for Non-negative Integers without Consecutive Ones.
    
class Solution {
public:
    int findIntegers(int num) {
        vector<int> f(32);
        f[0] = 1; f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i - 2] + f[i - 1];
        
        int cnt = 0;
        for (int i = 30, prebit = 0; i >= 0; --i) {
            if ((1 << i) & num) {
                cnt += f[i];
                if (prebit) 
                    return cnt;
                prebit = 1;
            } else {
                prebit = 0;
            }
        }
        return cnt + 1/* num self */;
    }
};


// WA
class Solution {
    // num = 1 << i
    int getIntegersLE(int i) {
        // [0,1] [2] [4,5] ... 
        static const vector<int> memo{2, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269};
        // for (int i = 3; i < 31; ++i) {
        //     // memo[0, i-2]
        //     memo.push_back(accumulate(begin(memo), begin(memo) + i - 1, 0));
        //     cout << memo.back() << ", ";
        // }
        
        if (i < 0) return 0;
        if (i == 0) return memo[0];
        return accumulate(begin(memo), begin(memo) + i + 1, 1 - memo[i]); 
    }
    
    pair<bool, int> check(int num, int i) {
        int k = -1;
        while (--i >= 0) {
            int j = i + 1;
            int a = (num & (1 << j)) >> j;
            int b = (num & (1 << i)) >> i;
            if (a + b == 2) return {false, j};
            if (k == -1 && b == 1) k = i; 
        }
        return {true, k};
    }
    
public:
    int findIntegers(int num) {
        int i = 30;
        while (((1 << i) & num) == 0) --i;
        if ((1 << i) == num) return getIntegersLE(i);
        
        int ans = 0;
        auto p = check(num, i);
        if (p.first) {
            
        } else {
            
        }
        return ans;
    }
};

/*class Solution {
public:
    int findIntegers(int num) {
        // // count of integers between [1 << i, (1 << (i + 1)) - 1]
        // // whose binary representations do NOT contain consecutive ones
        // vector<int> count{2, 1};
        // int total_count = count[0];
        // // total count : [0, (1 << (i + 1)) - 1]
        // vector<int> total;
        // for (int i = 2; i <= 30; ++i) {
        //     total.push_back(total_count);
        //     count.push_back(total_count);
        //     total_count += count[i - 1];
        // }
        // total.push_back(total_count);
        // for (int c : count) cout << c << ", ";
        // cout << endl;
        // for (int c : total) cout << c << ", ";
        // cout << endl;
        
        // total count : [0, (1 << (i + 1)) - 1]
        static const vector<int> total{2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309};
        
        int ans = 0;
        
        int x = INT_MAX;
        for (int i = 30; i >= 0; --i) {
            if (num == x) 
                return total[i];
            
            if (num < x) {
                x >>= 1;
                continue;
            }
            
            cout << bitset<32>(1 << i) << ", " << "i" << endl;
            cout << bitset<32>(num) << ", " << "num" << endl;
            cout << bitset<32>(x) << ", " << "x, " << total[i] << endl;
            cout << endl;
            ans += total[i];
            
            bool included = false;
            bool included_1 = false;
            int y = 1 << (i + 1);
            for (int j = i; j >= 0; --j) {
                x >>= 1;
                if ((num & (1 << j)) == 0) continue;
                int z = y | x;
                cout << bitset<32>(z) << ", " << "z, " << j - 1 << endl;
                if (j > 0) {
                    ans += total[j - 1];
                    if (z == num) included = true;
                    if (z >= num - 1) included_1 = true;
                }
                y = y | (1 << j);
            }
            
            if (!included || !included_1) {
                string s1(bitset<32>(num).to_string());
                if (!included && s1.find("11") == string::npos) ++ans;
                string s2(bitset<32>(num - 1).to_string());
                if (!included_1 && s1.length() == s2.length() && s2.find("11") == string::npos) ++ans;
            }
            
            break;
        }
        return ans;
    }
};*/