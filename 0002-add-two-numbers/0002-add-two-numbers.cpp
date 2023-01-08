/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c , temp = 0;
        ListNode dummy(0);
        ListNode* node = &dummy;
        
        while( l1 && l2){
            temp += l1->val + l2->val;
            ListNode* ptr = new ListNode( temp % 10);
            temp /= 10;
            node->next = ptr;
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while( l1){
            temp += l1->val;
            ListNode* ptr = new ListNode( temp % 10);
            temp /= 10;
            node->next = ptr;
            node = node->next;
            l1 = l1->next;
            // l2 = l2->next;
        }
        while( l2){
            temp += l2->val;
            ListNode* ptr = new ListNode( temp % 10);
            temp /= 10;
            node->next = ptr;
            node = node->next;
            // l1 = l1->next;
            l2 = l2->next;
        }
        if(temp) node->next = new ListNode(temp % 10);
        return dummy.next;
    }
};