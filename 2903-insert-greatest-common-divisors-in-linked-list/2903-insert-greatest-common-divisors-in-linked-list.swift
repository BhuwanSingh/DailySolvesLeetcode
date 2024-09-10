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
    func insertGreatestCommonDivisors(_ head: ListNode?) -> ListNode? {
        var prev = head
        var curr = head?.next
        while prev != nil && curr != nil {
            let node = ListNode(GCD(prev!.val, curr!.val))
            prev?.next = node
            node.next = curr
            prev = curr
            curr = curr?.next
        }
        return head
    }

    func GCD(_ x: Int, _ y: Int) -> Int {
        if x == 0 { return y }
        return GCD(y%x, x)
    }
}