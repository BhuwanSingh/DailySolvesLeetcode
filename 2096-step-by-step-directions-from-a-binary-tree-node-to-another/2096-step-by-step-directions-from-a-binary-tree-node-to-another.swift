/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func find(_ node: TreeNode?, _ val: Int, _ path: inout String) -> Bool {
        guard let node = node else { return false }
        if node.val == val { return true }

        if let left = node.left, find(left, val, &path) {
            path.append("L")
        } else if let right = node.right, find(right, val, &path) {
            path.append("R")
        }
        return !path.isEmpty
    }

    func getDirections(_ root: TreeNode?, _ startValue: Int, _ destValue: Int) -> String {
        var sPath = ""
        var dPath = ""

        _ = find(root, startValue, &sPath)
        _ = find(root, destValue, &dPath)

        while !sPath.isEmpty && !dPath.isEmpty && sPath.last == dPath.last {
            sPath.removeLast()
            dPath.removeLast()
        }

        return String(repeating: "U", count: sPath.count) + String(dPath.reversed())
    }
}