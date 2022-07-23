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
    ListNode* partition(ListNode* head, int x) {
        vector<int> less , more;
        ListNode* node = head;
        while(node){
            if( node->val < x){
                less.push_back(node->val);
            } else {
                more.push_back(node->val);
            }
            node = node->next;
        }
        ListNode dummy(0);
        ListNode* temp = &dummy;
        for(int i : less){
            temp->next = new ListNode(i);
            temp = temp->next;
        }
        for(int i : more){
            temp->next = new ListNode(i);
            temp = temp->next;
        }
        return dummy.next;
    }
};