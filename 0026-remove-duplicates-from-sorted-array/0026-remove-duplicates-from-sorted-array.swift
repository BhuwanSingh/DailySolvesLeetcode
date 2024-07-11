class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        guard !nums.isEmpty else { return 0 }
        
        var pointer = 0
        for i in 1..<nums.count {
            if nums[pointer] != nums[i] {
                pointer += 1
                nums[pointer] = nums[i]
            }
        }
        return pointer + 1
    }
}
