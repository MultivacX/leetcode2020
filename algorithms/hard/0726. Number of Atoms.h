// 726. Number of Atoms

// Runtime: 4 ms, faster than 73.68% of C++ online submissions for Number of Atoms.
// Memory Usage: 9.3 MB, less than 66.67% of C++ online submissions for Number of Atoms.

class Solution {
public:
    string countOfAtoms(string formula) {
        vector<pair<string, int>> v;
        int n = formula.length();
        int i = 0;
        while (i < n) {
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                // get atom name
                string name(1, formula[i++]);
                while (i < n && formula[i] >= 'a' && formula[i] <= 'z') {
                    name.append(1, formula[i++]);
                }
                v.push_back({name, 1});
            } else if (formula[i] >= '0' && formula[i] <= '9') {
                // get count
                int count = formula[i++] - '0';
                while (i < n && formula[i] >= '0' && formula[i] <= '9') {
                    count = count * 10 + formula[i++] - '0';
                }
                if (v.back().first == ")") {
                    v.back().first = "#";
                    for (int j = v.size() - 2; j >= 0; --j) {
                        if (v[j].first == "(") {
                            v[j].first = "#";
                            break;
                        }
                        v[j].second *= count;
                    }
                } else {
                    v.back().second *= count;
                }
            } else if (formula[i] == '(') {
                v.push_back({"(", 1});
                ++i;
            } else if (formula[i] == ')') {
                v.push_back({")", 1});
                ++i;
                // "K4((ON)(SO3)2)2"
                //     ^  ^
                if (i < n && formula[i] < '0' || formula[i] > '9') {
                    v.back().first = "#";
                    for (int j = v.size() - 2; j >= 0; --j) {
                        if (v[j].first == "(") {
                            v[j].first = "#";
                            break;
                        }
                    }
                }
            }
        }
        map<string, int> m;
        for (const auto& p : v) m[p.first] += p.second;
        m.erase("#");
        m.erase("(");
        m.erase(")");
        string ans;
        for (auto it : m) {
            if (it.second > 1) ans += it.first + to_string(it.second);
            else ans += it.first;
        }
        return ans;
    }
};