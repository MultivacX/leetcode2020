// 401. Binary Watch

// Runtime: 4 ms, faster than 62.16% of C++ online submissions for Binary Watch.
// Memory Usage: 8.9 MB, less than 57.14% of C++ online submissions for Binary Watch.

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        // vector<vector<string>> hours(5, vector<string>());
        // for (int i = 0; i <= 11; ++i) {
        //     hours[bitset<32>(i).count()].push_back(to_string(i));
        // }
        // cout << "{";
        // for (int i = 0; i <= 4; ++i) {
        //     cout << "{";
        //     for (auto& s : hours[i]) {
        //         cout << "\"" << s <<  "\", ";
        //     }
        //     cout << "}," << endl;
        // }
        // cout << "};" << endl;
        // vector<vector<string>> minute(7, vector<string>());
        // for (int i = 0; i <= 59; ++i) {
        //     minute[bitset<32>(i).count()].push_back((i >= 10 ? "" : "0") + to_string(i));
        // }
        // cout << "{";
        // for (int i = 0; i <= 6; ++i) {
        //     cout << "{";
        //     for (auto& s : minute[i]) {
        //         cout << "\"" << s <<  "\", ";
        //     }
        //     cout << "}," << endl;
        // }
        // cout << "};" << endl;
        
        static const vector<vector<string>> hours{{"0", },
            {"1", "2", "4", "8", },
            {"3", "5", "6", "9", "10", },
            {"7", "11", },
        };
        static const int H = 3;
        static const vector<vector<string>> minutes
            {{"00", },
            {"01", "02", "04", "08", "16", "32", },
            {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48", },
            {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56", },
            {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58", },
            {"31", "47", "55", "59", },
        };
        static const int M = 5;  
        
        vector<string> ans;
        for (int h = 0; h <= min(H, num); ++h) {
            int m = max(0, num - h);
            if (m > M) continue;
            for (const string& hour : hours[h]) {
                for (const string& minute : minutes[m]) {
                    ans.push_back(hour + ":" + minute);
                }    
            }
        }
        return ans;
    }
};