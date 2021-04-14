package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }
}


class Trie {
    private int SIZE = 26;
    private TrieNode root;

    private class TrieNode {
        private int num;  // 有多少个单词通过这个节点
        private TrieNode[] son; //所有儿子节点
        private boolean isEnd; //是否为叶节点
        private char val; //节点的值
        private boolean hasSon;

        TrieNode() {
            num = 1;
            son = new TrieNode[SIZE];
            isEnd = false;
            hasSon = false;
        }
    }

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode node = root;

        for (int i = 0; i < word.length(); i++) {
            int pos = word.charAt(i) - 'a';
            if (node.son[pos] == null) {
                node.hasSon = true;
                node.son[pos] = new TrieNode();
                node.son[pos].val = word.charAt(i);
            } else {
                node.son[pos].num++;
            }
            node = node.son[pos];
        }
        node.isEnd = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode node = root;

        for (int i = 0; i < word.length(); i++) {
            int pos = word.charAt(i) - 'a';
            if (node.son[pos] == null) {
                return false;
            } else {
                node = node.son[pos];
            }
        }
        return node.isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode node = root;

        for (int i = 0; i < prefix.length(); i++) {
            int pos = prefix.charAt(i) - 'a';
            if (node.son[pos] == null) {
                return false;
            } else {
                node = node.son[pos];
            }
        }
        return true;
    }
}

