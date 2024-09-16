import Algorithms

class Solution {
    func findMinDifference(_ timePoints: [String]) -> Int {
        timePoints
        .map { $0.components(separatedBy: ":").map(Int.init) }
        .map { ($0[0] ?? 0) * 60 + ($0[1] ?? 0) }
        .flatMap { (minute: Int) -> [Int] in [minute, minute + 1440] }
        .sorted(by: >)
        .adjacentPairs()
        .map(-)
        .min() ?? 0
    }
}