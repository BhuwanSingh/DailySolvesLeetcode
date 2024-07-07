class Solution {
    func numWaterBottles(_ ta: Int, _ tb: Int) -> Int {
        var numBottles = ta , numExchange = tb
        var ans = numBottles
        while numBottles >= numExchange {
            var remainder = numBottles % numExchange
            numBottles /= numExchange
            ans += numBottles
            numBottles += remainder
        }
        return ans
    }
}