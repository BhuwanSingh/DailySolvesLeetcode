/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> answer = new ArrayList<>();
        combos(answer , root);
        return answer;
    }
    
    public void combos(List<Integer> answer , TreeNode root ){
        if(root == null) return;
        
        combos(answer , root.left);
        answer.add(root.val);
        combos(answer , root.right);
    }    
}