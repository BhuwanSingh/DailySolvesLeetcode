/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func nodesBetweenCriticalPoints(_ head: ListNode?) -> [Int] {
        var curr = head
        var prev : ListNode? = nil 
        var num = 0
        var arr = [Int]()
        
        while let currentNode = curr {
            var next = currentNode.next
            if let prevNode = prev , let nextNode = next {
                if (prevNode.val < currentNode.val && nextNode.val < currentNode.val) || 
                    (prevNode.val > currentNode.val && nextNode.val > currentNode.val) {
                        arr.append(num)
                }
            }
            num += 1
            prev = curr
            curr = currentNode.next
        }
        
        if arr.count < 2 {
            return [-1,-1]
        }
        
        var minVal = Int.max
        for i in 1..<arr.count {
            minVal = min(minVal , arr[i] - arr[i - 1])
        }
        
        let maxDistance = arr.last! - arr.first!
        return [minVal, maxDistance]
    }
}