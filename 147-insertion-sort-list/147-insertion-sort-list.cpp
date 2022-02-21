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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v;
        ListNode* node = head;
        while(node){
            v.push_back(node->val);
            node = node->next;
        }
        sort(v.begin() , v.end());
        node = head;
        int i = 0;
        while(node){
            node->val = v[i];
            node = node->next;
            i++;
        }
        return head;
    }
};