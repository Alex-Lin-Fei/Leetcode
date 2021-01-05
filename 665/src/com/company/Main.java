package com.company;

import javax.swing.*;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println(checkPossibility(new int[]{3,4,2,3}));
    }

    public static boolean checkPossibility(int[] nums) {
//        boolean hasChanged = false;
//        for (int i = 0; i < nums.length; i++) {
//            if (i < nums.length - 1 && nums[i] > nums[i + 1]) {
//                if (hasChanged)
//                    return false;
//                if (i > 0 && nums[i-1] > nums[i+1]) {
//                    if (i + 2 < nums.length && (nums[i + 2] < nums[i]))
//                        return false;
//                }
//                hasChanged = true;
//            }
//        }
//        return true;
        boolean hasChanged = false;
        for(int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i-1]) {
                if(hasChanged == false) {
                    if(i+1<nums.length && nums[i+1]>=nums[i-1])
                        nums[i] = nums[i - 1];

                    else
                        nums[i-1] = nums[i];

                    hasChanged = true;
                }
                else
                    return false;
            }
        }
        return true;
    }
}
