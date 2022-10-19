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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        int len = 0;
        while( node ){
            len++;
            node = node->next;
        }
        
        int front = len - n;
        
        if( front == 0 )
            return head->next;
        else{
            node = head;
            while(--front){
                node = node->next;
            }
            node->next = node->next->next;
            return head;
        }
    }
};