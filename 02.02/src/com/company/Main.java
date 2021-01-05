package com.company;


public class Main {

    public int kthToLast(ListNode head, int k) {
        ListNode pre = head;
        ListNode pro = head;
        int t = k;
        while (t-- > 0) {
            pre = pre.next;
        }
        while (pre != null) {
            pre = pre.next;
            pro = pro.next;
        }
        assert pro != null;
        return pro.val;
    }

    public static void main(String[] args) {
	// write your code here
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}