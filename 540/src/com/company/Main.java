package com.company;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.print(singleNonDuplicate(new int[]{1,1,2,2, 3, 3, 4, 4, 8}));
    }
    public static int singleNonDuplicate(int[] nums) {
        int start = 0, end = nums.length - 1, mid;

        while (start < end) {
            mid = (start + end) >> 1;
//            mid is odd
            if (mid % 2 == 1) {
                if (nums[mid] == nums[mid - 1])
                    start = mid + 1;
                else if (mid < nums.length - 1 && nums[mid] == nums[mid + 1])
                    end = mid - 1;
                else return nums[mid];
            }
//            mid is even
            else {
                if (mid > 0 && nums[mid] == nums[mid - 1])
                    end = mid - 2;
                else if (mid < nums.length - 1 && nums[mid] == nums[mid + 1])
                    start = mid + 2;
                else return nums[mid];
            }
        }
        System.out.print(start + " " + end);
        return nums[start];
    }
}
