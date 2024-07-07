class Solution {
    func intersect(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var map: [Int:Int] = [:]
        for i in 0..<nums1.count {
            map[nums1[i], default: 0] += 1
        }
        var res = [Int]()
        for i in 0..<nums2.count {
            if let count = map[nums2[i]], count > 0  {
                res.append(nums2[i])
                map[nums2[i]] = count - 1
            }
        }
        return res
    }
}