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
    func balanceBST(_ root: TreeNode?) -> TreeNode? {
        var sortedValues: [Int] = []
        inOrderTraversal(root , &sortedValues);
        return constructBST(sortedValues, 0, sortedValues.count - 1)
    }
    private func inOrderTraversal(_ node: TreeNode? , _ result: inout[Int]){
        guard let node = node else { return }
        inOrderTraversal(node.left , &result)
        result.append(node.val)
        inOrderTraversal(node.right , &result)
    }

    private func constructBST(_ values: [Int] , _ start: Int , _ end: Int) -> TreeNode? {
        if start > end {
            return nil
        }

        let mid = start + (end - start) / 2
        let node = TreeNode(values[mid])
        node.left = constructBST(values , start , mid - 1)
        node.right = constructBST(values , mid + 1 , end)
        return node
    }

}