package com.company;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println(threeSumClosest(new int[]{-1, 2,-1, -4}, 2));
    }

    public static  int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        
        int gap = Integer.MAX_VALUE;
        int ans=0;
        for(int i = 0; i < nums.length - 2; i++) {
            int left = i+1, right = nums.length-1;
            int sum = nums[i]+nums[left]+nums[right];
            if (sum == target)
                return sum;
            else if (sum>target) {
                if (sum - target < gap) {
                    ans = sum;
                    gap = sum-target;
                }
                continue;
            }
            else
            {
                if (target-sum < gap){
                    gap = target-sum;
                    ans=sum;
                }
            }
        }
        return ans;
    }

}
