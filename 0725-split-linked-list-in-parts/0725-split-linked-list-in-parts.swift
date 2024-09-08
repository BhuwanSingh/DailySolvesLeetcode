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
    func splitListToParts(_ head: ListNode?, _ k: Int) -> [ListNode?] {
        var ans = [ListNode?](repeating: nil, count: k)

        // get total size of linked list
        var size = 0
        var current = head
        while current != nil {
            size += 1
            current = current?.next
        }

        // minimum size for the k parts
        let splitSize = size / k

        // Remaining nodes after splitting the k parts evenly
        var numRemainingParts = size % k

        current = head
        var prev: ListNode?

        for i in 0..<k {
            // create the i-th part
            let newPart = current
            // calculate size of i-th part
            var currentSize = splitSize
            if numRemainingParts > 0 {
                currentSize += 1
                numRemainingParts -= 1
            }

            // traverse to end of new part
            for _ in 0..<currentSize {
                prev = current
                current = current?.next
            }

            // cut off the rest of linked list
            if prev != nil {
                prev?.next = nil
            }

            ans[i] = newPart
        }

        return ans
    }
}