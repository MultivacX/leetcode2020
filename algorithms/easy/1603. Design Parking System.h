// 1603. Design Parking System
// https://leetcode.com/problems/design-parking-system/

// Runtime: 56 ms, faster than 100.00% of C++ online submissions for Design Parking System.
// Memory Usage: 33.2 MB, less than 100.00% of C++ online submissions for Design Parking System.
    
class ParkingSystem {
    vector<int> cnt;
    
public:
    ParkingSystem(int big, int medium, int small) : cnt{big, medium, small} {
        
    }
    
    bool addCar(int carType) {
        if (cnt[carType - 1] > 0) {
            --cnt[carType - 1];
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */