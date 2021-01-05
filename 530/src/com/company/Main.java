package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public static int getMinimumDifference(TreeNode root) {
        if(root != null) {
            int minLeft = Integer.MAX_VALUE;
            int minRight = Integer.MAX_VALUE;

            if (root.left != null) {
                TreeNode temp = root.left;
                while(temp.right!=null)
                    temp=temp.right;
                minLeft = root.val - temp.val;
                minLeft = Math.min(minLeft, getMinimumDifference(root.left));
            }
            if (root.right != null) {
                TreeNode temp = root.right;
                while(temp.left!=null)
                    temp=temp.left;
                minRight = temp.val-root.val;
                minRight = Math.min(minRight,  getMinimumDifference(root.right));
            }
            return Math.min(minLeft, minRight);
        }

        return Integer.MAX_VALUE;
    }

}
//
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}
