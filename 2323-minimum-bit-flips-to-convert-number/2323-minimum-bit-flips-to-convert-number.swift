class Solution {
    func minBitFlips(_ start: Int, _ goal: Int) -> Int {
        (start ^ goal).nonzeroBitCount
    }
}