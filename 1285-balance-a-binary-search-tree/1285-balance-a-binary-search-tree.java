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
    public TreeNode balanceBST(TreeNode root) {
        if(root == null) return null;
        List<Integer> ele = new ArrayList<>();
        inorderEle(root , ele);
        return constructBST(ele , 0 , ele.size() - 1);
    }
    void inorderEle(TreeNode node ,  List<Integer> ele){
        if(node == null) return;
        inorderEle(node.left , ele);
        ele.add(node.val);
        inorderEle(node.right , ele);
    }
    TreeNode constructBST(List<Integer> ele , int start , int end){
        if(start > end) return null;
        int mid = start + (end - start) / 2;
        TreeNode node = new TreeNode(ele.get(mid)); 
        node.left = constructBST(ele , start , mid-1);
        node.right = constructBST(ele , mid+1 , end);
        return node;
    }
}