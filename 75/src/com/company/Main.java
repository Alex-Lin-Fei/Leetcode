package com.company;

import com.sun.jmx.snmp.EnumRowStatus;

public class Main {

    public static void main(String[] args) {
        // write your code here
        sortColors(new int[]{2,1,0});
    }

    public static void sortColors(int[] nums) {
        int headPos = -1;
        int tailPos = nums.length;
        int curPos = 0;

        while(curPos < tailPos){
            if (nums[curPos] == 0)
            {
                swap(nums, ++headPos, curPos);
                if(curPos == headPos)
                    curPos++;
            }
            else if (nums[curPos] == 2) {
                swap(nums, --tailPos, curPos);
            }
            else curPos++;
        }


        for(int i : nums)
            System.out.print(i);
    }
    static void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a]= nums[b];
        nums[b] = temp;
    }
}
