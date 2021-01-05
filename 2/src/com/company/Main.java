package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here

    }
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode pre = l1;
        int carry = 0;
        while (l1 != null || l2 != null) {
            int sum = 0;
            if (l1 != null) {
                pre = l1;
                l1 = l1.next;
                sum = carry + pre.val;
            } else {
                pre.next = l2;
                pre = l2;
                sum = carry;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            } else {
                pre.next = l1;
            }
            pre.val = sum % 10;
            carry = sum / 10;
        }

        if (carry == 1)
            pre.next = new ListNode(1);
        return pre;
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