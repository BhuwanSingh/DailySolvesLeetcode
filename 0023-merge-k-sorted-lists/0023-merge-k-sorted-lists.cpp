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
    struct compare{
        bool operator()( ListNode* l1 , ListNode* l2 ){
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode* , vector<ListNode* > , compare > pq;
        for( auto i : lists ){
            if( i ) pq.push( i );
        }
        ListNode* pre = new ListNode(0);
        ListNode* res = pre;
        while( !pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            pre->next = curr;
            pre = pre->next;
            if( curr->next ) pq.push( curr->next );
        }
        return res->next;
    }
};