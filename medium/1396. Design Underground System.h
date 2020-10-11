// 1396. Design Underground System
// https://leetcode.com/problems/design-underground-system/

// Runtime: 192 ms, faster than 99.52% of C++ online submissions for Design Underground System.
// Memory Usage: 57.8 MB, less than 5.67% of C++ online submissions for Design Underground System.

class UndergroundSystem {
    // id, {checkIn_stationName, checkIn_t}
    unordered_map<int, pair<string, int>> traveling;
    // sn_a, {sn_b, {total_t, traveling_cnt}}
    unordered_map<string, unordered_map<string, pair<int, int>>> times;
        
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        traveling.emplace(id, pair<string, int>{stationName, t});
    }
    
    void checkOut(int id, string stationName, int t) {
        string checkInStationName = traveling[id].first;
        // int checkInTime = traveling[id].second;
        times[checkInStationName][stationName].first += t - traveling[id].second;
        times[checkInStationName][stationName].second += 1;
        traveling.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return times[startStation][endStation].first / (double)times[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */