class Solution {
    func findTheWinner(_ n: Int, _ k: Int) -> Int {
        var friends = Array(1...n), loser = 0
        for i in 1..<n {
            loser = (loser + k - 1) % friends.count
            friends.remove(at: loser)
        }
        return friends.first!
    }
}