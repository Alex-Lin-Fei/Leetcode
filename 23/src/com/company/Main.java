package com.company;


import java.util.PriorityQueue;

public class Main {

    //顺序归并
    /*
    public static ListNode mergeKLists(ListNode[] lists) {
        ListNode res = null;
        for (int i = 0; i < lists.length; i++) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
*/
    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null || list2 == null)
            return list1 == null ? list2 : list1;
        ListNode head = new ListNode(-1);
        ListNode temp = head;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                temp.next = list1;
                list1 = list1.next;
            } else {
                temp.next = list2;
                list2 = list2.next;
            }
            temp = temp.next;
        }
        temp.next = (list1 != null) ? list1 : list2;

        return head.next;
    }

    //    归并
/*
    public static ListNode merge(ListNode[] lists, int l, int r) {
        if (l == r)
            return lists[l];
        if (l > r)
            return null;
        int mid = (l + r)>>1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
    }

    public static ListNode mergeKLists(ListNode[] lists) {
        return merge(lists, 0, lists.length - 1);
    }
    */

    //    优先队列
    public static ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Node> queue = null;
        for (ListNode list : lists) {
            assert false;
            queue.offer(new Node(list.val, list));
        }
        ListNode head = new ListNode(-1), tail = head;

        while (!queue.isEmpty()) {
            Node temp = queue.peek();
            queue.poll();
            tail.next = temp.listNode;
            if (temp.listNode.next != null)
                queue.offer(new Node(temp.listNode.next.val, temp.listNode.next));
        }
        return head.next;
    }

    public static void main(String[] args) {
        // write your code here
    }
}

class Node {
    int val;
    ListNode listNode;

    Node(int x, ListNode node) {
        val = x;
        listNode = node;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}