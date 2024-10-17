class Solution {
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
    var i = 0
    for num in nums {
        if num != val {
            nums[i] = num
            i += 1
        }
    }
    return i
    }
}