package com.company;

import com.sun.jmx.remote.internal.ArrayQueue;
import sun.reflect.generics.tree.Tree;

import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public static boolean isEvenOddTree(TreeNode root) {
        int level = 0;
        int pre;

        LinkedList<TreeNode> que = new LinkedList<>();

        que.add(root);

        while(!que.isEmpty()) {
            int size = que.size();

            pre = -1;
            while(size-- > 0) {
                TreeNode node = que.getFirst();
                que.removeFirst();

                if (node.left != null)
                    que.add(node.left);
                if (node.right != null)
                    que.add(node.right);

                if (node.val % 2 != (level + 1) % 2)
                    return false;
                
                if (pre != -1) {
                    if (level == 0 && pre >= node.val || level == 1 && pre <= node.val)
                        return false;
                }
                pre = node.val;
                level = (level + 1) % 2;
            }
        }
        return true;
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