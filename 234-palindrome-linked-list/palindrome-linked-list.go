/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }
    slow, fast := head, head
    for slow.Next != nil && fast.Next != nil && fast.Next.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }

    otherEnd := reverse(slow.Next)

    for head != nil && otherEnd != nil {
        if head.Val != otherEnd.Val {
            return false
        }
        head = head.Next
        otherEnd = otherEnd.Next
    }
    return true
}

func reverse(head *ListNode) *ListNode {
    var prev *ListNode
    curr := head
    for curr != nil {
        next := curr.Next
        curr.Next = prev

        prev = curr
        curr = next
    }

    return prev
}