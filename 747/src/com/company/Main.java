package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println(dominantIndex(new int[]{1,2,3,4}));
    }

    public static int dominantIndex(int[] nums) {
        int maxNum1, maxNum2;
        int idx=-1;
        maxNum1 = maxNum2 = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++) {
            if (nums[i] > maxNum1) {
                maxNum2 = maxNum1;
                maxNum1 = nums[i];
                idx = i;
            } else if (nums[i] > maxNum2)
                maxNum2 = nums[i];
        }
        if (maxNum1 >= 2 * maxNum2)
            return idx;
        return -1;
    }
}
