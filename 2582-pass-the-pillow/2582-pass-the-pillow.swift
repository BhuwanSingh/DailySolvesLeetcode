class Solution {
    func passThePillow(_ n: Int, _ time: Int) -> Int {
        return n - abs(n - 1 - time % (n * 2 - 2))
    }
}