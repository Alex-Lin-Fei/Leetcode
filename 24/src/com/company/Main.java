package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        ListNode head = new ListNode(1);
        ListNode pre=head;
        ListNode n = head;

        int i = 2;
        while(i<6) {
            pre.next = new ListNode(i++);
            pre=pre.next;
        }
        n = swapPairs(head);
        while(n!=null) {
            System.out.print(n.val + " ");
            n=n.next;
        }

//        n = pre;
//        while(n!=null) {
//            System.out.print(n.val + " ");
//            n=n.next;
//        }

    }

    public static ListNode swapPairs(ListNode head) {
//        if(head==null)
//            return null;
        ListNode preHead = new ListNode(-1);
        ListNode tP = preHead;
        preHead.next=head;
        ListNode pre = head;

        while (pre!=null && pre.next != null) {
            ListNode nex = pre.next;

            pre.next = nex.next;
            nex.next = pre;
            tP.next = nex;
            tP = pre;
            pre = pre.next;
        }

        return preHead.next;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
