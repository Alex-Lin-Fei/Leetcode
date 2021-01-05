package com.company;

public class Main {

    public TreeNode sortedArrayToBST(int[] nums) {
        return sortedArrayToBST(nums, 0, nums.length - 1);
    }

    public TreeNode sortedArrayToBST(int[] nums, int l, int r) {
        if (l == r)
            return new TreeNode(nums[r]);
        else if (l > r)
            return null;
        else {
            int mid = (l + r) >> 1;
            TreeNode root = new TreeNode(nums[mid]);
            root.left = sortedArrayToBST(nums, l, mid - 1);
            root.right = sortedArrayToBST(nums, mid + 1, r);
            return root;
        }
    }

    public static void main(String[] args) {
	// write your code here
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}
