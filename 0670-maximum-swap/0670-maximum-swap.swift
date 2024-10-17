class Solution {
    func maximumSwap(_ num: Int) -> Int {
        var digits = Array(String(num)).map{ Int(String($0))!}
        var lastIndex = Array(repeating: 0, count: 10)

        for i in 0..<digits.count {
            lastIndex[digits[i]] = i
        }

        for i in 0..<digits.count {
            for d in stride(from: 9, to: digits[i], by: -1){
                if lastIndex[d] > i {
                    digits.swapAt(i , lastIndex[d])
                    let result = digits.map{String($0)}.joined()
                    return Int(result)!
                }
            }
        }
        return num
    }
}