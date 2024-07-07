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
    func mergeNodes(_ head: ListNode?) -> ListNode? {
        var resultHead = ListNode()
        var DummyHead = resultHead
        var cVal = 0
        var curr = head
        
        while let currentNode = curr {
            // let currentNode = curr
            if currentNode.val == 0 && cVal != 0 {
                DummyHead.next = ListNode(cVal)
                DummyHead = DummyHead.next!
                cVal = 0
            } 
            if currentNode.val != 0 {
                cVal += currentNode.val
            }
            curr = currentNode.next
        }
        return resultHead.next
    }
}