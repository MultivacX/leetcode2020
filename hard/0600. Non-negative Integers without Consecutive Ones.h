// 600. Non-negative Integers without Consecutive Ones

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