// 418. Sentence Screen Fitting
// https://leetcode.com/problems/sentence-screen-fitting/

// WA ["x"] 20 811
class Solution {
    struct Data {
        Data() {}
        Data(int er, int ec, int t) 
        : end_row(er), end_col(ec), times(t) {}

        int end_row;
        int end_col;
        int times;
    };
    
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int L = 0;
        for (auto& word : sentence)
            if (word.length() > cols)
                return false;
            else L += word.length() + 1;
        L -= 1;
        
        const int N = sentence.size();
        
        vector<Data> data;
        for (int col = 0; col < cols; ++col) {
            int r = 0;
            int c = col;
            
            if (c + L <= cols) {
                int k = (cols - c - L) / (L + 1);
                c += L + (L + 1) * k;
                data.push_back({r, c, 1 + k});
                continue;
            }
            
            for (int i = 0; i < N; ++i) {
                int l = sentence[i].length() + (i + 1 < N ? 1 : 0);
                if (c + l >= cols) {
                    ++r;
                    c = 0;
                }
                c += l;
            }
            data.push_back({r, c, 1});
        }
        
        int times = 0;
        int r = 0, c = 0;
        while (r < rows) {
            auto& d = data[c];
            r += d.end_row;
            c += d.end_col + 1;
            if (r >= rows)
                break;
            if (c >= cols) {
                ++r;
                c %= cols;
            }
            times += d.times;
        }
        return times;
    }
};