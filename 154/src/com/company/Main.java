package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println(findMin(new int[]{4,4,0,4,4,4}));
    }
    public static int findMin(int[] nums) {
//        判断是否反转
        boolean hasRotated=false;
        for(int i = 1; i < nums.length; i++)
            if(nums[i]<nums[i-1])
            {
                hasRotated=true;
                break;
            }
        if(hasRotated==false)
            return nums[0];

        int start = 0, end = nums.length-1, mid;
        while (start <= end) {
            mid = (start + end) >> 1;
            if (nums[mid] == nums[start]) {
                if (nums[start + 1] >= nums[mid])
                    start++;
                else
                    return nums[start+1];
            }
            else if (nums[mid] > nums[start])
                start = mid;
            else
                end = mid;
        }
        return nums[end];
    }
}
