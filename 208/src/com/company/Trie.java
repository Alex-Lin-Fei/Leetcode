package com.company;


/*
public class Trie {
    private int SIZE = 26;
    private TrieNode root;

    Trie() {
        root = new TrieNode();
    }

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

//    插入一个单词
    public void insert(String str) {
        if (str == null || str.length() == 0) {
            return;
        }
        TrieNode node = root;

        for (int i = 0; i < str.length(); i++) {
            int pos = str.charAt(i) - 'a';
            if (node.son[pos] == null) {
                node.hasSon = true;
                node.son[pos] = new TrieNode();
                node.son[pos].val = str.charAt(i);
            } else {
                node.son[pos].num++;
            }
            node = node.son[pos];
        }
        node.isEnd = true;
    }

//    计算单词前缀的数量
    public int countPrefix(String prefix) {
        if (prefix == null || prefix.length() == 0) {
            return -1;
        }
        TrieNode node = root;
        for (int i = 0; i < prefix.length(); i++) {
            int pos = prefix.charAt(i) - 'a';
            if (node.son[pos] == null) {
                return 0;
            } else {
                node = node.son[pos];
            }
        }
        return node.num;
    }

//    打印指定前缀的单词
//    遍历经过此节点的单词
//    在字典树中查找一个完全匹配的单词

    public boolean has(String str) {
        if (str == null || str.length() == 0) {
            return false;
        }
        TrieNode node = root;

        for (int i = 0; i < str.length(); i++) {
            int pos = str.charAt(i) - 'a';
            if (node.son[pos] == null) {
                return false;
            } else {
                node = node.son[pos];
            }
        }
        return node.isEnd;
    }

//
}
*/
