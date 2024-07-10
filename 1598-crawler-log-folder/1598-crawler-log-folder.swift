class Solution {
    func minOperations(_ logs: [String]) -> Int {
        logs.reduce(0) { sum, log in
            let delta = ["../":-1,"./":0][log, default:1] // either up(../), same(./) or down
            return max(sum + delta, 0) // prevent from going higher that top level
		}
    }
}