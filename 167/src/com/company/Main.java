package com.company;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }
    public static int[] twoSum(int[] numbers, int target) {
        int l = 0, r = numbers.length-1;
        while(l<r){
            int sum = numbers[l]+numbers[r];
            if(sum == target)
                break;
            else if (sum<target)
                l++;
            else
                r--;
        }
        return new int[]{l+1, r+1};
    }
}
