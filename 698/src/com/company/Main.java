package com.company;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Main {

    public boolean canPartitionKSubsets(int[] nums, int k, int target, int curSum, int start, boolean[] used) {
        if (k == 0)
            return true;
        if (curSum == target) {
            return canPartitionKSubsets(nums, k-1, target, 0, nums.length - 1, used);
        }
        for (int i = start; i>= 0; i--) {
            if (!used[i] && curSum + nums[i] <= target) {
                used[i] = true;
                if (canPartitionKSubsets(nums, k, target, curSum + nums[i], i - 1, used))
                    return true;
                used[i] = false;
            }
        }
        return false;
    }


    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        Arrays.sort(nums);
        for (int i: nums) {
            sum += i;
        }
        if (sum % k > 0 || nums[nums.length - 1] > sum / k)
            return false;
        int target = sum / k;

        boolean[] used = new boolean[nums.length];
        return canPartitionKSubsets(nums, k, target, 0, nums.length - 1, used);
    }

    public static void main(String[] args) {
	// write your code here
    }
}
