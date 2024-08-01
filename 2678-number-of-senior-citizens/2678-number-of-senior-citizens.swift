class Solution {
    func countSeniors(_ details: [String]) -> Int {
        var ans: Int = 0
        for info in details {
            let startIndex = info.index(info.startIndex, offsetBy: 11)
            let endIndex = info.index(info.startIndex, offsetBy: 12)
            let ageStr = String(info[startIndex...endIndex])
            if let Age = Int(ageStr), Age > 60 {
                ans += 1
            }
        }
        return ans
    }
}
