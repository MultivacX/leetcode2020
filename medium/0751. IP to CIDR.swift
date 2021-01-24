// 751. IP to CIDR
// https://leetcode.com/problems/ip-to-cidr/

// Runtime: 8 ms, faster than 100.00% of Swift online submissions for IP to CIDR.
// Memory Usage: 14.9 MB, less than 100.00% of Swift online submissions for IP to CIDR.

class Solution {
    func helper(_ n: Int64) -> Int {
        var ans = 0
        var m = n
        while m > 1 {
            m >>= 1
            ans += 1
        }
        return ans
    }
    
    func ipToCIDR(_ ip: String, _ n: Int) -> [String] {
        let a: Array<String> = ip.components(separatedBy: ".")
        var v: Int64 = 0
        for i in 0...3 { v |= Int64(a[i])! << (8 * (3 - i)) }
        var ans: [String] = []
        var m = Int64(n)
        while m > 0 {
            var step = v & -v
            while step > m { step >>= 1 }
            if step == 0 { step = 1 }
            // print(String(v, radix: 2))
            // print(step)
            // print(String(step, radix: 2))
            
            var cidr = String((v >> 24) & 255)
            cidr += "." + String((v >> 16) & 255)
            cidr += "." + String((v >> 8) & 255)
            cidr += "." + String(v & 255)
            cidr += "/" + String(32 - helper(step))
            // print(cidr)
            ans.append(cidr)
            
            v += step
            m -= step
        }
        return ans
    }
}