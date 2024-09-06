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
    func modifiedList(_ nums: [Int], _ head: ListNode?) -> ListNode? {
        var dummy = ListNode(0, head)
        var cur: ListNode? = dummy
        let nums = Set(nums)

        while cur != nil {
            var next = cur?.next
            while nums.contains(next?.val ?? -1) { next = next?.next }
            cur?.next = next
            cur = next
        }

        return dummy.next
    }
}