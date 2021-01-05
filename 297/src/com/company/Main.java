package com.company;

import sun.reflect.generics.tree.Tree;

import javax.sound.sampled.Line;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Main {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public String serialize(TreeNode root, String res) {
        if (root == null)
            res += "None,";
        else {
            res += String.valueOf(root.val) + ",";
            res = serialize(root.left, res);
            res = serialize(root.right, res);
        }
        return res;
    }

    public String serialize(TreeNode root) {
        String res = "";
        return serialize(root, res);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(LinkedList<String> list) {
        if (list.get(0).equals("None")) {
            list.remove(0);
            return null;
        }
        else {
            TreeNode root = new TreeNode(Integer.parseInt(list.get(0)));
            list.remove(0);
            root.left = deserialize(list);
            root.right = deserialize(list);
            return root;
        }
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] strings = data.split(",");
        LinkedList<String> arrayList = new LinkedList<>(Arrays.asList(strings));
        return deserialize(arrayList);
    }

    public static void main(String[] args) {
	// write your code here
    }
}
