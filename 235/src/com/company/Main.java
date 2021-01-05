package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        String pathP = getPath(root, p);
        String pathQ = getPath(root, q);
        TreeNode ans = root;
        for (int i = 0; i < Math.min(pathP.length(), pathQ.length()); i++)
        {
            if (pathP.charAt(i) == pathQ.charAt(i))
            {
                if (pathP.charAt(i) == 'l')
                    ans=ans.left;
                else
                    ans=ans.right;
            }
            else break;
        }
        return ans;
    }

    public static String getPath(TreeNode root, TreeNode node) {
        StringBuffer stringBuffer = new StringBuffer();
        TreeNode temp = root;
        while(temp != null) {
            if (temp.val < node.val) {
                temp = temp.right;
                stringBuffer.append('r');
            }
            else if (temp.val > node.val) {
                temp = temp.left;
                stringBuffer.append('l');
            }
            else
                break;
        }
        return stringBuffer.toString();
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

