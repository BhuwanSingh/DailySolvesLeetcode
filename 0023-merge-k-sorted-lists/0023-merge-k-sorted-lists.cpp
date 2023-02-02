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
    struct Compare{
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }

    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode* , vector<ListNode* > , Compare > pq;
        ListNode* Dummy = new ListNode(0);
        ListNode* node = Dummy;
        for(auto i : lists){
            if( i != nullptr )
                pq.push(i);
        }
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            node->next = new ListNode(curr->val);
            node = node->next;
            if( curr->next ) pq.push( curr->next);
        }
        return Dummy->next;
    }
};