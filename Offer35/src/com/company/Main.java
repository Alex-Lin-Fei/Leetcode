package com.company;

import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

public class Main {
    static HashMap<Node, Node> hashMap;
    public static void main(String[] args) {
	// write your code here
//
//        Vector<Integer> vector = new Vector<>();
//        Map<Integer, Integer> map;


    }

    public static Node copyRandomList(Node head) {
        if(head != null) {
            if(hashMap.containsKey(head)){
                return hashMap.get(head);
            }
            Node newHead = new Node(head.val);
            hashMap.put(head, newHead);
            newHead.next=copyRandomList(head.next);
            newHead.random = copyRandomList(head.random);
            return newHead;
        }
        return null;
    }
}


class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
