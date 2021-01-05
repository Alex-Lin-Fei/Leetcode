package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] nums = new int[]{5,7,7,8,8,10};
        System.out.print(lower_bound(nums, 6));
        System.out.print(upper_bound(nums, 6));
    }

    public static int[] searchRange(int[] nums, int target) {
        if (nums.length == 0)
            return new int[]{-1, -1};
        int l = lower_bound(nums, target);
        int r = upper_bound(nums, target);
        if (l == nums.length || nums[l] != target)
            return new int[]{-1, -1};
        return new int[]{l, r - 1};
    }

    public static int lower_bound(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }

    public static int upper_bound(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }

}
