// 1258. Synonymous Sentences
// https://leetcode.com/problems/synonymous-sentences/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Synonymous Sentences.
// Memory Usage: 9.3 MB, less than 53.85% of C++ online submissions for Synonymous Sentences.
    
class Solution {
    unordered_map<string, string> uf;
    unordered_map<string, set<string>> s;
    vector<string> arr;
    vector<string> ans;
    
    vector<string> split(const string& s, char delimiter) {
		vector<string> tokens;
   		string token;
   		istringstream tokenStream(s);
   		while (getline(tokenStream, token, delimiter)) {
      		tokens.push_back(token);
   		}
   		return tokens;
	}
    
    void generate(int i, vector<string>& strs) {
        if (i >= arr.size()) {
            string str;
            for (int j = 0; j < strs.size(); ++j) {
                str += strs[j];
                if (j + 1 < strs.size())
                    str += ' ';
            }
            ans.push_back(str);
            return;
        }
        
        if (uf.count(arr[i])) {
            for (auto& word : s[uf[arr[i]]]) {
                strs.push_back(word);
                generate(i + 1, strs);
                strs.pop_back();    
            }
        } else {
            strs.push_back(arr[i]);
            generate(i + 1, strs);
            strs.pop_back();
        }
    }
    
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for (auto& v : synonyms) {
            if (uf.count(v[0]) == 0) uf[v[0]] = v[0];
            if (uf.count(v[1]) == 0) uf[v[1]] = v[1];
            if (uf[v[0]] == uf[v[1]]) continue;
            auto p0 = uf[v[0]];
            for (auto& it : uf) 
                if (it.second == p0) 
                    it.second = uf[v[1]];
        }
        for (auto& it : uf) s[it.second].insert(it.first);
        arr = split(text, ' ');
        vector<string> strs;
        generate(0, strs);
        
        // for (auto& it : uf) cout << it.second << " == " << it.first << endl; cout << endl;
        // for (auto& it : s) { cout << it.first << ": ";
        //     for (auto& str : it.second) cout << str << " "; cout << endl;
        // } cout << endl;
        // for (auto str : arr) cout << str << " "; cout << endl;
        
        return ans;
    }
};