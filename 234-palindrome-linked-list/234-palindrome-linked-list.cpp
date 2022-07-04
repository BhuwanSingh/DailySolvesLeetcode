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
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        int n = 0;
        while(node){
            n++;
            node = node->next;
        }
        int temp = (n - 1) / 2;
        ListNode* tnode = head;
        while(temp > 0){
            tnode = tnode->next;
            temp--;
        }
        ListNode* sh = tnode->next;
        tnode->next = nullptr;
        ListNode* second = reverse(sh);
        
        while(head != nullptr && second != nullptr){
            if(head->val != second->val) return false;
            head = head->next;
            second = second = second->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        
        return head;
    }
};