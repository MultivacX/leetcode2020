// 983. Minimum Cost For Tickets

// Time Limit Exceeded
/*class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return min(
            get_costs(days, costs, 1, days[0], days[0], costs[0]), min(
            get_costs(days, costs, 1, days[0], days[0] + 6, costs[1]), 
            get_costs(days, costs, 1, days[0], days[0] + 29, costs[2])
            ));
    }
    
    int get_costs(const vector<int>& days, const vector<int>& costs, int day_idx, int pass_start_day, int pass_end_day, int cost) {
        if (days.size() <= day_idx) 
            return cost;
        
        if (pass_end_day < days[day_idx]) {
            return min(
                get_costs(days, costs, day_idx + 1, days[day_idx], days[day_idx], cost + costs[0]), min(
                get_costs(days, costs, day_idx + 1, days[day_idx], days[day_idx] + 6, cost + costs[1]), 
                get_costs(days, costs, day_idx + 1, days[day_idx], days[day_idx] + 29, cost + costs[2])
            ));
        } else {
            return get_costs(days, costs, day_idx + 1, pass_start_day, pass_end_day, cost);
        }
    }
};*/