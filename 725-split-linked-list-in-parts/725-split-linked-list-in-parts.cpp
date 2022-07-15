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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode* > res;
        if(!head){
            while( res.size() < k){
                res.push_back({});
            }
            return res;
        }
        int n = 0;
        ListNode* node = head;
        while(node){
            node = node->next;
            n++;
        }
        int minTot = n / k , extra = n % k;
        // extra is the number of lists that have size greater than the others with more than 1.
        // min size of them all is at least minTot.
        ListNode* nhead = head;
        node = head;
        while(node){
            ListNode* temp = nullptr;
            node = nhead;
            int size = n / k;
            if(extra-- > 0) size++;
            // cout << node->val << " ";
            while( size-- > 1 && node){
                node = node->next;                
            }
            // cout << "\n";
            if(node) {
                temp = node->next;
                node->next = nullptr;
            }
            res.push_back(nhead);
            nhead = temp;
        }
        res.pop_back();
        while( res.size() < k){
            res.push_back({});
        }
        return res;
    }
};