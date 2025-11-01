/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func modifiedList(nums []int, head *ListNode) *ListNode {
    hm := map[int]bool{}
    for _, val := range nums {
        hm[val] = true
    }

    dummyHead := &ListNode{}
    dummyHead.Next = head

    curr := dummyHead

    for curr.Next != nil {
        if _, ok := hm[curr.Next.Val]; ok {
            curr.Next = curr.Next.Next
        } else {
            curr = curr.Next
        }
    }

    return dummyHead.Next
}