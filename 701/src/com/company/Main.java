package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root==null) {
            TreeNode cur = new TreeNode(val);
            return cur;
        }
        TreeNode curNode = root;
        TreeNode preNode = curNode;
        while(curNode!= null) {
            preNode = curNode;
            if (val < curNode.val)
                curNode=curNode.left;

            else curNode=curNode.right;
        }
        if (val < preNode.val)
            preNode.left = new TreeNode(val);
        else preNode.right = new TreeNode(val);
        return root;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
