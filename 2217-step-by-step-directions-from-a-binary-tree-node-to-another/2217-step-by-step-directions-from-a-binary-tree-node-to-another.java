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
    TreeNode lca(TreeNode root , int startValue , int destValue){
        if(root == null || root.val == startValue || root.val == destValue) return root;
        TreeNode left =  lca(root.left , startValue , destValue);
        TreeNode right = lca(root.right , startValue , destValue);
        if(left != null && right != null) return root;
        if(left != null) return left;
        else return right;
    }
    boolean generatePath(TreeNode root , int value , StringBuilder path){
        if(root == null) return false;
        if(root.val == value) return true;
        path.append('L');
        if(generatePath(root.left , value , path)) return true;
        path.deleteCharAt(path.length() - 1);
        path.append('R');
        if(generatePath(root.right , value , path)) return true;
        path.deleteCharAt(path.length() - 1);
        return false;
    }
    public String getDirections(TreeNode root, int startValue, int destValue) {
        TreeNode findLCA = lca(root , startValue , destValue);
        StringBuilder pathToStart = new StringBuilder(); 
        StringBuilder pathToEnd = new StringBuilder();
        generatePath(findLCA , startValue , pathToStart);
        generatePath(findLCA , destValue , pathToEnd);
        for(int i=0; i<pathToStart.length() ; i++){
            pathToStart.setCharAt(i , 'U');
        }
        return pathToStart.toString() + pathToEnd.toString();
    }
}