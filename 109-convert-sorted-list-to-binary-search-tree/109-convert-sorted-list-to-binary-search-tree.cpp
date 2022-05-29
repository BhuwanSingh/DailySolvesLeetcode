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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        ListNode* fast = head , *slow = head , *last = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            last = slow;
            slow = slow->next;
        }
        TreeNode* res = new TreeNode(slow->val);
        // cout << res->val << " ";
        res->right = sortedListToBST(slow->next);
        if(last) last->next = nullptr;
        if(slow != head )res->left = sortedListToBST(head);
        else res->left = nullptr;
        return res;
    }
};