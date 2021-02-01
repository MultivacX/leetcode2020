// 911. Online Election

// Runtime: 492 ms, faster than 12.33% of C++ online submissions for Online Election.
// Memory Usage: 73.3 MB, less than 100.00% of C++ online submissions for Online Election.

class TopVotedCandidate {
public:
    using Data = tuple<int, int, int>;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int max_votes = 1;
        int top_person = persons[0];
        
        // {person, votes}
        unordered_map<int, int> person2votes;
        person2votes[top_person] = max_votes;
        
        records.push_back({times[0], times[0] + 1, top_person});
        for (int i = 1; i < persons.size(); ++i) {
            int person = persons[i];
            int time = times[i];

            int votes_now = ++person2votes[person];
            
            max_votes = max(max_votes, votes_now);
            if (max_votes == votes_now) 
                top_person = person;
            
            if (get<2>(records.back()) == top_person) {
                get<1>(records.back()) = time + 1;
            } else {
                get<1>(records.back()) = time;
                records.push_back({time, time + 1, top_person});
            }
        }
        
        // for (auto& r : records) printf("[%d, %d) : %d\n", get<0>(r), get<1>(r), get<2>(r));
    }
    
    int q(int t) {
        get<0>(record) = t;
        auto it = upper_bound(begin(records), end(records), record, [](const Data& l, const Data& r){
            return get<0>(l) < get<0>(r);
        }) - 1;
        return get<2>(*it);
    }
    
    // {start, end, person}
    vector<Data> records;
    Data record{0, 0, 0};
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */