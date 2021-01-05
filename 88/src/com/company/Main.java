package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int pos = nums1.length - 1, p1 = m - 1, p2 = n - 1;
        while(p1>=0 && p2>=0) {
            if (nums1[p1]<= nums2[p2])
                nums1[pos--] = nums2[p2--];
            else
                nums1[pos--] = nums1[p1--];
        }
    }
}
