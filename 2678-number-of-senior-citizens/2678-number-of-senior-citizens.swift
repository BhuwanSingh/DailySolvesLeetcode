class Solution {
    func countSeniors(_ details: [String]) -> Int {
        details.filter { Int($0.dropFirst(11).prefix(2))! > 60 }.count
    }
}
