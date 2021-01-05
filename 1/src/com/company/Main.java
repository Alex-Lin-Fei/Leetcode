package com.company;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] nums = {11, 7, 2, 15};
        twoSum(nums, 9);
    }

    public static int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        ArrayList<Integer> temp = new ArrayList<>();
        for(int i: nums)
            temp.add(i);
        Arrays.sort(nums);

        for (int s = 0; s < nums.length; s++) {
            int t = binarySearchIII(nums, s + 1, nums.length, target - nums[s]);
            if (t != -1) {
                ans[0] = temp.indexOf(nums[s]);
                ans[1] = temp.indexOf(nums[t]);
                break;
            }
        }
        Arrays.sort(ans);
        return ans;
    }

    public static int binarySearchI(int[] nums, int s, int t, int target) {
        while(s <= t) {
            int mid =(s+t)>>1;
            if (nums[mid] < target)
                s = mid+1;
            else if (nums[mid] > target)
                t = mid-1;
            else
                return mid;
        }
        return -1;
    }

    public static int binarySearchII(int[] nums, int s, int t, int target) {
        while(s < t - 1) {
            int mid =(s+t)>>1;
            if (nums[mid] < target)
                s = mid;
            else if (nums[mid] > target)
                t = mid;
            else
                return mid;
        }
        return -1;
    }

    public static int binarySearchIII(int[] nums, int s, int t, int target) {
        while(s < t) {
            int mid =(s+t)>>1;
            if (nums[mid] < target)
                s = mid+1;
            else if (nums[mid] > target)
                t = mid;
            else
                return mid;
        }
        return -1;
    }
}
