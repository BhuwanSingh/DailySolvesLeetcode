/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumEvenGrandparent(root *TreeNode) int {
    sum := 0
    var dfs func(node *TreeNode, pV, gpV int)
    dfs = func(node *TreeNode, pV, gpV int){
        if node == nil {
            return
        }
        if( gpV % 2 == 0 ) {
            sum += node.Val
        }
        dfs(node.Left , node.Val, pV)
        dfs(node.Right , node.Val, pV)
    }
    dfs(root.Left, root.Val, -1)
    dfs(root.Right, root.Val, -1)

    return sum
}