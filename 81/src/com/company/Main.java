package com.company;

import jdk.nashorn.internal.runtime.UserAccessorProperty;

public class Main {

    public static void main(String[] args) {
        // write your code here
        System.out.print(search(new int[]{2,5,6,0,0,1,2}, 3));
    }

    public static boolean search(int[] nums, int target) {
        int start = 0, end = nums.length-1,mid;
        while(start <= end) {
            mid = (start + end) >> 1;
            if(nums[mid] == target)
                return true;
            else if (nums[mid] == nums[start])
                start++;
//            右边有序
            else if (nums[mid] < nums[start]) {
                if(nums[mid] <= target && target <= nums[end])
                    start = mid;
                else
                    end = mid-1;
            }
//            左边有序
            else {
                if (nums[mid] >= target && nums[start] <= target)
                    end = mid;
                else
                    start = mid+1;
            }
            /*
            else if (nums[mid] <= nums[end]){
            if (target > nums[mid] && target <= nums[end]){
            start=mid+1;
            }
            else

            }
            else{
            if(t > nums[start] && t < nums[mid]

            else

            }

             */
        }
        return false;
    }
}
