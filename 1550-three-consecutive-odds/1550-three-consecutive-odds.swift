class Solution {
    func threeConsecutiveOdds(_ arr: [Int]) -> Bool {
        if arr.count < 3 {
            return false 
        }
        for i in 1..<arr.count - 1 {
            if  arr[i - 1] % 2 != 0 && arr[i] % 2 != 0 && arr[i + 1] % 2 != 0  {
                return true
            }
        }
        return false
    }
}